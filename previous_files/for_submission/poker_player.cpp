#include "chat_message.hpp"
#include "poker_player.hpp"
#include "dealer.h"
#include "json.hpp"
#include "poker_table.h"
#include "global_var.hpp"

int turn=0;
int start;
std::string action;
int pot = 0;
int bid = 0;
int raise_by = 0;
int bidChange = 0;
int totalPlayers;
bool skip1=false;
bool skip2=false;
bool skip3=false;
bool skip4=false;
bool skip5=false;
bool lastPhase = false;
int winner;
bool gameOver = false;

using asio::ip::tcp;



poker_player::poker_player(tcp::socket socket, poker_table& room)
: socket_(std::move(socket)),
room_(room)
{
    //cout<<"poker_player constructor"<<endl;
    
}

void poker_player::start()
{
    //cout<<"poker_player start()"<<endl;
    
    room_.join(shared_from_this());
    do_read_header();
}

void poker_player::deliver(const chat_message& msg)
{
    //cout<<"poker_player deliver()"<<endl;
    
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
        do_write();
        
    }
}


void poker_player::do_read_header()
{
    auto self(shared_from_this());
    asio::async_read(socket_,
                     asio::buffer(read_msg_.data(), chat_message::header_length),
                     [this, self](std::error_code ec, std::size_t /*length*/)
                     {
        if (!ec && read_msg_.decode_header())
        {
            // clear out the old buffer from the last read
            // a '\0' is a good value to make sure a string
            // is terminated
            for (unsigned int i=0;i<chat_message::max_body_length;i++)
            {
                read_msg_.body() [i] = '\0';
            }
            do_read_body();
        }
        else
        {
            room_.leave(shared_from_this());
        }
    });
}

