#ifndef POKER_H
#define POKER_H
#include <vector>

using namespace std;



class card
{
public:
    int value;
    char suit;
};

class player
{
public:
    vector<card> hand;
};

class deck
{
    vector<card> d;
};

class Player
{
    public:
        Player();
        void Fold(); //call Fold_Button_Pressed() in MainWindow
        void Check();
        void Call();
        void Raise();
        void Bet();
        void All_In();
        void Timer();
        void TimeOut();
        vector SuitHand(hand);
        vector ValueHand(hand);
    private:
        vector<int> hand;
        int playerID;
        int playerIP;
        int balance;
        int bid;
        vector<int> SuitHand;
        vector<int> ValueHand;
};

class Dealer
{
    public:
        
#endif
