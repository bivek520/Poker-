//
// chat_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include "asio.hpp"
#include "chat_message.hpp"
#include "json.hpp"
#include <string>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace std;
using asio::ip::tcp;

//----------------------------------------------------------------------

typedef std::deque<chat_message> chat_message_queue;

//----------------------------------------------------------------------

class player
{
public:
    player()
    {
        boost::uuids::basic_random_generator<boost::mt19937> g;
        id=g();
        string playerID;
        stringstream ss;
        ss<<id;
        playerID=ss.str();
        cout << "uuid is " << playerID << endl;
    }
    virtual ~player() {}
    virtual void deliver(const chat_message& msg) = 0;
    boost::uuids::uuid id;                                  //holds user id of each player
    int turn;                                               //hold turn # of eacch player
    bool ready=false;
	
	
	
};

typedef std::shared_ptr<player> player_ptr;

//----------------------------------------------------------------------
int player_turn=1;
class poker_table
{
public:
    void join(player_ptr participant)
    {
        cout<<"New Player has joined the room"<<endl;
        participant->turn=player_turn;                          //gives turn # to each player
        player_turn++;
        participants_.insert(participant);
        for (auto msg: recent_msgs_)                    //CSE3310 (server)  previous chat messages are sent to a client
        {
            participant->deliver(msg);
            //cout<<"poker_table join() for loop"<<endl;
        }
        //cout<<"poker_table join() done printing"<<endl;
    }
    void leave(player_ptr participant)
    {
        //cout<<"poker_table leave()"<<endl;
        participants_.erase(participant);
    }
    void deliver(const chat_message& msg)
    {      //cout<<"poker_table deliver()"<<endl;
        recent_msgs_.push_back(msg);
        while (recent_msgs_.size() > max_recent_msgs)
            recent_msgs_.pop_front();
        for (auto participant: participants_)       //CSE3310 (server)  messages are sent to all connected clients
        {
            participant->deliver(msg);
            //cout<<"sending to all the clients"<<endl;
        }
    }
    void deliver_to(const chat_message& msg,int deli_to)
    {      //cout<<"poker_table deliver()"<<endl;
        recent_msgs_.push_back(msg);
        while (recent_msgs_.size() > max_recent_msgs)
            recent_msgs_.pop_front();
        for (auto participant: participants_)       //CSE3310 (server)  messages are sent to all connected clients
        {
            if(participant->turn==deli_to)
                participant->deliver(msg);
            //cout<<"sending to individual clients"<<endl;
        }
    }

    void set_ready(bool status,int deli_to)
    {
        for (auto participant: participants_)       //CSE3310 (server)  messages are sent to all connected clients
        {
            if(participant->turn==deli_to)
            {
                participant->ready=status;
                cout<<"This is the set_ready function\nplayer: "<<deli_to<<" status: "<<status<<endl;
            }
        }
    }
    bool allReady()                                 //checks if all the player in the servers are ready for the game
    {
        bool all_ready = true;
        for (auto participant: participants_)       //set all_ready to false if all players aren't ready
        {
            if(participant->ready==false)
            {
                all_ready=false;
            }
        }
        cout<<"All ready is accessed and this is the result:"<<all_ready<<endl;
        return all_ready;
    }
    
private:
    std::set<player_ptr> participants_;
    enum { max_recent_msgs = 100 };           //CSE3310 (server) maximum number of messages are stored
    chat_message_queue recent_msgs_;
};

//----------------------------------------------------------------------

class poker_player
: public player,
public std::enable_shared_from_this<poker_player>
{
public:
    poker_player(tcp::socket socket, poker_table& room)
    : socket_(std::move(socket)),
    room_(room)
    {
        //cout<<"poker_player constructor"<<endl;
    }
    void start()
    {
        //cout<<"poker_player start()"<<endl;
        
        room_.join(shared_from_this());
        do_read_header();
    }
    
    void deliver(const chat_message& msg)
    {
        //cout<<"poker_player deliver()"<<endl;
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress)
        {
            do_write();
        }
    }
    
