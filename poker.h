#ifndef POKER_H
#define POKER_H
#include <vector>
#include <gtkmm.h>

using namespace std;

class Player
{
    public:
        Player(char* playerIP, char* portNumber);
        void Fold(); 
        void Check();
        void Call();
        void Raise();
        void Bet();
        void All_In();
        void Timer();
        bool TimeOut();
	vector<int> getHandOrganized();
        vector<int> getSuitHand();
        vector<int> getValueHand();
	vector<int> rankingHand();
    private:
        vector<int> Hand;
        int PlayerID;
        char* PlayerIP;
        int Balance;
        int Bid;
	vector<int> OrganizedHand;
        vector<int> SuitHand;
        vector<int> ValueHand;
	vector<int> Rankings;
};

class Dealer
{
    public:
	Dealer(char* portNumber);
	void CompareHands(vector<int> playersRanks);
	void GiveHand();
	void Pot_Add();
	void Pot_Set();
	void Exchange(vector<int> playerHand);
	void GivePot();
	void SplitPot();
	void NextPlayer();
   private:
	char* portNumber;
	vector<int> StaticDeck;
	vector<int> ShuffledDeck;
	int PlayerSize;
	int Pot;
	int CurrentTurn;
};

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
