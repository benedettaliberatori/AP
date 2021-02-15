#ifndef	__NODE_
#define __NODE_



/**
 * @file node.hpp
 * @authors Benedetta Liberatori, Ciro Antonio Mami, Davide Roznowicz
 * @brief Header for the class _node
 */


#include <memory> 
#include <utility> 


/**
 * @tparam N template standing for an object of class pair_type.
 */
template <typename N>
   struct _node{

       
	   /** @brief Unique ptr to the left node. */
        std::unique_ptr<_node> left;
        
        /** @brief Unique ptr to the right node. */
        std::unique_ptr<_node> right;
        
        /** @brief ptr to the parent node. */
        _node* parent = nullptr;
        
                
        /** @brief pair_type member. */
        N pair;

         /**
        * @brief Constructor for  _node.
        * @tparam p const lvalue.
        */
        explicit _node(const N& p): pair{p} {}
        
         /**
        * @brief Constructor for _node.
        * @tparam p rvalue reference.
        */
        explicit _node(N&& p) noexcept: pair{std::move(p)} {}

        /**
        * @brief Constructor for _node, called by the copy constructor of bst. 
        * It copies the pair from the given node, set the parent with the given raw pointer and recursively calls itself on the left and right children if present.
        * @tparam x Unique_ptr to node to be copied. 
        * @tparam p Raw ptr to the parent of the node to be constructed. 
        */
        _node(const std::unique_ptr<_node> &x, _node* p) :  parent{p}, pair{x->pair} {
	  if(x->left){left.reset(new _node{x->left, this});}
	  if(x->right){ right.reset(new _node{x->right, this});}
	  }

        /**
         * @brief Deconstructor.
         */

         ~_node() noexcept = default;
  
    
    };

#endif
