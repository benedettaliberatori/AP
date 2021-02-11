#include "helper_functions.h"

// helper functions



// my_find
template<typename k_t, typename v_t, typename OP> 
std::pair<class bst<k_t, v_t, OP>::iterator, const bool> bst<k_t, v_t, OP>::my_find(const k_t& x) const{  // class bst< 

	auto tmp = root.get();
	auto my_key = x;
	
	while (tmp) {
	
		if (!op(my_key,tmp->pair.first) && !(op(tmp->pair.first, my_key))) {  // my_key==current_key
			std::cout << "same key - key = " << my_key << std::endl;
			return (std::pair<iterator,bool>(iterator{tmp}, true));
		}		
		else if (op(my_key,tmp->pair.first)){  // my_key<current_key
			if (tmp->left) {  // left != nullptr
				tmp=tmp->left.get();
			}
			else {
				return (std::pair<iterator,bool>(iterator{tmp}, false));	
			}
		}
		else if(op(tmp->pair.first,my_key)){  // my_key>current_key
			if (tmp->right) {  // right != nullptr
				tmp=tmp->right.get();
			}
			else {
				return (std::pair<iterator,bool>(iterator{tmp}, false));
					
			}	
		}
	}	
	std::cout << "root is nullptr - key =" << my_key << std::endl;
	return (std::pair<iterator,bool>(iterator{tmp}, false)); // iterator to root that is nullptr

}


// find
template<typename k_t, typename v_t, typename OP> 
class bst<k_t, v_t, OP>::iterator bst<k_t, v_t, OP>::find (const k_t& x){
	auto new_pair = my_find(x);
	auto iter = new_pair.first;
	auto current = iter.getcurrent();
	const bool truth =new_pair.second;
	if (truth==false){  // key not present
		std::cout << "NOT found element=" << x << std::endl;
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
	auto iter = new_pair.first;
	auto current = iter.getcurrents();
	const bool truth =new_pair.second;
	if (truth==false){  // key not present
		std::cout << "NOT found element=" << x << std::endl;
		return const_iterator{nullptr};  // iterator to end()
	}
	else {
			return const_iterator{current};	
    }
}




template<typename k_t, typename v_t, typename OP> template<typename O> 
std::pair<class bst<k_t, v_t, OP>::iterator,bool>  bst<k_t, v_t, OP>:: _insert(O&& x){  // input pair_type

      pair_type this_pair = std::forward<O>(x);   // pair to be added
      auto new_pair = my_find(this_pair.first);
      auto iter = new_pair.first;
      const bool truth =new_pair.second;
      auto current = iter.getcurrent();	// iter.nd() is ptr to current node
	 
	 if (root.get()) {  // rt != nullptr
	 	if (truth==true) {
	 		return (std::pair<iterator,bool>(iter,false));  // return 
	 	}
	 	else {  // truth==false : a new node has to be inserted
	 		if (op(this_pair.first, current->pair.first)) {   // insert on the left
	 			auto new_node = new node{this_pair};
	 			current->left.reset(new_node);  // old node points on the left to the new_node
	 			new_node->parent = current;
	 			return (std::pair<iterator,bool>(iterator{new_node}, true));
	 		}
	 		else if(op(current->pair.first,this_pair.first)) {   // insert on the right
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



