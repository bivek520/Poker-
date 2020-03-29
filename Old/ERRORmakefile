SRC1 = ../src/player.cpp
SRC2 = ../src/dealer.cpp
SRC3 = ../src/MainWindow.cpp
SRC4 = ../src/main.cpp

OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4 = $(SRC4:.cpp=.o)

EXE = $(SRC4:.cpp=.e)

HFILES1 = ../include/player.h
HFILES2 = ../include/dealer.h
HFILES3 = ../include/MainWindow.h

#all : src/player src/dealer src/MainWindow src/main
all: $(EXE)

#GTKFLAGS = $(shell pkg-config --cflags --libs gtk+-3.0)

GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0  --cflags --libs`
CFLAGS = -Wall -O0 -g -std=c++11

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) -o $(EXE) $(GTKFLAGS)


$(OBJ1) : $(SRC1) $(HFILES1)

	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1) 
  

$(OBJ2) : $(SRC2) $(HFILES2)

	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2) 
  

$(OBJ3) : $(SRC3) $(HFILES3)

	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3) $(GTKFLAGS)
  

$(OBJ4) : $(SRC4) $(HFILES1) $(HFILES2) $(HFILES3)

	g++ -c $(CFLAGS) $(SRC4) -o $(OBJ4) $(GTKFLAGS)

clean:
#	-rm -rf gtkmm-3.24.2
#	-rm -f *.o
#	-rm -r $(EXE)
	-rm -f src/player
	-rm -f src/dealer
	-rm -f src/MainWindow
	-rm -f src/main

