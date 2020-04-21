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
    for ( i=100; i<=113; i++)
    {
        Deck.push_back(i);
    }
    for ( i=200; i<=213; i++)
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

    }
    
  std::vector<int> ShuffledDeck;

  // set some values:
//  for (int i=1; i<=52; ++i) ShuffledDeck.push_back(i); // 1 2 3 4 5 6 7 8 9

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
    
    int player1[5];
    int player2[5];
    int player3[5];
    vector<player> list;
    for(i=0;i<5;i++)
    {
        for(list.begin,li)
        {
        player1[i]=ShuffledDeck.pop_back();
        player2[i]=ShuffledDeck.pop_back();
        player3[i]=ShuffledDeck.pop_back();
        }
    }

  return 0;
}