private:
	void gameUnlock()
	{
	
	
	
	}
    void do_read_header()
    {
      auto self(shared_from_this());
      asio::async_read(socket_,
          asio::buffer(read_msg_.data(), chat_message::header_length),
          [this, self](std::error_code ec, std::size_t /*length*/)
          {
            if (!ec && read_msg_.decode_header())
            {
              do_read_body();
            }
            else
            {
              room_.leave(shared_from_this());
            }
          });
    }

    void do_read_body()
    {
      auto self(shared_from_this());
      asio::async_read(socket_,
          asio::buffer(read_msg_.body(), read_msg_.body_length()),
          [this, self](std::error_code ec, std::size_t /*length*/)
          {
            if (!ec)
            {
                
                nlohmann::json to_dealer = nlohmann::json::parse(std::string(read_msg_.body()));
                nlohmann::json to_player;  // represents the entire game state.  sent to all players
		/*
                to_player["turn"] = "3f96b414-9ac9-40b5-8007-90d0e771f0d0";   // UUID of the current player.
                to_player["chat"] = to_dealer["chat"];
                to_player["dealer_comment"] = "fred has raised and received 2 new cards";
                to_player["recommended_play"] = "you should fold";
                to_player["hand"] = {
                    {{"bet",1},{"current_bet",10}, {"uuid","3f96b414-9ac9-40b5-8007-90d0e771f0d0"} , {"name","Bud"} ,{"cards",{"acespades","10hearts","9clubs","2diamonds","kinghearts"}}},
                    {{"bet",2},{"current_bet",1}, {"uuid","3f96b414-9ac9-40b5-8007-20d0e771f0d0"} , {"name","Donald"} ,{"cards",{"acehearts","10spades","9clubs","2clubs","jackhearts"}}},
                    {{"bet",5},{"current_bet",5}, {"uuid","3f96b414-9ac9-40b5-8007-30d0e771f0d0"} , {"name","Ann"} ,{"cards",{"aceclubs","10diamonds","9clubs","2hearts","queenhearts"}}},
                    {{"bet",10},{"current_bet",0}, {"uuid","3f96b414-9ac9-40b5-8007-40d0e771f0d0"} , {"name","Melania"} ,{"cards",{"acediamonds","10clubs","9clubs","2spades","kinghearts"}}}
                };
                
                std::string t = to_player.dump();
                chat_message sending;
                if (t.size() < chat_message::max_body_length)
                {
                    std::cout << "the size string being sent is " << t.size() << std::endl;
                    memcpy( sending.body(), t.c_str(), t.size() );
                    sending.body_length(t.size());
                    sending.encode_header();
                    room_.deliver(sending);
                }
                 */
		
                std::string t = to_player.dump();
                chat_message sending;
                if (t.size() < chat_message::max_body_length)
                {
                    std::cout << "the size string being sent is " << t.size() << std::endl;
                    memcpy( sending.body(), t.c_str(), t.size() );
                    sending.body_length(t.size());
                    sending.encode_header();
                    room_.deliver(sending);
                }
		if(room_.allReady())
		{
			std::cout << "the size string being sent is " << t.size() << std::endl;
                    memcpy( sending.body(), t.c_str(), t.size() );
                    sending.body_length(t.size());
                    sending.encode_header();
                    room_.deliver(sending);
		}
            }
            else
            {
                room_.leave(shared_from_this());
            }
        });
    }
    
    void do_write()
    {
      auto self(shared_from_this());
      asio::async_write(socket_,
          asio::buffer(write_msgs_.front().data(),
            write_msgs_.front().length()),
          [this, self](std::error_code ec, std::size_t /*length*/)
          {
            if (!ec)
            {
              write_msgs_.pop_front();
              if (!write_msgs_.empty())
              {
                do_write();
              }
            }
            else
            {
              room_.leave(shared_from_this());
            }
          });
    }
    tcp::socket socket_;
    poker_table& room_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};
//----------------------------------------------------------------------
class poker_game
{
public:
    poker_game(asio::io_context& io_context,
               const tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint)
    {
        //cout<<"Poker game started"<<endl;
        do_accept();
    }
private:
    void do_accept()
    {
        acceptor_.async_accept(
                               [this](std::error_code ec, tcp::socket socket)
                               {
            if (!ec)
            {
                std::make_shared<poker_player>(std::move(socket), room_)->start();
            }
            do_accept();
        });
    }
    tcp::acceptor acceptor_;
    poker_table room_;
};

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Usage: dealer <port> [<port> ...]\n";
            return 1;
        }
        
        asio::io_context io_context;
        
        std::list<poker_game> servers;
        for (int i = 1; i < argc; ++i)
        {
            tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
            servers.emplace_back(io_context, endpoint);
        }
        
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    
    return 0;
}
