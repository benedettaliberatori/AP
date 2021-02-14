## Binary Search Tree

The purpose of this project is the implementation of a templated binary search tree using modern C++14.
The performance of the container has been compared against the one of other built-in containers in the Standard Template Library. 


## General Structure


Three classes are implemented:

* `bst<k_t, v_t, OP>`: a templated Binary Search Tree; `k_t` is the key type - `v_t` is the value type - OP corresponds to std::less<k_t>, an object which implements a templated comparison operation among the keys. The class features two members: `root` (a `std::unique_ptr` pointing to the root node of the tree) and `op`, an OP object.

* `_node<N>`: a struct templated on `N`, the type of the pair stored in the node (in our case std::pair<const k_t, v_t>). The members are and three pointers: `left` and `right` (`std::unique_ptr` to left and right children nodes respectively), and `parent` (raw pointer pointing to the parent node), and the `pair` stored. 

* `_iterator<N, O>`: a templated class whose only private member is `current`, a raw pointer to the current node of type `N`. The second template argument `O` is the type of the pair stored in the node, in order to define both `iterator` and `const_iterator`. 

Since the default visibility of a struct is public, all the members and methods of `_node<N>` are public for the bst class to use. The struct is kept outside the class bst as it does not need to be templated on the comparison operator.
The class `_iterator` provides a way to sequentially access the elements of our container, without exposing its underlying representation. In particular it implements a forward iterator. Bbeing templated on different types, it is implemented outside the bst class. 

## Constructors & Member Functions


The `_node<N>` struct relies on a default decontructor and two constructors, one which takes a const lvalue reference to N and one which takes a rvalue reference to N. Both constructs the new node with the pair given and set parent, left and right to `nullptr`. 

The `_iterator<N, O>` class relies on a constructor which initializes the raw pointer to the current node with the given one and a default deconstructor. Furthermore it has:
* `dereference operator*()` which returns a reference to the pair stored in the current node.
* `reference operator->()`.
*  function `getcurrent()` which returns  a  raw pointer to the current node, making it possible to access this private member.
* `pre-increment &operator++()`  and `post-increment operator++(int)` which allows to traverse the tree in-order.
* boolean `operator==` and `operator!=` for comparisons.

The `bst<k_t, v_t, OP>` class has default constructors and deconstructors, default move semantic and custom copy semantic in order to perform a deep copy of a bst object.

Broadly speaking it has:
* Functions implemented in the *public* part.
* Utility functions of the latter, implemented in the *private* part  since do not need to be accessible from outside. 
* *Operators*.



#### my_find
```
//private
std::pair<node *, const bool> my_find(const k_t& x) const;

```
my_find is an utility private function whose main goal is to ease the the work done by `find` and `insert`. It returns a pair of an pointer to node and a boolean: if the key specified as input is present in the tree, then the pointer to the found node is returned and the boolean variable is set to true; instead, if the key is not found, then a pointer to the parent node is returned together with a false statement.


#### insert
```
//private
template <typename O> 
std::pair<iterator,bool>  _insert(O&&x);

//public
std::pair<iterator, bool> insert(const pair_type& x){ return _insert(x);}
std::pair<iterator, bool> insert(pair_type&& x){ return _insert(std::move(x));} 

```
`insert` allows the user to insert a new node in the tree, by giving a const lvalue or a rvalue reference to the pair as input. In order to make the code more clear, both the versions for `insert` invoked `_insert`, a private function in which `forward<O>` is called to allow for the usage of lvalue or rvalue reference according to the needs of the function. `insert` exploits `my_find` to look for the key and insert it, whether it is not already in the tree: in this case it returns a pair of an iterator to the node and a bool evaluated to true. In the case in which the key was already present, then an iterator to the node of the retrieved key is returned together with a the boolean value set to false.

#### find
```
//public
iterator find(const k_t& x);
const_iterator find(const k_t& x) const;

```
`find` searches for the key in the tree and two versions of this function are implemented, returning an iterator (or const_iterator) to the proper node if the key is already present; end() iterator (or const_iterator) otherwise.


#### Subscripting operator []
```
//public
v_t& operator[](k_t&& x);
v_t& operator[](const k_t& x);

```

the `subscripting operator []` is an overloading operator which, given a key in input (in form of rvalue reference or const lvalue), returns a reference to the associated value if the key was already present in the tree; otherwise, the key is inserted and the associated value is a default one (obtained writing v_t v = {}). 


#### emplace
```
//public
template< class... Types >
std::pair<iterator,bool> emplace(Types&&... args)
  
```

`emplace` calls `_insert` by giving in input a `forward<O>` construct, which allows flexibility in  taking const lvalue or rvalue references as inputs. Therefore it behaves like `insert` itself: the only difference is that it uses a variadic template, requesting in input two args (key and value). It returns a pair of an iterator to the added node if the key was not present before, together with a true statement; instead, if the key was already present, then an iterator to the already present node is returned, and the boolean value is false.



#### exchange
```
//private
void exchange(node* N1, node* N2)

```

The function is used to support the erase function, basically it takes two raw ptr to node which have to be exchanged, the most simple way to do this that came to us has been to create a new node with the samep pair of N2 (the node to be copied) and then exchanging it with N1, exchanging parent and left and right node. The usage of smart pointers allow us to be sure that everything will be done with no memory leaks.

#### _erase
```
//private
void _erase(node* x);

```
`_erase` is the heart of the erasing of a node, the function is recursive and take as input a ptr to the node to be erased, the case zero is the one in which the node to be erased has no child, in this case, we simply delete it by the resetting of the left/right ptr of his parent. The other cases are the ones in which the node to be deleted has only left child, only right child, or both child: in the first case we exchange the node to be erased with the node which has the biggest key smaller than the one to be erased, in the two other cases we exchange with the smallest key which is bigger than the one to be erased. The last control is if the height of the tree of the node to be erased is 1 one (so we are deleting the last node of the tree), where we simly reset the root, deleting the tree.


#### erase
```
//public
void erase(const k_t& x);

```

The function erase the node which has as key the one passed in input, it call the function my_find to find the ptr to that node, and if that key is present in the tree it pass the ptr to the `_erase` function.

















