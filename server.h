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
    private:
	int potVal;
};
#endif 

