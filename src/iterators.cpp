#include "iterators.h"


// iterators.cpp

	


// ++ overloading ---> pre-increment
template <typename k_t, typename v_t, typename OP> 
_iterator class bst<k_t, v_t, OP>::&operator++() {
   if (current != nullptr){
     
	   if (current->right.get() != NULL)
	   {
		 current = current->right.get();
		 while (current->left.get() != NULL){
		 	current = current->left.get();}
	   }
	   else{
		   node* tmp = current->parent;

		   while(tmp && current != tmp->left.get()){
		       current = tmp;
		       tmp = tmp->parent;
	   	   }

	   	   current = tmp;
	    
	   }
   }

   return *this;
    
}
  
  
  
// ++ overloading
template <typename k_t, typename v_t, typename OP>   
_iterator class bst<k_t, v_t, OP>::operator++(int) {
	  auto tmp{*this};
	  ++(*this);
	  return tmp;
}




