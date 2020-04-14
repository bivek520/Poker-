CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: mainwindow

mainwindow: server.o main.o mainwin.o *.h
	$(CXX) $(CXXFLAGS) server.o main.o mainwin.o $(GTKFLAGS) -o pokerplus
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
server.o: server.cpp *.h
	$(CXX) $(CXXFLAGS) -c server.cpp $(GTKFLAGS) -o server.o
clean:
	rm -f *.o *.gch mainwindow


