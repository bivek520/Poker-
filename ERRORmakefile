all : gtkmm-3.24.2 src/player src/dealer src/MainWindow src/main

gtkmm-3.24.2:
	tar xzf gtkmm-3.24.2.tar.xz
	
CXXFLAGS+= -Wall -O0 -g -std=c++11
CPPFLAGS+=-I./include -I./gtkmm-3.24.2/gtk/gtkmm.h
LDLIBS+= --cflags --libs`

clean:
	-rm -rf gtkmm-3.24.2
	-rm -f src/player
	-rm -f src/dealer
	-rm -f src/MainWindow
	-rm -f src/main