void poker_player::do_read_body()
{
    auto self(shared_from_this());
    asio::async_read(socket_,
                     asio::buffer(read_msg_.body(), read_msg_.body_length()),
                     [this, self](std::error_code ec, std::size_t /*length*/)
                     {
        if (!ec)
        {
            /*
             json Davis example stuff was here
             */
            if (turn==0)
            {
                nlohmann::json to_dealer = nlohmann::json::parse(std::string(read_msg_.body()));
                nlohmann::json from_player = nlohmann::json::parse(std::string(read_msg_.body()));
                room_.set_ready(to_dealer["ready"],shared_from_this()->playerNo);
                totalPlayers=room_.getSize();
                //send out ready status to all players
                if (shared_from_this()->ready==true)
                {
                    nlohmann::json to_player;
                    to_player["participant"]=shared_from_this()->playerNo;
                    to_player["ready"]=true;
                    to_player["pot"]=pot;
                    to_player["balance"]=shared_from_this()->balance;
                    to_player["size"] = totalPlayers;
                    std::string t=to_player.dump();
                    chat_message sending;
                    if (t.size() < chat_message::max_body_length)
                    {
                        memcpy( sending.body(), t.c_str(), t.size() );
                        sending.body_length(t.size());
                        sending.encode_header();
                        room_.deliver(sending);
                    }
                }
                
                if (room_.allReady()==false)
                {
                    std::cout<<"cant start game"<<std::endl;
                    nlohmann::json to_player1;
                    to_player1["start"]=false;
                    pot=(playerNumber) * 5;
                    to_player1["pot"]=pot;
                    to_player1["balance"]=shared_from_this()->balance;
                    std::string t=to_player1.dump();
                    chat_message sending;
                    if (t.size() < chat_message::max_body_length)
                    {
                        memcpy( sending.body(), t.c_str(), t.size() );
                        sending.body_length(t.size());
                        sending.encode_header();
                        room_.deliver(sending);
                    }
                }
                else
                {
                    bidChange = playerNumber;
                    turn++;
                    nlohmann::json to_player2;
                    to_player2["start"]=true;
                    to_player2["participant"]=shared_from_this()->playerNo;
                    to_player2["turn"]=turn;
                    to_player2["bid"]=bid;
                    to_player2["pot"]=pot;
                    to_player2["balance"]=shared_from_this()->balance;
                    std::string t=to_player2.dump();
                    chat_message sending;
                    if (t.size() < chat_message::max_body_length)
                    {
                        memcpy( sending.body(), t.c_str(), t.size() );
                        sending.body_length(t.size());
                        sending.encode_header();
                        room_.deliver(sending);
                    }
                }
                
            }
            
            //if turn not 0
            else
            {
                turn++;
                if (turn== (room_.getSize()+1))
                    turn=1;
                if (skip1==true && turn==1)
                    turn++;
                if (skip2==true && turn==2)
                    turn++;
                if (skip3==true && turn==3)
                    turn++;
                if (skip4==true && turn==4)
                    turn++;
                if (skip5==true && turn==5)
                    turn++;
                
                if (turn==(room_.getSize()+1))turn=1;
                //read json from player getting their action
                nlohmann::json from_player = nlohmann::json::parse(std::string(read_msg_.body()));
                
                if (from_player["action"].empty()==false)
                {
                    shared_from_this()->actionTaken = from_player["action"];
                    action = from_player["action"];
                    if(action == "bet")
                    {
                        bidChange = playerNumber;
                        bid = from_player["bid"];
                        pot = pot + bid;
                        std::cout << "pot = " <<pot<<std::endl;
                        shared_from_this()->balance=from_player["balance"];
                    }
                    if(action == "raised")
                    {
                        bidChange = playerNumber;
                        raise_by = from_player["raise_by"];
                        pot = pot + raise_by + bid;
                        std::cout << "pot = " <<pot<<std::endl;
                        int temp = from_player["balance"];
                        shared_from_this()->balance=temp-(raise_by+bid);
                        bid = bid + raise_by;
                    }
                    if(action == "called")
                    {
                        int temp = from_player["balance"];
                        shared_from_this()->balance=temp-bid;
                        pot = pot + bid;
                        std::cout << "pot = " <<pot<<std::endl;
                    }
                    if(action == "allin")
                    {
                        bidChange = playerNumber;
                        
                        if(from_player["raise_by"].empty() == false)
                        {
                            raise_by = from_player["raise_by"];
                            pot = pot + raise_by + bid;
                            std::cout << "pot = " <<pot<<std::endl;
                            int temp = from_player["balance"];
                            shared_from_this()->balance=temp-raise_by-bid;
                            bid = bid + raise_by;
                        }
                        if(from_player["bid"].empty() == false)
                        {
                            bid = from_player["bid"];
                            pot = pot + bid;
                            std::cout << "pot = " <<pot<<std::endl;
                            shared_from_this()->balance=from_player["balance"];
                        }
                    }
                    if(action == "folded")
                    {
                        if (shared_from_this()->playerNo==1)
                            skip1=true;
                        if (shared_from_this()->playerNo==2)
                            skip2=true;
                        if (shared_from_this()->playerNo==3)
                            skip3=true;
                        if (shared_from_this()->playerNo==4)
                            skip4=true;
                        if (shared_from_this()->playerNo==5)
                            skip5=true;
                        shared_from_this()->skipStatus=true;
                        bidChange =bidChange - 1;
                    }
                }
                if (from_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][0]"].empty() == false)
                    hand[shared_from_this()->playerNo][0] = from_player["hand["+ std::to_string(playerNo) +"][0]"];
                if (from_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][1]"].empty() == false)
                    hand[shared_from_this()->playerNo][1] = from_player["hand["+ std::to_string(playerNo) +"][1]"];
                if (from_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][2]"].empty() == false)
                    hand[shared_from_this()->playerNo][2] = from_player["hand["+ std::to_string(playerNo) +"][2]"];
                if (from_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][3]"].empty() == false)
                    hand[shared_from_this()->playerNo][3] = from_player["hand["+ std::to_string(playerNo) +"][3]"];
                if (from_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][4]"].empty() == false)
                    hand[shared_from_this()->playerNo][4] = from_player["hand["+ std::to_string(playerNo) +"][4]"];
                
                if (from_player["gimmieCards"].empty() == false)
                {
                    nlohmann::json to_player;
                    Dealer.organizeAndRank(hand[shared_from_this()->playerNo],rankHand[shared_from_this()->playerNo]);
                    
                    to_player["turn"]=turn;
                    to_player["participant"]=shared_from_this()->playerNo;
                    to_player["balance"]=shared_from_this()->balance;
                    to_player["pot"]=pot;
                    to_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][0]"]=hand[shared_from_this()->playerNo][0];
                    to_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][1]"]=hand[shared_from_this()->playerNo][1];
                    to_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][2]"]=hand[shared_from_this()->playerNo][2];
                    to_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][3]"]=hand[shared_from_this()->playerNo][3];
                    to_player["hand["+ std::to_string(shared_from_this()->playerNo) +"][4]"]=hand[shared_from_this()->playerNo][4];
                    std::string t=to_player.dump();
                    chat_message sending;
                    if (t.size() < chat_message::max_body_length)
                    {
                        memcpy( sending.body(), t.c_str(), t.size() );
                        sending.body_length(t.size());
                        sending.encode_header();
                        room_.deliver(sending);
                    }
                }
                nlohmann::json to_player2;
                if(bidChange == 1)
                {
                    std::cout<<"POT SETTLED"<<std::endl;
                    to_player2["potSettled"]=true;
                    to_player2["exchangePhase"]=true;
                    turn = 1;
                    bid=0;
                    raise_by=0;
                    lastPhase=true;
                }
                int winner = Dealer.compareHands(rankHand[1], rankHand[2], rankHand[3], rankHand[4], rankHand[5]);
                std::cout << "WINNER:  Player "+std::to_string(winner)<<std::endl;
                //to_player2["winner"]=winner;             USE THIS TO FIND WINNER     <3
                bidChange=bidChange-1;
                //send turn to all players
                to_player2["participant"]=shared_from_this()->playerNo;
                to_player2["action"]=action;
                to_player2["turn"]=turn;
                to_player2["raise_by"]=raise_by;
                to_player2["pot"]=pot;
                to_player2["bid"]=bid;
                to_player2["balance"]=shared_from_this()->balance;
                std::string t=to_player2.dump();
                chat_message sending;
                if (t.size() < chat_message::max_body_length)
                {
                    memcpy( sending.body(), t.c_str(), t.size() );
                    sending.body_length(t.size());
                    sending.encode_header();
                    room_.deliver(sending);
                }
                
            }
            do_read_header();
        }
        else
        {
            room_.leave(shared_from_this());
        }
    });
}

void poker_player::do_write()
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
