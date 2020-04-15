#ifndef __SERVER_H
#define __SERVER_H
#include <iostream>

class Server {
    public:
        Server();
        virtual ~Server();
    protected:
	void organizeHand(int hand[]); 
	void rankHand();
	
	//please check if it's correct
	int setBalance();
	void exchange(bool exchanged, int hands[]);
	void givePot(int winner);
	void splitPot(int player)
	void fold(int player)
	void call(int currentBalance, int playerBalance);
	void bet(int currentBalance, int playerBalance);

    private:
	int potVal;
	bool exchanged;
	bool fold;
};
#endif 

