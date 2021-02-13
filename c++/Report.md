## Binary Search Tree

The purpose of this project is the implementation of a templated binary search tree using modern C++14.
The performance of the container has been compared against the one of other built-in containers in the Standard Template Library. 


## General Structure


The `bst` class is templated on the types of the key, value and comparison operator. It has two private members: a unique pointer to an object of type _node **root** and a comparison operator **op**.

The `_node` struct is templated on the type of the pair stored in the node. Since the default visibility of a struct is public, all the members and methods are public for the tree to use. It has four members: a unique pointer to the **left** child, a unique pointer to the **right** child, a raw pointer to the **parent** and the key-value **pair** stored. This struct is implemented outside the bst class, since it does not need the template on the comparison operator. 

Then we provided our container with a class `_iterator`, in order to sequentially access the elements, without exposing its underlying representation. In particular it implements a forward iterator. This class is templated on the type of the node and the type of the pair stored in the node, in order to define both *iterator* and *const_iterator*. This class is implemented outside the bst class, being templated on different types. It has one private member: a raw pointer to a node, named **current**.


