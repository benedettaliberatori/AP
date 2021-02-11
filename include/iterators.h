#include "BST.h"

#include <stack>
#include <iterator>
#include<utility> //pair
#include<memory>



template <typename k_t, typename v_t, typename OP> 
template <typename O> 
class bst<k_t, v_t, OP>::_iterator {
  using node = typename bst<k_t,v_t,OP>::node;
  node* current;
  
public:
  OP op;
  using pair_type = O;
  using reference = pair_type &;
  using pointer = pair_type *;


  //constructor

  explicit _iterator(node *p): current{p} {} 

  reference operator*() const { return current->pair; }
  pointer operator->() const { return &**this; }

  node* getcurrent() {return current;}
  
  // pre-increment
  _iterator &operator++();
  
  _iterator operator++(int);

  friend bool operator==(_iterator &a, _iterator &b) {return a.current == b.current;}

  friend bool operator!=(_iterator &a, _iterator &b) { return !(a == b); }
};






