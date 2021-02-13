# this is the Makefile
#
# possible calls: 			make main.x	----> compiles main.cpp into main.x using the headers in include
#						make dox		----> compiles the docs with doxygen
#						make			----> compiles everything (.cpp targets and doxy)
#						make clean	----> cleans it all (both generated executables & doxygen-generated files)





MAIN = main.x
CXX = c++
CXXFLAGS = -std=c++14 -Iinclude -Wall -Wextra


# eliminate default suffixes
.SUFFIXES:
SUFFIXES=

# just consider our own suffixes
.SUFFIXES: .cpp .x



all: $(MAIN) dox

.PHONY: all



dox: Doxygen/doxy.in
	doxygen $^

.PHONY: dox	

	

$(MAIN): main.cpp 
	$(CXX) $^ -o $(MAIN) $(CXXFLAGS)

clean:
	rm -rf *.x html latex

.PHONY: clean 









