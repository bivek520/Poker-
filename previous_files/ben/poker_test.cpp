#define BOOST_TEST_MODULE pokertest
#include <boost/test/included/unit_test.hpp>
#include "dealer.h"
#include <vector>
BOOST_AUTO_TEST_SUITE (pokertest)

BOOST_AUTO_TEST_CASE (royal_flush)
{
   dealer  D;
    int hand[5]= {141,131,121,111,101};
    int rankHand[6];

    D.organizeAndRank(hand,rankHand);
    //after calling the organizeAndRank() it updates the rankHand depending on the hand of the player.

    BOOST_CHECK(rankHand[0]==10);

}
BOOST_AUTO_TEST_CASE (straight_flush)
{

   dealer  D;
    int hand[5]= {53,63,73,83,93};
    int rankHand[6];

    D.organizeAndRank(hand,rankHand);
    
    BOOST_CHECK(rankHand[0]==9);
    
}
BOOST_AUTO_TEST_CASE (four_of_a_kind)
{

   dealer  D;
    int hand[5]= {141,142,143,144,101};
    int rankHand[6];

    D.organizeAndRank(hand,rankHand);
    
    BOOST_CHECK(rankHand[0]==8);
    
}

BOOST_AUTO_TEST_CASE (full_house)
{

   dealer  D;
    int hand[5]= {141,142,143,134,132};
    int rankHand[6];

    D.organizeAndRank(hand,rankHand);
    
    BOOST_CHECK(rankHand[0]==7);
    
}
BOOST_AUTO_TEST_CASE (two_pair)
{

   dealer  D;
    int hand[5]= {141,142,81,134,132};
    int rankHand[6];

    D.organizeAndRank(hand,rankHand);
    
    BOOST_CHECK(rankHand[0]==3);
    
}

BOOST_AUTO_TEST_CASE (legalDeck)
{

   dealer  D;
    D.createDeck();
    
    std::vector<int> Deck = D.getDeck();
std::vector<int>::iterator it;
    BOOST_CHECK(Deck.size()==52);

    for(int i = 2; i<=14; i++)
    {
        for(int y=1;y<=4;y++)
        {
        
            it = std::find (Deck.begin(), Deck.end(), i * 10 + y);
            BOOST_CHECK(it != Deck.end());
        }
    }
    
    
}

BOOST_AUTO_TEST_SUITE_END( )
