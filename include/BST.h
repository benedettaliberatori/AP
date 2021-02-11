#include <iostream>
#include <memory> // std::unique_ptr
#include <utility> // std::move

#include "node.h"
#include "iterators.h"

template <typename k_t , typename v_t , typename OP = std::less<k_t> >
class bst{
public:
    using pair_type = std::pair<const k_t,v_t>;
    using node = _node<pair_type>;
    using iterator = _iterator<node, pair_type>;
    using const_iterator = _iterator<node, const pair_type>;
private:    
    std::unique_ptr<node> root;
    

public:
    bst() = default;
    ~bst() = default;
    OP op;
    //using iterator = _iterator<v_t>>;
    //using const_iterator = _iterator<const v_t>;


    

iterator begin() noexcept {
  
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
 
const_iterator begin() const noexcept {
   
  
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
   
const_iterator cbegin() const noexcept {
     
  
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
  
auto end() noexcept {
      return iterator{nullptr};
    }
auto end() const noexcept {
      return const_iterator{nullptr};}
auto cend() const noexcept {  
      return const_iterator{nullptr};
    }



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

   bst(const bst& x) {
    std::cout << "copy ctor"<< std::endl;
   
    copy_rec(x.root);
    
   }

  
    bst& operator=(const bst& x) {
        root.reset();
        auto tmp = x; // copy ctor
        *this = std::move(tmp); // move assignment
        return *this;    
    }
 template <typename O> std::pair<iterator,bool>   _insert(O&&x);                                                                                                                                                                                                       
                                                                                                                                                                                                            
  std::pair<iterator, bool> insert(const pair_type& x){ return _insert(x);}
  std::pair<iterator, bool> insert(pair_type&& x){ return _insert(std::move(x));}          

    void erase(const k_t& x);
    void _erase(iterator& x);
    void exchange(node* N1, node* N2);

    iterator find (const k_t& x);
    const_iterator find(const k_t& x) const;
    int height(std::unique_ptr<node>& x);
    std::pair<iterator, const bool> my_find(const k_t& x) const;
    int height(){return height(root);}
    void printBT(const std::string& prefix, std::unique_ptr<node>& x, bool isLeft)
{
    if( x)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << x->pair.first << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), x->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), x->right, false);
    }
}

void printBT()
{
    printBT("", root, false);    
}

// pass the root node of your binary tree

friend
std::ostream &operator<<(std::ostream& os, const bst& x){




 for (const auto &el : x){

      os << el.first << " " << std::endl;}


    os << std::endl;
    return os;

}

};