#include <iostream>
#include "player.h"
#include "dealer.h"
#include "MainWindow.h"


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
void Dealer::CompareHands(vector<int> playersRanks)
{
    //playersRanks is a vector that will be created in main by pushing back Player1/2/3.Rankings
    //inside a for loop for(int i=0; i<playerSize; i++)
}
void Dealer::GiveHand()
{
    //using json
}
void Dealer::Pot_Add()
{
    
}
void Dealer::Pot_Set()
{
    
}
void Dealer::Exchange(vector<int> playerHand)
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
void MainWindow::Refresh()
{
    
}
void MainWindow::Display_Player_Hand()
{
    
}
void MainWindow::Balance_Visibility()
{
    
}
void MainWindow::Player_Status()
{
    
}
void MainWindow::Fold_Button_Pressed()
{
    
}
void MainWindow::Match_Button_Color()
{
    
}
void MainWindow::Match_Button_Label()
{
    
}
void MainWindow::Match_Button_Pressed()
{
    
}
void MainWindow::Add_Button_Pressed()
{
    
}
void MainWindow::Exchange_Button_Label()
{
    
}
void MainWindow::Exchange_Button_Pressed()
{
    
}
void MainWindow::Status_Label()
{
    
}
void MainWindow::Status_Color()
{
    
}
void MainWindow::Status_Opacity()
{
    
}
void MainWindow::Slider_()
{
    
}
void MainWindow::SliderStatus() //or Widget
{
    
}
void MainWindow::MinAdd()
{
    
}
void MainWindow::MaxAdd()
{
    
}
void MainWindow::Balance_Opacity()
{
    
}

void MainWindow::Reveal_Cards()
{
    
}
void MainWindow::SelectionBoxStatus()
{
    
}
void MainWindow::TurnPosition()
{
    
}
void MainWindow::PlayerCards()
{
    
}
void MainWindow::Pot(int potValue)
{
    
}
void MainWindow::Timer()
{
    
}
void MainWindow::Id_Opacity()
{
    
}
MainWindow::~MainWindow()
{
}

int main(){return 0;}
