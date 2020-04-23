CXXFLAGS +=  -DASIO_STANDALONE -Wall -O0 --std=c++11
CPPFLAGS+=-I./include -I./asio-1.12.2/include
LDLIBS+= -lpthread
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: asio-1.12.2 mainwindow server

asio-1.12.2:
	tar xzf asio-1.12.2.tar.gz

server: dealer.o server.o
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) dealer.o server.o  $(GTKFLAGS) -o dealer

mainwindow:  mainwin.o chat_client.o main.o
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) main.o mainwin.o chat_client.o $(GTKFLAGS) -o pokerplus

main.o: main1.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c main1.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
chat_client.o: chat_client.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c chat_client.cpp $(GTKFLAGS) -o chat_client.o
dealer.o: dealer.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c dealer.cpp $(GTKFLAGS) -o dealer.o
server.o: server.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c server.cpp $(GTKFLAGS) -o server.o

clean:
	rm -f *.o *.gch mainwindow dealer pokerplus
	rm -rf asio-1.12.2



