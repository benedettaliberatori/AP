#ifndef BST_HPP_
#define BST_HPP_

#include <iostream>
#include <memory> // std::unique_ptr
#include <utility> // std::move
#include <vector>
#include "node.hpp"
#include "iterators.hpp"

template <typename k_t , typename v_t , typename OP = std::less<k_t> >
class bst{
public:
    using pair_type = std::pair<const k_t,v_t>;
    using node = _node<pair_type>;
    using iterator = _iterator<node, pair_type>;
    using const_iterator = _iterator<node, const pair_type>;
  
private:    
    std::unique_ptr<node> root;
    OP op;
    template <typename O> std::pair<iterator,bool>   _insert(O&&x); 

public:
    bst() = default;
    ~bst() = default;
   
    

    bst(bst&&) = default;
    bst& operator=(bst&&) = default;
  
    
    void copy_rec(const std::unique_ptr<node> &x){
        if(x)
        {
            insert(x->pair);
            copy_rec(x->left);
            copy_rec(x->right);
        }
    }

   bst(const bst& x) {copy_rec(x.root);}
  
    bst& operator=(const bst& x) {
        root.reset();
        auto tmp = x; // copy ctor
        *this = std::move(tmp); // move assignment
        return *this;    
    }



  iterator begin() noexcept; 
  const_iterator begin() const noexcept; 
  const_iterator cbegin() const noexcept;
  
  
  iterator end() noexcept { return iterator{nullptr};}
  const_iterator end() const noexcept { return const_iterator{nullptr};}
  const_iterator cend() const noexcept {return const_iterator{nullptr};}
    
  void clear(){root.reset(); return;}   
  void balance();                                                               
  void _balance(std::vector<pair_type>& v, int begin, int end);

  bool is_balanced(std::unique_ptr<node>& x);                                  
  int  height(std::unique_ptr<node>& x);                                       
                                                                                
                                                                                
                                                                                
   bool is_balanced(){return is_balanced(root);}                                
   int height(){return height(root);}          
  
  std::pair<iterator, bool> insert(const pair_type& x){ return _insert(x);}
  std::pair<iterator, bool> insert(pair_type&& x){ return _insert(std::move(x));}          

    void erase(const k_t& x);
    void _erase(iterator& x);
    void exchange(node* N1, node* N2);

  template< class... Types >  std::pair<iterator,bool> emplace(Types&&... args);    

    iterator find (const k_t& x);
    const_iterator find(const k_t& x) const;
    
    std::pair<iterator, const bool> my_find(const k_t& x) const;
    
    



friend
std::ostream &operator<<(std::ostream& os, const bst& x){

 for (const auto &el : x){

      os << el.first << " " << std::endl;}


    os << std::endl;
    return os;

}

};

#endif
#include "BST.tpp"
