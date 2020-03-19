SRC = poker.cpp

OBJ = $(SRC:.cpp=.o)

EXE = $(SRC:.cpp=.e)

GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0  --cflags --libs`
CFLAGS = -Wall -O0 -g -std=c++11


all : $(EXE) 

 
$(EXE): $(OBJ) 

	g++ $(CFLAGS) $(OBJ) -o $(EXE) $(GTKFLAGS)


$(OBJ) : $(SRC)

	g++ -c $(CFLAGS) $(SRC) -o $(OBJ) $(GTKFLAGS)
	
clean:
	-rm -f $(OBJ)



CXXFLAGS= -std=c++11
GTKFLAGS= `pkg-config gtkmm-3.0 --cflags --libs`

ex: poker.cpp
	$(CXX) $(CXXFLAGS) poker.cpp $(GTKFLAGS)
	./a.out
clean:
	rm -rf *.o