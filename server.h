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
	void fold(int player, std::string playerAction)
	void call(int potValue, int playerBalance, std::string playerAction);
	void bet(int potValue, int playerBalance, std::string playerAction);
	void raise(int potValue, int playerBalance, std::string playerAction);
	void All_in(int potValue, int playerBalance, std::string playerAction);
	int minBet();
	int maxBet();
	int minRaise();
	inr maxRaise();
    private:
	int potVal;
	bool exchanged;
	bool fold;
};
#endif 

