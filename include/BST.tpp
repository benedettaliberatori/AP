#ifndef BST_TPP
#define BST_TPP



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

template<typename k_t, typename v_t, typename OP> int bst<k_t, v_t, OP>::height(std::unique_ptr<node>& x)                                                      
                                                                                                                                                               
{                                                                                                                                                              
        if (!x) return 0;                                                                                                                                      
        return 1 + std::max(height(x->left) , height(x->right));                                                                                               
}                                                                                                                                                              
                                                                                                                                                               
                                                                                                                                                               
template<typename k_t, typename v_t, typename OP> bool bst<k_t, v_t, OP>::is_balanced(std::unique_ptr<node>& x)                                                
{                                                                                                                                                              
        if (!x)                                                                                                                                                
                return false;                                                                                                                                  
        int leftheight = height(x->left);                                                                                                                      
        int rightheight = height(x->right);                                                                                                                    
                                                                                                                                                               
        if (abs(leftheight - rightheight) > 1)                                                                                                                 
                return false;                                                                                                                                  
        return true;                                                                                                                                           
}

template<typename k_t, typename v_t, typename OP> void bst<k_t, v_t, OP>::_balance(std::vector<pair_type>& v, int begin, int end){                             
                                                                                                                                                               
                                                                                                                                                               
    if(begin <end){                                                                                                                                            
    int m=(begin+end)*0.5;                                                                                                                                     
    insert(v[m]);                                                                                                                                              
    _balance(v, begin, m);                                                                                                                                     
    _balance(v, m+1, end);                                                                                                                                     
    }                                                                                                                                                          
    return;                                                                                                                                                    
                                                                                                                                                               
                                                                                                                                                               
                                                                                                                                                               
}


template<typename k_t, typename v_t, typename OP> void bst<k_t, v_t, OP>::balance(){                                                                           
    std::vector<pair_type> v;                                                                                                                                  
     for(const auto &el : *this){                                                                                                                              
    v.push_back(el);                                                                                                                                           
  }                                                                                                                                                            
                                                                                                                                                               
  clear();                                                                                                                                                     
  _balance(v, 0, v.size());}         


#endif
#include "BST.hpp"