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

using namespace std;
using asio::ip::tcp;

//----------------------------------------------------------------------

typedef std::deque<chat_message> chat_message_queue;

//----------------------------------------------------------------------

class chat_participant
{
public:
  virtual ~chat_participant() {}
  virtual void deliver(const chat_message& msg) = 0;
};

typedef std::shared_ptr<chat_participant> chat_participant_ptr;

//----------------------------------------------------------------------

class chat_room
{
public:
  void join(chat_participant_ptr participant)
  {
      cout<<"New Player has joined the room"<<endl;

    participants_.insert(participant);
    for (auto msg: recent_msgs_)                    //CSE3310 (server)  previous chat messages are sent to a client
    {
      participant->deliver(msg);
        //cout<<"chat_room join() for loop"<<endl;
    }
    //cout<<"chat_room join() done printing"<<endl;
  }

  void leave(chat_participant_ptr participant)
  {
      //cout<<"chat_room leave()"<<endl;

    participants_.erase(participant);
  }

  void deliver(const chat_message& msg)
  {      //cout<<"chat_room deliver()"<<endl;

    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs)
      recent_msgs_.pop_front();

    for (auto participant: participants_)       //CSE3310 (server)  messages are sent to all connected clients
    {
      participant->deliver(msg);
        //cout<<"sending to all the clients"<<endl;
    }
  }

private:
  std::set<chat_participant_ptr> participants_;
  enum { max_recent_msgs = 100 };           //CSE3310 (server) maximum number of messages are stored
  chat_message_queue recent_msgs_;
};

//----------------------------------------------------------------------

class chat_session
  : public chat_participant,
    public std::enable_shared_from_this<chat_session>
{
public:
  chat_session(tcp::socket socket, chat_room& room)
    : socket_(std::move(socket)),
      room_(room)
  {
      //cout<<"chat_session constructor"<<endl;
  }

  void start()
  {
      //cout<<"chat_session start()"<<endl;

    room_.join(shared_from_this());
    do_read_header();
  }

  void deliver(const chat_message& msg)
  {
      //cout<<"chat_session deliver()"<<endl;

    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
      do_write();

    }
  }

private:
  void do_read_header()
  {
      //cout<<"chat_session do_read_header()"<<endl;

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
      //cout<<"chat_session do_read_body()"<<endl;

    auto self(shared_from_this());
    asio::async_read(socket_,
        asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this, self](std::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            room_.deliver(read_msg_);
            do_read_header();
          }
          else
          {
            room_.leave(shared_from_this());
          }
        });
  }

  void do_write()
  {
      //cout<<"chat_session do_write()"<<endl;

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
  chat_room& room_;
  chat_message read_msg_;
  chat_message_queue write_msgs_;
};

//----------------------------------------------------------------------

class chat_server
{
public:
  chat_server(asio::io_context& io_context,
      const tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint)
  {
      //cout<<"chat_server constructor"<<endl;

    do_accept();
  }

private:
  void do_accept()
  {
      //cout<<"chat_server do_accept() start"<<endl;

    acceptor_.async_accept(
        [this](std::error_code ec, tcp::socket socket)
        {
        //cout<<"chat_server do_accept() async_accept()"<<endl;

          if (!ec)
          {
              //cout<<"chat_server do_accept() async_accept() if brace"<<endl;

            std::make_shared<chat_session>(std::move(socket), room_)->start();
          }

          do_accept();
        });
  }

  tcp::acceptor acceptor_;
  chat_room room_;
};

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
  try
  {
      //cout<<"main->before the for loop"<<endl;

    if (argc < 2)
    {
      std::cerr << "Usage: chat_server <port> [<port> ...]\n";
      return 1;
    }

    asio::io_context io_context;

    std::list<chat_server> servers;
    for (int i = 1; i < argc; ++i)
    {
        //cout<<"main->for loop"<<endl;
      tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
      servers.emplace_back(io_context, endpoint);
    }
      //cout<<"main->after the for loop"<<endl;

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
