#ifndef BST_TPP
#define BST_TPP
#include "BST.hpp"



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

template<typename k_t, typename v_t, typename OP> int bst<k_t, v_t, OP>::height(const std::unique_ptr<node>& x)  noexcept                                                    
                                                                                                                                                               
{                                                                                                                                                              
        if (!x) return 0;                                                                                                                                      
        return 1 + std::max(height(x->left) , height(x->right));                                                                                               
}                                                                                                                                                              
                                                                                                                                                               
                                                                                                                                                               
template<typename k_t, typename v_t, typename OP> bool bst<k_t, v_t, OP>::is_balanced(const std::unique_ptr<node>& x)  noexcept                                              
{                                                                                                                                                              
        if (!x)                                                                                                                                                
                return false;                                                                                                                                  
        int leftheight = height(x->left);                                                                                                                      
        int rightheight = height(x->right);                                                                                                                    
                                                                                                                                                               
        if (abs(leftheight - rightheight) > 1)                                                                                                                 
                return false;                                                                                                                                  
        return true;                                                                                                                                           
}

template<typename k_t, typename v_t, typename OP> void bst<k_t, v_t, OP>::_balance(std::vector<pair_type>& v, int begin, int end) {                             
                                                                                                                                                               
                                                                                                                                                               
    if(begin <end){                                                                                                                                            
    int m=(begin+end)*0.5;                                                                                                                                     
    insert(v[m]);                                                                                                                                              
    _balance(v, begin, m);                                                                                                                                     
    _balance(v, m+1, end);                                                                                                                                     
    }                                                                                                                                                          
    return;                                                                                                                                                    
                                                                                                                                                               
                                                                                                                                                               
                                                                                                                                                               
}


template<typename k_t, typename v_t, typename OP> void bst<k_t, v_t, OP>::balance() {                                                                           
    std::vector<pair_type> v;                                                                                                                                  
     for(const auto &el : *this){                                                                                                                              
    v.push_back(el);                                                                                                                                           
  }                                                                                                                                                            
                                                                                                                                                               
  clear();                                                                                                                                                     
  _balance(v, 0, v.size());}         


template<typename k_t, typename v_t, typename OP> template<typename O> 
std::pair<class bst<k_t, v_t, OP>::iterator,bool>  bst<k_t, v_t, OP>:: _insert(O&& x){  // input pair_type

      pair_type this_pair = std::forward<O>(x);   // pair to be added
      auto new_pair = my_find(this_pair.first);
      auto current= new_pair.first;
      const bool truth =new_pair.second;

	 
	 if (root.get()) {  // rt != nullptr
	 	if (truth==true) {
	 		return (std::pair<iterator,bool>(current,false));  // return 
	 	}
	 	else {  // truth==false : a new node has to be inserted
	 		if (op(this_pair.first, current->pair.first)) {   // insert on the left
	 			auto new_node = new node{this_pair};
	 			current->left.reset(new_node);  // old node points on the left to the new_node
	 			new_node->parent = current;
	 			return (std::pair<iterator,bool>(iterator{new_node}, true));
	 		}
	 		else {   // insert on the right
	 			auto new_node = new node{this_pair};
	 			current->right.reset(new_node);  // old node points on the right to the new_node
	 			new_node->parent = current;
	 			return (std::pair<iterator,bool>(iterator{new_node}, true));
	 		}
	 	}
	 }
	 
	 
	 else {  // rt==nullptr means rt==(ptr to root node)  ----->  insert a node exactly on root
	 	    root.reset(new node{this_pair});  // root is unique_ptr - root node created
		    return (std::pair<iterator,bool>(iterator{root.get()}, true));
	 }

}

template<typename k_t, typename v_t, typename OP> 
std::pair<class bst<k_t, v_t, OP>::node *, const bool> bst<k_t, v_t, OP>::my_find(const k_t& x) const{  // class bst< 

	auto tmp = root.get();
	auto my_key = x;
	
	while (tmp) {
	
		if (!op(my_key,tmp->pair.first) && !(op(tmp->pair.first, my_key))) {  // my_key==current_key
			
			return (std::pair<node*,bool>(tmp, true));
		}		
		else if (op(my_key,tmp->pair.first)){  // my_key<current_key
			if (tmp->left) {  // left != nullptr
				tmp=tmp->left.get();
			}
			else {
				return (std::pair<node*,bool>(tmp, false));	
			}
		}
		else if(op(tmp->pair.first,my_key)){  // my_key>current_key
			if (tmp->right) {  // right != nullptr
				tmp=tmp->right.get();
			}
			else {
				return (std::pair<node*,bool>(tmp, false));
					
			}	
		}
	}	
	return (std::pair<node*,bool>(tmp, false)); // iterator to root that is nullptr

}


