#include "BST.h"

// BST.cpp
// constructors for BST class





template<typename k_t, typename v_t, typename OP> 
void bst<k_t, v_t, OP>::copy_rec(const std::unique_ptr<node> &x){	// accessory function for copy ctor
    if(x)
    {
        insert(x->pair);
        copy_rec(x->left);
        copy_rec(x->right);
    }
  }
  
  
  
  
// copy ctor
template<typename k_t, typename v_t, typename OP> 
bst<k_t, v_t, OP>::bst(const bst& x) {			
    
    std::cout << "copy ctor"<< std::endl;
    copy_rec(x.root);
    
  }





// copy assignment
template<typename k_t, typename v_t, typename OP> 
bst& bst<k_t, v_t, OP>::operator=(const bst& x) {	
    std::cout << "copy assignment"<< std::endl;
    root.reset();
    auto tmp = x; // copy ctor
    *this = std::move(tmp); // move assignment
    return *this;    
  }



template<typename k_t, typename v_t, typename OP> class bst<k_t, v_t, OP>::iterator bst<k_t, v_t, OP>::begin() noexcept {
   
    if(!root)
    {
      return iterator{nullptr};
    }
    node *tmp = root.get();
    while(tmp->left)
    {
        tmp = tmp->left.get();
    }
    return iterator{tmp};
     
}



template<typename k_t, typename v_t, typename OP> class bst<k_t, v_t, OP>::const_iterator bst<k_t, v_t, OP>::begin() const  noexcept {
 
    if(!root)
    {
      return const_iterator{ nullptr};
    }
    node *tmp = root.get();
    while(tmp->left)
    {
        tmp = tmp->left.get();
    }
    return const_iterator{tmp};
    
}


template<typename k_t, typename v_t, typename OP> class bst<k_t, v_t, OP>::const_iterator bst<k_t, v_t, OP>::cbegin() const  noexcept {  
   
    if(!root)
    {
      return const_iterator{nullptr};
    }
    node *tmp = root.get();
    while(tmp->left)
    {
        tmp = tmp->left.get();
    }
    return const_iterator{tmp};
     
}

template<typename k_t, typename v_t, typename OP> 
friend  
std::ostream& class bst<k_t, v_t, OP>::operator<<(std::ostream& os, const bst& x){
    
    for (const auto &el : x){
      
    os << el.first << " ";}
    
     
    os << std::endl;
    return os;


    
}


