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
	int* rankingHand();
    private:
        vector<int> hand;
        int playerID;
        int playerIP;
        int balance;
        int bid;
	vector<int> OrganizedHand;
        vector<int> SuitHand;
        vector<int> ValueHand;
	int rankArray[2];
};

class Dealer
{
    public:
	Dealer(char* portNumber);
	void CompareHands( );    //how do we pass in Player1.hand?
	void GiveHand(vector<int> ShuffledDeck);
	void Pot_Add(int *Pot);
	void Pot_Set();
	void Exchange();
	void GivePot();
	void SplitPot();
	void NextPlayer();
   private:
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
	void Slider(Gtk::Scale *Slider);
	void SliderStatus(Gtk::Scale *Slider); //or Widget
	void MinAdd();
	void MaxAdd();
	void Balance_Opacity();
	void Timer();
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
