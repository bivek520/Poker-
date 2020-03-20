all : src/player src/dealer src/MainWindow src/main
	
CXXFLAGS+= -Wall -O0 -g -std=c++11
CPPFLAGS+= -I./include 
LDLIBS+= $(shell pkg-config --cflags --libs gtk+-2.0)

clean:
	-rm -rf gtkmm-3.24.2
	-rm -f src/player
	-rm -f src/dealer
	-rm -f src/MainWindow
	-rm -f src/main

