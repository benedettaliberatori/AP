#include <iostream>
#include <memory> // std::unique_ptr
#include <utility> // std::move
#include <stack>
#include <iterator>
#include <algorithm>
#include <vector>

template <typename k_t , typename v_t , typename OP = std::less<k_t> >
class bst{
    using pair_type = std::pair<const k_t, v_t>;
    struct node{
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;
        node* parent = nullptr;
        pair_type pair;

        explicit node(const pair_type& p): pair{p} {std::cout << "l-value\n";}
        

        explicit node(pair_type&& p): pair{std::move(p)} {std::cout << "r-value" << std::endl;}

        explicit node(const std::unique_ptr<node>& x): pair{x->pair}{
        
        if(x->right)
	        right.reset(new node{x->right});
        if(x->left)
	        left.reset(new node{x->left});
            std::cout << "copy" << std::endl;
    }
    
    };
    
    std::unique_ptr<node> root;
    OP op;

public:
    bst() = default;
    ~bst() = default;
   
    



    bst(bst&&) = default;
    bst& operator=(bst&&) = default;
  
    


  
    bst& operator=(const bst& x) {
        root.reset();
        auto tmp = x; // copy ctor
        *this = std::move(tmp); // move assignment
        return *this;    
    }



     void copy_rec(const std::unique_ptr<node> &x){
    if(x)
    {
        insert(x->pair);
        copy_rec(x->left);
        copy_rec(x->right);
    }
  }

    bst(const bst& x) {
    
    copy_rec(x.root);
    
    }


   template <typename O> class _iterator;

   using iterator = _iterator< pair_type>;
   using const_iterator = _iterator< const pair_type>;


   iterator begin() noexcept;
   const_iterator begin() const noexcept; 
   const_iterator cbegin() const noexcept; 
  

   iterator end() noexcept { return iterator{nullptr};}
   const_iterator end() const noexcept { return const_iterator{nullptr};}
   const_iterator cend() const noexcept {return const_iterator{nullptr};}

   void clear(){root.reset(); return;}

   void balance();
   void _balance(std::vector<pair_type>& v, int begin, int end);

};








