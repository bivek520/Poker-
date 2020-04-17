CXXFLAGS +=  -DASIO_STANDALONE -Wall -O0 --std=c++11
CPPFLAGS+=-I./include -I./asio-1.12.2/include
LDLIBS+= -lpthread
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: asio-1.12.2 mainwindow server

asio-1.12.2:
	tar xzf asio-1.12.2.tar.gz

server: server.o *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) server.o $(GTKFLAGS) -o dealer

mainwindow: main.o mainwin.o *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) ch_header.cpp main.o mainwin.o $(GTKFLAGS) -o pokerplus

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
server.o: server.cpp *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c server.cpp $(GTKFLAGS) -o server.o
clean:
	rm -f *.o *.gch mainwindow


