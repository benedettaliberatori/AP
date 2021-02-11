#include <memory> // std::unique_ptr
#include <utility> // std::move



template <typename N>
   struct _node{

       template <typename k_t, typename v_t, typename OP> friend class bst;

       template <typename I,typename O> friend class _iterator;
        std::unique_ptr<_node> left;
        std::unique_ptr<_node> right;
        _node* parent = nullptr;
        //using pair_type = std::pair<k_t, v_t>;
        using pair_type = N;
        pair_type pair;

        explicit _node(const pair_type& p): pair{p} {std::cout << "l-value\n";}
        

        explicit _node(pair_type&& p): pair{std::move(p)} {std::cout << "r-value" << std::endl;}

      
    
    };
