CXXFLAGS += -DASIO_STANDALONE -Wall -O0 -g --std=c++11
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
CPPFLAGS+= -I./*.h -I./asio-1.12.2/include -I.`/usr/bin/pkg-config gtkmm-3.0  --cflags --libs`
LDLIBS+= -lpthread `/usr/bin/pkg-config gtkmm-3.0  --cflags --libs`

all: asio-1.12.2 mainwindow server

asio-1.12.2:
	tar xzf asio-1.12.2.tar.gz

server: server.o *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) server.o $(GTKFLAGS) -o dealer
mainwindow: main.o mainwin.o main.o *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) main.o mainwin.o $(GTKFLAGS) -o pokerplus
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
#ch_header.o: ch_header.cpp *.h
#	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c ch_header.cpp $(GTKFLAGS) -o ch_header.o
server.o: server.cpp *.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) -c server.cpp $(GTKFLAGS) -o server.o
clean:
	rm -f *.o *.gch mainwindow server
	rm -rf asio-1.12.2