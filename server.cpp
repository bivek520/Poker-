#include "server.h"
#include <cstdlib>

Server::Server()
{


}
Server::~Server() { }
void Server::organizeHand(int hand[])
{
	int suitHand[5];
	int valueHand[5];
	for (int x = 0; x < 5;x++)
	{
	valueHand[x] = hand[x] / 10;
	suitHand[x] = hand[x] % 10;
	}
	/*
	std::cout << "valueHand: " << std::endl;
	for (int x = 0; x < 5;x++)
	{
	std::cout << ", " + valueHand[x] << std::endl;
	}
	std::cout << "\n suitHand: " << std::endl;
	for (int x = 0; x < 5;x++)
	{
	std::cout << ", " + suitHand[x] << std::endl;
	}
	*/
}

