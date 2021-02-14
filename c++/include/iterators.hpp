#ifndef __ITERATORS_
#define __ITERATORS_


/**
 * @file iterators.hpp
 * @authors Benedetta Liberatori, Ciro Antonio Mami, Davide Roznowicz
 * @brief Header for the class _iterator
 */



#include <stack>
#include <iterator>
#include <utility> //pair
#include <memory>

#include "node.hpp"


/**
 * @tparam N template standing for an object of struct node.
 * @tparam O template standing for an object of class pair_type.
 */
template <typename N,typename O> 
class _iterator {

  using node = N;
  /** @brief ptr to the current node. */
  node* current;
  
public:

  using pair_type = O;
  using reference = pair_type &;
  using pointer = pair_type *;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;

  
   /**
  * @brief Constructs a new iterator.
  * @tparam p ptr to node.
  */
  explicit _iterator(node *p): current{p} {} 

  /**
    * @brief overloading operator for dereferencing iterator.
    * @return reference to pair_type
    */
  reference operator*() const noexcept { return current->pair; }
  
  /**
    * @brief overloading operator for referencing iterator.
    * @return ptr to pair_type
    */
  pointer operator->() const noexcept { return &**this; }


  /**
    * @brief returns the ptr to current node.
    * @return ptr to current node.
    */
  node* getcurrent() noexcept {return current;}
  

       /**
    * @brief overloading operator ++ | pre-increment for the iterator: allows to move forward from begin() to end().
    * @return reference to iterator
    */
  _iterator &operator++()  {
   if (current != nullptr){
     
   if (current->right.get() != NULL)
   {
      current = current->right.get();

      while (current->left.get() != NULL){
      
      current = current->left.get();}
       }
    else{
        node* tmp = current->parent;

        while(tmp && current != tmp->left.get()){
            current = tmp;
            tmp = tmp->parent;
        }

        current = tmp;
    

    }
    }

    return *this;
    
  }
  
  
  
         /**
    * @brief overloading operator ++ | post-increment for the iterator: allows to move forward from begin() to end().
    * @return reference to iterator
    */
  _iterator operator++(int) {
  auto tmp{*this};
  ++(*this);
  return tmp;
  }


	  /**
	* @brief overloading operator == | friend which allows the comparison of the iterators.
	* @return bool
	*/
  friend bool operator==(_iterator &a, _iterator &b) noexcept {
    return a.current == b.current;
  }



	  /**
	* @brief overloading operator != | opposite of operator ==.
	* @return bool
	*/
  friend bool operator!=(_iterator &a, _iterator &b) noexcept { return !(a == b); }



};
  
#endif
