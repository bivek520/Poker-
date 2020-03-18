#include <iostream>
#include "poker.h"

int main()
{
	//PLAYER
	Player::Player(char* playerIP, char* portNumber)
	{
		//argv[1] has IP address of player used to connect to server,
		//argv[2] has port number of server
	}
        void Player::Fold()
	{
		//call Fold_Button_Pressed() in MainWindow
	}
        void Player::Check()
	{
		
	}
        void Player::Call()
	{
		
	}
        void Player::Raise()
	{
		
	}
        void Player::Bet()
	{
		
	}
        void Player::All_In()
	{
		
	}
        void Player::Timer()
	{
		
	}
        bool Player::TimeOut()
	{
		
	}
	vector<int> Player::getHandOrganized()
	{
		
	}
        vector<int> Player::getSuitHand()
	{
		
	}
        vector<int> Player::getValueHand()
	{
		
	}
	vector<int> Player::rankingHand()
	{
		
	}
	
	//DEALER
	Dealer::Dealer(char* portNumber)
	{
		//argv[2] has a port number used to construct Dealer object
	}
	void Dealer::CompareHands(vector<int> > playersRanks)
	{
		//playersRanks is a vector that will be created in main by pushing back Player1/2/3.Rankings
		//inside a for loop for(int i=0; i<playerSize; i++)
	}
	void Dealer::GiveHand()
	{
		
	}
	void Dealer::Pot_Add()
	{
		
	}
	void Dealer::Pot_Set()
	{
		
	}
	void Dealer::Exchange()
	{
		
	}
	void Dealer::GivePot()
	{
		
	}
	void Dealer::SplitPot()
	{
		
	}
	void Dealer::NextPlayer()
	{
		
	}
	
	//UI
	MainWindow::MainWindow()
	{
		
	}
	void Refresh()
	{
		
	}
	void Display_Player_Hand()
	{
	
	}
	void Balance_Visibility()
	{
		
	}
	void Player_Status()
	{
		
	}
	void Fold_Button_Pressed()
	{
		
	}
	void Match_Button_Color()
	{
		
	}
	void Match_Button_Label()
	{
		
	}
	void Match_Button_Pressed()
	{
		
	}
	void Add_Button_Pressed()
	{
		
	}
	void Exchange_Button_Label()
	{
		
	}
	void Exchange_Button_Pressed()
	{
		
	}
	void Status_Label()
	{
		
	}
	void Status_Color()
	{
		
	}
	void Status_Opacity()
	{
		
	}
	void Slider(Gtk::Scale *Slider)
	{
		
	}
	void SliderStatus(Gtk::Scale *Slider) //or Widget
	{
		
	}
	void MinAdd()
	{
		
	}
	void MaxAdd()
	{
		
	}
	void Balance_Opacity()
	{
		
	}
	void Timer()
	{
		
	}
	void Reveal_Cards()
	{
		
	}
	void SelectionBoxStatus()
	{
		
	}
	void TurnPosition()
	{
		
	}
	void PlayerCards()
	{
		
	}
	void Pot(int Dealer::Dealer.Pot)
	{
		
	}
	void Timer()
	{
		
	}
	void Id_Opacity()
	{
		
	}
	virtual ~Mainwindow()
	{
	}
	return 0;
}
