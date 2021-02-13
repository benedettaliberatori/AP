# Binary Search Tree

Advanced Programming - 2020/2021

Benedetta Liberatori - Ciro Antonio Mami - Davide Roznowicz


## Repo Structure

The repository contains the following:

* `include` : contains the headers: BST.hpp (declaration of the fundamental members of the class BST, together with the constructors and the copy/move semantics as well as declaration of the member functions); BST.tpp (definition of the templated functions for the class BST); iterators.hpp (implementation of the class iterator); node.hpp (implementation of the class node).

* `benchmark.cpp`: contains the code used to perform the benchmarking, whose results are presented in the final part of the report.

* `main.cpp`: main

* `Doxygen`: contains the Doxygen documentation (html and latex)

* `Makefile`: is used to compile the main.cpp (command: make main.x) and generate the Doxygen documentation (command: make dox). By typing make, both the main.x and the documentation are generated.

* `Report.md`: contains a detailed characterization of the classes/structures and most relevant functions. Some final charts illustrate some benchmarking for finding a key, both using our own classes/functions and built-in classes such as maps.
