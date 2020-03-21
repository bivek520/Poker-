all : src/player src/dealer src/MainWindow 

CXXFLAGS+= -Wall -O0 -g -std=c++11
CPPFLAGS+= -I./include `/usr/bin/pkg-config gtk+-3.0 --cflags`
LDLIBS+= `/usr/bin/pkg-config gtk+-3.0 --cflags --libs`
#LDLIBS = $(shell pkg-config --cflags --libs gtk+-3.0)

clean:
        -rm -f src/player
        -rm -f src/dealer
        -rm -f src/MainWindow
        -rm -f src/main
