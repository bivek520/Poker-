#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

// random generator function:
int myrandom (int i) { return std::rand()%i;}

int main () {
    std::srand ( unsigned ( std::time(0) ) );
    std::vector<int> Deck;
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
    
    /*for ( i=200; i<=213; i++)
    {
        Deck.push_back(i);

    }
    for ( i=300; i<=313; i++)
    {
        Deck.push_back(i);

    }
    for ( i=400; i<=413; i++)
    {
        Deck.push_back(i);

    }*/
    
  std::vector<int> ShuffledDeck;

  // using built-in random generator:
  std::random_shuffle ( Deck.begin(), Deck.end() );

  // using myrandom:
  std::random_shuffle ( Deck.begin(), Deck.end(), myrandom);

  ShuffledDeck.assign(Deck.begin(), Deck.end());
  
  // print out content:
  std::cout << "ShuffledDeck contains:\n";
  for (std::vector<int>::iterator it=Deck.begin(); it!=Deck.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << "\n\nCopied contains:\n";

    for (std::vector<int>::iterator it=ShuffledDeck.begin(); it!=ShuffledDeck.end(); ++it)
       std::cout << ' ' << *it;
  std::cout << '\n';
   /* 
    int player1[5];
    int player2[5];
    int player3[5];
    vector<player> list;
    for(i=0;i<5;i++)
    {
        for(list.begin,list.end)
        {
        player1[i]=ShuffledDeck.pop_back();
        player2[i]=ShuffledDeck.pop_back();
        player3[i]=ShuffledDeck.pop_back();
        }
    }
*/
  return 0;
}

