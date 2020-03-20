#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include <gtkmm.h>

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
	Gtk::Label* Label_Shape;
	Gtk::Button* Button_Shape;
	Gtk::Button* Add_Button;
	Gtk::Button* Fold_Button;
	Gtk::Button* Exchange_Button;
	Gtk::Scale* Slider; //or Widget
};

#endif
