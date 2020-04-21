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
	void exchange(bool EPhase, int hands[]);
	void givePot(std::string playerID);
	void splitPot(int player);
	void fold(int player, std::string playerAction);
	void call(int potValue, int playerBalance, std::string playerAction);
	void bet(int potValue, int playerBalance, std::string playerAction);
	void raise(int potValue, int playerBalance, std::string playerAction);
	void All_in(int potValue, int playerBalance, std::string playerAction);
	int minBet();
	int maxBet();
	int minRaise();
	int maxRaise();
	void gameWin(std::string playerID);
	void bidReset(bool BPhase2,int bidAmount);


    private:
	int potVal;
	int betAmount;
	int bidAmount;
	int playerBalance;
	std::string playerID;
	std::string playerAction;
	int hands[];
	bool EPhase;
	bool BPhase1;
	bool BPhase2;
	bool potSettled
	bool fold;
	std::string playerID
};
#endif 

