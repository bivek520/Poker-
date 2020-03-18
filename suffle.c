#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

// random generator function:
int myrandom (int i) { return std::rand()%i;}

int main () {
  std::srand ( unsigned ( std::time(0) ) );
  std::vector<int> ShuffledDeck;

  // set some values:
  for (int i=1; i<=52; ++i) ShuffledDeck.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  std::random_shuffle ( ShuffledDeck.begin(), ShuffledDeck.end() );

  // using myrandom:
  std::random_shuffle ( ShuffledDeck.begin(), ShuffledDeck.end(), myrandom);

  // print out content:
  std::cout << "ShuffledDeck contains:";
  for (std::vector<int>::iterator it=ShuffledDeck.begin(); it!=ShuffledDeck.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
