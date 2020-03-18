SRC = poker.cpp

OBJ = $(SRC:.cpp=.o)

EXE = $(SRC:.cpp=.e)

GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0  --cflags --libs`
CFLAGS = -g -std=c++11


all : $(EXE)

 
$(EXE): $(OBJ) 

	g++ $(CFLAGS) $(OBJ) -o $(EXE) $(GTKFLAGS)


$(OBJ) : $(SRC)

	g++ -c $(CFLAGS) $(SRC) -o $(OBJ) $(GTKFLAGS)
