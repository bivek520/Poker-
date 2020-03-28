#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
//#include "shelter.h"
#include <fstream>

const std::string APP_TITLE{"POKER ++"};
const std::string APP_NAME{"edu.uta.cse1325.mass.v0_1_0"};
const std::string VERSION{"0.1.0"};
const std::string EXT = "mass";
const std::string COOKIE{"M⅍S1"};


class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
	void on_fold_click();
	void on_call_click();
	void on_raise_click();
	void on_exchange_click();
	Gtk::VBox vbox;
	Gtk::HBox hbox;
	  Gtk::Grid m_Grid;
/*	void on_new_game_click();*/
/*        void on_quit_click();              // Exit the application*/
/*        void on_about_click();              // new window displaying game rules and info*/


    private:

        Gtk::Label p1,p2,p3,p4,p5;                  // Display player name
        Gtk::Label action1, action2, action3, action4, action5;                   // Action message display
	Gtk::Label balance1, balance2, balance3, balance4, balance5;		//Player's current balance, Available amount 
	Gtk::Label indicator1, indicator2, indicator3, indicator4, indicator5;   //Indicates whose turn.
	Gtk::Label pot;
	Gtk::Label image11, image12, image13, image14, image15;          //player1 hands
	Gtk::Label image21, image22, image23, image24, image25;	//player2 hands
	Gtk::Label image31, image32, image33, image34, image35;	//player3 hands
	Gtk::Label image41, image42, image43, image44, image45;	//player4 hands
	Gtk::Label image51, image52, image53, image54, image55;	//player5 hands

	Gtk::Label hand1, hand2, hand3, hand4, hand5;	//your hands, big picture

	Gtk::Button fold, call, raise, exchange;    // required buttons         
};
#endif 

