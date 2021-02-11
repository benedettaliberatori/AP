#include "BST.h"
#include "iterators.h"

#include <vector>
#include <algorithm>


// helper functions for BST class


// my_find
//template<typename k_t, typename v_t, typename OP> 
std::pair<class bst<k_t, v_t, OP>::iterator, const bool> bst<k_t, v_t, OP>::my_find(const k_t& x) const;


// find
//template<typename k_t, typename v_t, typename OP> 
class bst<k_t, v_t, OP>::iterator bst<k_t, v_t, OP>::find (const k_t& x);
//const std::pair<const_iterator, const bool> my_find(const k_t& x) const;

// find const
//template<typename k_t, typename v_t, typename OP> 
class bst<k_t, v_t, OP>::const_iterator bst<k_t, v_t, OP>::find (const k_t& x) const;


// _insert
//template<typename k_t, typename v_t, typename OP> template<typename O> 
std::pair<class bst<k_t, v_t, OP>::iterator,bool>  bst<k_t, v_t, OP>:: _insert(O&& x);
                                                                                                                                                                                                                                                                                                                                                                                                           
//template<typename k_t, typename v_t, typename OP> template<typename O> 
std::pair<class bst<k_t, v_t, OP>::iterator,bool>  bst<k_t, v_t, OP>::insert(const pair_type& x){ return _insert(x);}

//template<typename k_t, typename v_t, typename OP> template<typename O> 
std::pair<class bst<k_t, v_t, OP>::iterator,bool>  bst<k_t, v_t, OP>::insert(pair_type&& x){ return _insert(std::move(x));}          











