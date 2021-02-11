#ifndef	__NODE_
#define __NODE_

#include <memory> 
#include <utility> 



template <typename N>
   struct _node{

       template <typename k_t, typename v_t, typename OP> friend class bst;

       template <typename I,typename O> friend class _iterator;
  
        std::unique_ptr<_node> left;
        std::unique_ptr<_node> right;
        _node* parent = nullptr;
        using pair_type = N;
        pair_type pair;

        explicit _node(const pair_type& p): pair{p} {}
        

        explicit _node(pair_type&& p): pair{std::move(p)} {}

      
    
    };

#endif
