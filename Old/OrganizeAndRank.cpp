#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <cstring>
#include <array>

void printHand(int hand[], std::string condition)
{
std::cout << condition << " :";
for (int x=0;x<5;x++)
{
	std::cout << " " + std::to_string(hand[x]);
}
std::cout << std::endl;
}
void printRankHand(int hand[], std::string condition)
{
std::cout << condition << " :";
for (int x=0;x<6;x++)
{
	std::cout << " " + std::to_string(hand[x]);
}
std::cout << std::endl;
}

int organizeAndRank(int * hand, int * rankHand)
{

	int suitHand[5];
	int valueHand[5];
	int lowHand[] = {14, 5, 4, 3, 2};
	bool pass1 = true;
	bool pass2 = true;
	int temp;
	std::sort(hand, hand + 5, std::greater<int>());
	for(int x=0;x<6;x++)//reseting the rankHand
	{rankHand[x]=0;}
	for(int x=0;x<5;x++)
	{
		valueHand[x] = hand[x] / 10;
		suitHand[x] = hand[x] % 10;
	}
	for (int x=0;x<4;x++)
	{
		if(suitHand[x]!=suitHand[x+1]){pass1 = false;}//not a flush -> set false to something other than 10, 9, 6
	}
	if (pass1)//is a flush
	{
		if(valueHand == lowHand)//use ace as low card for straight flush
		{
		rankHand[0]=9;
		rankHand[1]=5;
		std::cout << "low straight flush" << std::endl;
		return 0;
		}
		pass1 = true;
		for(int x=0; x<4; x++)//straight flush?
		{
			if(valueHand[x]!=valueHand[x+1]+1){pass1 = false;}
		}
		if(pass1)//if straight flush or royal flush
		{
			if(valueHand[0]==14)//if royal flush
			{
			rankHand[0]=10;
			std::cout << "royal flush" << std::endl;
			return 0;
			}
			rankHand[0]=9;
			for(int x=0;x<5;x++)
			{
				rankHand[0]=9;
				rankHand[1]=valueHand[0];
				std::cout << "straight flush" << std::endl;
				return 0;
			}

		}
		else//at this point it is a flush but not a straight flush or royal flush
		{
			rankHand[0]=6;
			for(int x=1;x<6;x++){rankHand[x]=valueHand[x-1];}//fill rest of handRank
			std::cout << "flush" << std::endl;
			return 0;
		}
	}
	pass1 = true;
	int num1 = 0;
	int num2 = 0;
	int freq1 = 1;
	int freq2 = 1;
	for(int x=0;x<5;x++)
	{	
		if(freq1==1){num1 = valueHand[x];}
		else if(freq2==1 && valueHand[x] != num1){num2 = valueHand[x];}
		for(int y=x+1;y<5;y++)
		{
			if(valueHand[y]==num1 && pass1){num1=valueHand[y]; freq1++;}//first "kind" is found and is ready to be checked for 3 of a kind
			else if(valueHand[y]==num2 && pass2){num2=valueHand[y]; freq2++;}//second "kind" is found and is ready to be checked for 3 of a kind
		}
		if(freq1 != 1){pass1 = false;}//stop incrementing for kinds if found
		if(freq2 != 1){pass2 = false;}

	}
	if(freq1 == 4)//4 of a kind
	{
		if(valueHand[0]!=num1)
		{
		temp = hand[4];
		hand[4]=hand[0];
		hand[0]=temp;
		}
		rankHand[0]=8;
		rankHand[1]=num1;
		rankHand[2]=valueHand[4];
		std::cout << "4 of a kind" << std::endl;
		return 0;
	}
	if(freq1 == 3 || freq2 == 3)//at least one 3 of a kind
	{
		if(freq1 == 2 || freq2 == 2)//full house
		{
			if(valueHand[2] == num1 && valueHand[4] == num1)//check middle (three of a kind) and see if it's at the front. ie check for swap
			{
			temp = hand[0];
			hand[0] = hand[4];
			hand[4] = temp;
			temp = hand[1];
			hand[1] = hand[3];
			hand[3] = temp;
			temp = valueHand[0];
			valueHand[0] = valueHand[4];
			valueHand[4] = temp;
			temp = valueHand[1];
			valueHand[1] = valueHand[3];
			valueHand[3] = temp;
			}
			rankHand[0] = 7;
			rankHand[1] = num1;
			rankHand[2] = num2;
			std::cout << "full house" << std::endl;
			return 0;
		}
		if(valueHand[0]==num1)//only one three of a kind
		{}
		else if(valueHand[1]==num1)
		{
			temp=hand[0];
			hand[0]=hand[3];
			hand[3]=temp;
			temp=valueHand[0];
			valueHand[0]=valueHand[3];
			valueHand[3]=temp;
		}
		else
		{
			temp=hand[0];
			hand[0]=hand[3];
			hand[3]=temp;
			temp=hand[1];
			hand[1]=hand[4];
			hand[4]=temp;
			temp=valueHand[0];
			valueHand[0]=valueHand[3];
			valueHand[3]=temp;
			temp=valueHand[1];
			valueHand[1]=valueHand[4];
			valueHand[4]=temp;
		}
		rankHand[0]=4;
		rankHand[1]=num1;
		rankHand[2]=valueHand[3];
		rankHand[3]=valueHand[4];
		std::cout << "three of a kind" << std::endl;
		return 0;
		
	}	
	if(freq1 == 2 || freq2 == 2)//at least one pair
	{	
		if(freq1 == 2 && freq2 == 2)//two pair
		{
			for(int x=0;x<5;x++)
			{	
				if(valueHand[x]!=num1 && valueHand[x]!=num2)
				{
					if(x==0)
					{
						temp=hand[0];
						hand[0]=hand[2];
						hand[2]=temp;
						temp=hand[4];
						hand[4]=hand[2];
						hand[2]=temp;	
						temp=valueHand[0];
						valueHand[0]=valueHand[2];
						valueHand[2]=temp;
						temp=valueHand[4];
						valueHand[4]=valueHand[2];
						valueHand[2]=temp;		
					}
					else if(x==2)
					{
						temp=hand[4];
						hand[4]=hand[2];
						hand[2]=temp;	
						temp=valueHand[4];
						valueHand[4]=valueHand[2];
						valueHand[2]=temp;	
					}
					rankHand[0]=3;
					rankHand[1]=num1;
					rankHand[2]=num2;
					rankHand[3]=valueHand[4];
					std::cout << "two pair" << std::endl;
					return 0;
				}
			}
		}
		if(valueHand[0]==num1)//only one pair
		{}
		else if(valueHand[1]==num1)
		{
			temp=hand[2];
			hand[2]=hand[0];
			hand[0]=temp;
			temp=valueHand[2];
			valueHand[2]=valueHand[0];
			valueHand[0]=temp;
		}
		else if(valueHand[2]==num1)
		{
			temp=hand[2];
			hand[2]=hand[0];
			hand[0]=temp;
			temp=hand[3];
			hand[3]=hand[1];
			hand[1]=temp;
			temp=valueHand[2];
			valueHand[2]=valueHand[0];
			valueHand[0]=temp;
			temp=valueHand[3];
			valueHand[3]=valueHand[1];
			valueHand[1]=temp;
		}
		else
		{
			temp=hand[3];
			hand[3]=hand[0];
			hand[0]=temp;
			temp=hand[4];
			hand[4]=hand[1];
			hand[1]=temp;		
			temp=valueHand[3];
			valueHand[3]=valueHand[0];
			valueHand[0]=temp;
			temp=valueHand[4];
			valueHand[4]=valueHand[1];
			valueHand[1]=temp;	
		}
		rankHand[0]=2;
		rankHand[1]=num1;
		rankHand[2]=valueHand[2];
		rankHand[3]=valueHand[3];
		rankHand[4]=valueHand[4];
		std::cout << "one pair" << std::endl;
		return 0;
	}
	if(valueHand==lowHand)//test for straight with ace low card
	{
		rankHand[0]=5;
		rankHand[1]=5;
		std::cout << "straight" << std::endl;
		return 0;
	}
	pass1 = true;
	for(int x=0;x<4;x++)//test for straight
	{
		if(valueHand[x]!=valueHand[x+1]+1){pass1=false;}
	}
	if(!pass1)//high card or "junk"
	{
		rankHand[0]=1;
		for(int x=0;x<5;x++)
		{
		rankHand[x+1]=valueHand[x];
		}
		std::cout << "high card" << std::endl;
		return 0;
	}
	else//straight
	{
		rankHand[0]=5;
		rankHand[1]=valueHand[0];
		std::cout << "straight" << std::endl;
		return 0;	
	}
}
void giveHand(int * const hand, std::vector<int> &Deck)
{
	for(int x=0;x<5;x++)
	{
		if(hand[x]==0)
		{
		hand[x] = Deck.at(Deck.size()-1);
		Deck.pop_back();
		}
	}
}
int myrandom (int i) { return std::rand()%i;}
int compareHands(int hand1[], int hand2[], int hand3[], int hand4[], int hand5[])
{
	int winner =0;
	int hands[5][6];
	for(int x=0;x<6;x++)
	{
		hands[0][x]= hand1[x];
		hands[1][x]= hand2[x];
		hands[2][x]= hand3[x];
		hands[3][x]= hand4[x];
		hands[4][x]= hand5[x];
	}
	for(int x=1;x<5;x++)
	{
		for(int y=0;y<6;y++)
		{
			if(hands[winner][y]>hands[x][y])
			{
			break;
			}
			else if(hands[winner][y]<hands[x][y])
			{
			winner = x;
			break;
			}
		}
	}
	return winner+1;
}
int main(int argc, char* argv[]){
//https://drive.google.com/open?id=1mNm3gDMdWhdbsA_Dy4ZniYTyp98hjXwK
//go here to see the Example Card Hands
std::cout << ".....PREDEFINED HANDS....." << std::endl;
int RoyalFlush[5]={144,134,124,114,104};
int StraightFlush[5]={92,82,72,62,52};
int FourKind[5]={141,143,144,142,94};
int FullHouse[5]={123,124,122,111,112};
int Flush[5]={143,113,93,63,33};
int Straight[5]={91,82,74,62,54};
int ThreeKind[5]={52,121,23,24,22};
int TwoPair[5]={143,141,133,134,92};
int OnePair[5]={43,54,81,142,144};
int HighCard[5]={54,62,111,122,144};
int testRankHand[6];
organizeAndRank(RoyalFlush,testRankHand);
printHand(RoyalFlush, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(StraightFlush,testRankHand);
printHand(StraightFlush, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(FourKind,testRankHand);
printHand(FourKind, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(FullHouse,testRankHand);
printHand(FullHouse, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(Flush,testRankHand);
printHand(Flush, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(Straight,testRankHand);
printHand(Straight, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(ThreeKind,testRankHand);
printHand(ThreeKind, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(TwoPair,testRankHand);
printHand(TwoPair, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(OnePair,testRankHand);
printHand(OnePair, "Hand");
printRankHand(testRankHand, "Rank");
organizeAndRank(HighCard,testRankHand);
printHand(HighCard, "Hand");
printRankHand(testRankHand, "Rank");


std::cout << ".....RANDOMIZED....." << std::endl;

std::srand ( unsigned ( std::time(0) ) );
std::vector<int> Deck;//1. Deck is declared
int size = 0;//2. Deck is filled
for(int x = 2; x<=14; x++)
{
	for(int y=1;y<=4;y++)
	{
	Deck.push_back(x * 10 + y);
	size++;
	}
}
std::random_shuffle ( Deck.begin(), Deck.end() );
std::random_shuffle ( Deck.begin(), Deck.end(), myrandom);//3. Deck is shuffled
int playerHand[5]={0,0,0,0,0};//4. The player's hand is empty
int player2Hand[5]={0,0,0,0,0};
int player3Hand[5]={0,0,0,0,0};
int player4Hand[5]={0,0,0,0,0};
int player5Hand[5]={0,0,0,0,0};
int playerRankHand[6]={0,0,0,0,0,0};
int player2RankHand[6]={0,0,0,0,0,0};
int player3RankHand[6]={0,0,0,0,0,0};
int player4RankHand[6]={0,0,0,0,0,0};
int player5RankHand[6]={0,0,0,0,0,0};
giveHand(playerHand, Deck);//5. Player is given 5 random cards
std::cout << std::endl;
printHand(playerHand, "Hand Before Organization");
organizeAndRank(playerHand,playerRankHand);//6. Hand is organized and ranked
printHand(playerHand, "Hand After Organization");
printRankHand(playerRankHand, "Rank Hand");
int exchange[5];

for (int x=0;x<5;x++)//7. Cards to be exchanged are received from the player
{
	char input[1];
	std::cout << "Would you like to exchange card #" << x + 1 << "? (y/n)";
	scanf("%s", input);
	std::cout << std::endl;
	if(strcmp(input, "y")==0)//8. If that card to be exchanged was chosen, that card will be set to zero
	{
	playerHand[x]=0;
	}
}
giveHand(playerHand, Deck);//9. giveHand will be called again. if an element in the card is 0, it will be given a new card
std::cout <<  "\nPlayer 1: " << std::endl;
organizeAndRank(playerHand,playerRankHand);//10. Hand is organized and ranked again
printHand(playerHand, "Hand After Exchaning");
printRankHand(playerRankHand, "Rank After Exchaning");
giveHand(player2Hand, Deck);
std::cout <<  "\nPlayer 2: " << std::endl;
organizeAndRank(player2Hand,player2RankHand);
printHand(player2Hand, "Hand");
printRankHand(player2RankHand, "Rank");
giveHand(player3Hand, Deck);//11. Lets say there was only 3 total players
std::cout <<  "\nPlayer 3: " << std::endl;
organizeAndRank(player3Hand,player3RankHand);
printHand(player3Hand, "Hand");
printRankHand(player3RankHand, "Rank");
int winner = compareHands(playerRankHand, player2RankHand, player3RankHand, player4RankHand, player5RankHand);
std::cout << "\nPlayer #" << winner << " is the winner!" << std::endl;
  return 0;
}



