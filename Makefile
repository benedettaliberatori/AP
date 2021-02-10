# this is the Makefile


EXE = main.x
CXX = c++
CXXFLAGS = -I include -g -std=c++14 -Wall -Wextra -I.   # -I. look for including headers 

SRC= main.cpp src/BST.cpp src/iterators.cpp src/helper_functions.cpp
OBJ=$(SRC:.cpp=.o)
INC = include/BST.h  include/iterators.h  include/helper_functions.h

VPATH = .   # put headers in this folder

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cpp .o

all: $(EXE)

.PHONY: all

clean:
	rm -rf $(OBJ) $(EXE) src/*~ include/*~ *~ html latex

.PHONY: clean

%.o: %.cpp
		$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXE): $(OBJ)   
	$(CXX) $^ -o $(EXE)

documentation: README.md

.PHONY: documentation

main.o: include/BST.h include/helper_functions.h include/iterators.h

src/BST.o: include/BST.h

src/iterators.o: include/BST.h include/iterators.h
src/helper_functions.o: include/BST.h include/helper_functions.h









