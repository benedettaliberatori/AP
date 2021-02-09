#include <iostream>
#include <memory> // std::unique_ptr
#include <utility> // std::move
#include <stack>
#include <iterator>

template <typename k_t , typename v_t , typename OP = std::less<k_t> >
class bst{
    using pair_type = std::pair<const k_t, v_t>;
    struct node{
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;
        node* parent = nullptr;
        //using pair_type = std::pair<k_t, v_t>;
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
    

public:
    bst() = default;
    ~bst() = default;
    OP op;
    //using iterator = _iterator<v_t>>;
    //using const_iterator = _iterator<const v_t>;
  



    bst(bst&&) = default;
    bst& operator=(bst&&) = default;
  
    


  
    bst& operator=(const bst& x) {
        root.reset();
        auto tmp = x; // copy ctor
        *this = std::move(tmp); // move assignment
        return *this;    
    }




};


int main(){
    bst<const int,int> tree{};
  
    return 0;
}