// find
template<typename k_t, typename v_t, typename OP> 
class bst<k_t, v_t, OP>::iterator bst<k_t, v_t, OP>::find (const k_t& x){
	auto new_pair = my_find(x);

	auto current = new_pair.first;
	const bool truth =new_pair.second;
	if (truth==false){  // key not present
		return iterator{nullptr};  // iterator to end()
	}
	else {
			return iterator{current};	
    }
}


// const find
template<typename k_t, typename v_t, typename OP> 
class bst<k_t, v_t, OP>::const_iterator bst<k_t, v_t, OP>::find (const k_t& x) const{
	auto new_pair = my_find(x);
	auto current = new_pair.first;
	const bool truth =new_pair.second;
	if (truth==false){  // key not present
		return const_iterator{nullptr};  // iterator to end()
	}
	else {
			return const_iterator{current};	
    }
}

template<typename k_t, typename v_t, typename OP> void bst<k_t, v_t, OP>::exchange(node* N1, node* N2){
 auto tmp = new node{N2->pair};
 
  if(N1->left.get()) {
    N1->left->parent = tmp;
    tmp->left.reset(N1->left.release());
    }
    if(N1->right.get()){
     N1->right->parent = tmp;
     tmp->right.reset(N1->right.release());
    }
    
    
    
   if(N1->parent){
    tmp->parent = N1->parent;
    if(op(tmp->pair.first,N1->parent->pair.first)){

        N1->parent->left.reset(tmp);
       return;

    }
    else if(op(N1->parent->pair.first,tmp->pair.first)){

        N1->parent->right.reset(tmp);
        return;        

    }

   }
  
   if(N1->parent == nullptr) { root.reset(tmp);}
      
   
}


template<typename k_t, typename v_t, typename OP> void bst<k_t, v_t, OP>::erase(const k_t& x){


    auto tmp =my_find(x);
    
   if(tmp.second==true) _erase(tmp.first);
  


}
template<typename k_t, typename v_t, typename OP> void bst<k_t, v_t, OP>::_erase( node* x ){

if(height()==1) {root.reset(); return;}

  if(!(x->left) && !(x->right)) {
      if(x->parent->right.get()==x) {  x->parent->right.reset(); return;}
         
      else if(x->parent->left.get()==x) { x->parent->left.reset();return;}

   

    

    }
  else if (!(x->left) && x->right) {
  auto tmp = x->right.get(); 
    
    while(tmp->left) tmp = tmp->left.get();

    exchange(x,tmp);
    _erase(tmp);
    
   
  }

  
  else if (x->left.get() && !(x->right.get())) {
    auto tmp = x->left.get();
     while(tmp->right)tmp = tmp->right.get();


    exchange(x,tmp);

    _erase(tmp);
    
}

  else if(x->left && x->right) {
    auto tmp = x->right.get(); 
    
    while(tmp->left) tmp = tmp->left.get();

    exchange(x,tmp);

    _erase(tmp);
    
   
  
  }
}








template<typename k_t, typename v_t, typename OP> 
v_t& bst<k_t, v_t, OP>::operator[](const k_t& x){ 
                v_t v = {};   // if the key exists, then the value is not used; otherwise it is fixed as default value
                auto k = x;
                std::pair<iterator, bool> added_pair = insert(std::pair<k_t, v_t>(k,v));  
                return added_pair.first.getcurrent()->pair.second;
    
   }   
   

template<typename k_t, typename v_t, typename OP>
v_t& bst<k_t, v_t, OP>::operator[](k_t&& x){ 
                v_t v = {};   // if the key exists, then the value is not used; otherwise it is fixed as default value
                auto k = x;
                std::pair<iterator, bool> added_pair = insert(std::pair<k_t, v_t>(k,v));  
                return added_pair.first.getcurrent()->pair.second;
   }






#endif
