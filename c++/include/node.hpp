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
        
        using pair_type = N;
        
        /** @brief pair_type member. */
        pair_type pair;

         /**
        * @brief Constructs a new _node.
        * @tparam p const lvalue.
        */
        explicit _node(const pair_type& p): pair{p} {}
        
         /**
        * @brief move constructor for _node.
        * @tparam p rvalue reference.
        */
        explicit _node(pair_type&& p): pair{std::move(p)} {}

      
    
    };

#endif
