#ifndef DEALER_H
#define DEALER_H
#include <vector>
#include <gtkmm.h>

using namespace std;


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

#endif
