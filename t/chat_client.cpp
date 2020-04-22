#include "mainwin.h"
#include "chat_client.h"
#include <assert.h>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include "asio.hpp"
#include "chat_message.hpp"
#include "json.hpp"
#include <string>

extern Mainwin *win;
using asio::ip::tcp;
using namespace std;
typedef std::deque<chat_message> chat_message_queue;

//int turn;
//int playerNo;
//string uuid;
//bool start;

    chat_client::chat_client(asio::io_context& io_context,
                const tcp::resolver::results_type& endpoints)
    : io_context_(io_context),
    socket_(io_context)
    {
        
        do_connect(endpoints);
    }
    
    void chat_client::write(const chat_message& msg)
    {
        
        asio::post(io_context_,
                   [this, msg]()
                   {
//            cout<<"this is the write"<<endl;
            bool write_in_progress = !write_msgs_.empty();
            write_msgs_.push_back(msg);
            if (!write_in_progress)
            {
                
                do_write();
            }
        });
    }
    
    void chat_client::close()
    {
        asio::post(io_context_, [this]() { socket_.close(); });
    }
    
    void chat_client::do_connect(const tcp::resolver::results_type& endpoints)
    {
        
        // CSE3310 connection is established with the server
        asio::async_connect(socket_, endpoints,
                            [this](std::error_code ec, tcp::endpoint)
                            {
            if (!ec)
            {
                do_read_header();
            }
        });
    }
    
    void chat_client::do_read_header()
    {
        
        asio::async_read(socket_,
                         asio::buffer(read_msg_.data(), chat_message::header_length),
                         [this](std::error_code ec, std::size_t /*length*/)
                         {
            if (!ec && read_msg_.decode_header())
            {
                for (unsigned int i=0;i<chat_message::max_body_length;i++)
                {
                read_msg_.body() [i] = '\0';
                }
                do_read_body();
            }
            else
            {
                socket_.close();
            }
        });
    }
    
    void chat_client::do_read_body()
    {
        
        //CSE 3310 message body is received from the server
        asio::async_read(socket_,
                         asio::buffer(read_msg_.body(), read_msg_.body_length()),
                         [this](std::error_code ec, std::size_t /*length*/)
                         {
            if (!ec)
            {
               
	   	nlohmann::json from_dealer = nlohmann::json::parse(read_msg_.body());
                cout << "after parse "<<endl;

                std::cout.write(read_msg_.body(), read_msg_.body_length());

                if (from_dealer["playerNo"].empty()==false)
                        playerNo = from_dealer["playerNo"];
                if (from_dealer["start"].empty()==false)
                        start = from_dealer["start"];
                if (from_dealer["turn"].empty() == false)
                        turn = from_dealer["turn"];
                if (from_dealer["uuid"].empty() == false)
                        uuid = from_dealer["uuid"];
		
		//cards stuff
		if (from_dealer["card1"].empty() == false)
			card1 = from_dealer["card1"];
		if (from_dealer["card2"].empty() == false)
                        card2 = from_dealer["card2"];
		if (from_dealer["card3"].empty() == false)
                        card3 = from_dealer["card3"];
		if (from_dealer["card4"].empty() == false)
                        card4 = from_dealer["card4"];
		if (from_dealer["card5"].empty() == false)
                        card5 = from_dealer["card5"];

                if (turn>0 && playerNo>0 && turn==playerNo)
		       win->updateButton();	
		if (turn>0 && playerNo>0 && turn!=playerNo)
		       win->grayOutButton();
		if (turn>=2)
			win->shiftIndicator();		
                std::cout << "\n";
//                win->shiftIndicator();

                do_read_header();
            }
            else
            {
                socket_.close();
            }
        });
    }
    
    void chat_client::do_write()
    {
        //cout<<"at do_write"<<endl<<endl;
        //CSE 3310 message is sent to the chat server.
        asio::async_write(socket_,
                          asio::buffer(write_msgs_.front().data(),
                                       write_msgs_.front().length()),
                          [this](std::error_code ec, std::size_t /*length*/)
                          {
            //cout<<"do_write inside async_write"<<endl<<endl;
            
            if (!ec)
            {
                write_msgs_.pop_front();
                //cout<<"do_write->async_write->if brace"<<std::endl;
                if (!write_msgs_.empty())
                {
                    do_write();
                }
            }
            else
            {
                
                socket_.close();
            }
        });
    }

    int chat_client::getCard1()
    {
	return card1;
    }

    int chat_client::getCard2()
    {
        return card2;
    }

    int chat_client::getCard3()
    {
        return card3;
    }

    int chat_client::getCard4()
    {
        return card4;
    }

    int chat_client::getCard5()
    {
        return card5;
    }

