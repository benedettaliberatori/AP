# this is the Makefile



MAIN = main.x
CXX = c++
CXXFLAGS = -std=c++14 -Iinclude -Wall -Wextra


# eliminate default suffixes
.SUFFIXES:
SUFFIXES=

# just consider our own suffixes
.SUFFIXES: .cpp .x

all: $(MAIN)

.PHONY: all

documentation: Doxygen/doxy.in
	doxygen $^

$(MAIN): main.cpp 
	$(CXX) $^ -o $(MAIN) $(CXXFLAGS)

clean:
	rm -rf *.x

.PHONY: clean 









