#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include <gtkmm.h>
#include <sstream>
#include <fstream>
#include "player.h"
const std::string APP_TITLE{"PokerPlus"};
const std::string APP_NAME{"edu.uta.cse1325.mass.v0_1_0"};
const std::string VERSION{"0.1.0"};
const std::string EXT = "mass";
const std::string TITLE = "PokerPlus";
const std::string COOKIE{"M⅍S1"};
using namespace std;

class MainWindow : public Gtk::Window 
{
    public:
        MainWindow();
        virtual ~MainWindow();
	void Refresh();
	void Display_Player_Hand();
	void Balance_Visibility();
	void Player_Status();
	void Fold_Button_Pressed();
	void Match_Button_Color();
	void Match_Button_Label();
	void Match_Button_Pressed();
	void Add_Button_Pressed();
	void Exchange_Button_Label();
	void Exchange_Button_Pressed();
	void Status_Label();
	void Status_Color();
	void Status_Opacity();
	void Slider_();
	void SliderStatus(); 
	void MinAdd();
	void MaxAdd();
	void Balance_Opacity();
	void Reveal_Cards();
	void SelectionBoxStatus();
	void TurnPosition();
	void PlayerCards();
	void Pot(int potValue);
	void Timer();
	void Id_Opacity();
    private:
	Player *player;
	Gtk::Label* Label_Shape;
	Gtk::Button* Button_Shape;
	Gtk::Button* Add_Button;
	Gtk::Button* Fold_Button;
	Gtk::Button* Exchange_Button;
	Gtk::Scale* Slider; //or Widget
};

#endif
