#ifndef __DEALER_H
#define __DEALER_H
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

class dealer
{
   public:
	   dealer();
//	   int myrandom (int i);
	   void createDeck();
//	   void shuffleDeck();
	   std::vector<int> getDeck();
   private:
	   std::vector<int> Deck;
	   int i;
//	   std::srand ( unsigned ( std::time(0) ) );
};
#endif
