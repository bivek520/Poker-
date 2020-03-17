#ifndef POKER_H
#define POKER_H
#include <vector>
//test sef
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


#endif