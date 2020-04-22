#include "dealer.h"

dealer::dealer()
{
}

/*int dealer::myrandom (int i) 
{ 
   return std::rand()%i;
}*/

void dealer::createDeck()
{
   int i;
    //push cards on cards vector
    //first 2 digits are value, last is face
    //1 is clubs
    //2 is diamonds
    //3 is hearts
    //4 is spades
    //2 for 2, 3 for 3...,11 for Jack, 12 for Queen, 13 for King, 14 for Ace
    for ( i=101; i<=104; i++)
        Deck.push_back(i);
    for ( i=111; i<=114; i++)
        Deck.push_back(i);
    for ( i=121; i<=124; i++)
        Deck.push_back(i);
    for ( i=131; i<=134; i++)
        Deck.push_back(i);
    for ( i=141; i<=144; i++)
        Deck.push_back(i);
    for ( i=21; i<=24; i++)
        Deck.push_back(i);
    for ( i=31; i<=34; i++)
        Deck.push_back(i);
    for ( i=41; i<=44; i++)
        Deck.push_back(i);
    for ( i=51; i<=54; i++)
        Deck.push_back(i);
    for ( i=61; i<=64; i++)
        Deck.push_back(i);
    for ( i=71; i<=74; i++)
        Deck.push_back(i);
    for ( i=81; i<=84; i++)
        Deck.push_back(i);
    for ( i=91; i<=94; i++)
        Deck.push_back(i);
//}

//void dealer::shuffleDeck()
//{
  std::srand ( unsigned ( std::time(0) ) );
  // using built-in random generator:
  std::random_shuffle ( Deck.begin(), Deck.end() );
  // using myrandom:
  std::random_shuffle ( Deck.begin(), Deck.end(), [&](int i) {return std::rand()%i;});
}

std::vector<int> dealer::getDeck()
{
   return Deck;
}
