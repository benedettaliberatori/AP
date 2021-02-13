#ifndef BST_HPP_
#define BST_HPP_


/**
 * @file BST.hpp
 * @authors Benedeta Liberatori, Ciro Antonio Mami, Davide Roznowicz
 * @brief Header containing members and method names for a class implementing a Binary Search Tree
 */

#include <iostream>
#include <memory> // std::unique_ptr
#include <utility> // std::move
#include <vector>
#include "node.hpp"
#include "iterators.hpp"

/**
 * @tparam k_t Type of node keys.
 * @tparam v_t Type of node values.
 * @tparam OP Type of the comparison operator. Default is std::less<k_t>.
 */
template <typename k_t , typename v_t , typename OP = std::less<k_t> >
class bst{
public:
    using pair_type = std::pair<const k_t,v_t>;
    using node = _node<pair_type>;
    using iterator = _iterator<node, pair_type>;
    using const_iterator = _iterator<node, const pair_type>;
  
private:

    /** @brief Unique pointer to the root node. */
    std::unique_ptr<node> root;
  
    /** @brief Comparison operator. */
    OP op;

    /**
    * @brief Utility function of \p insert(). 
    * @tparam x<O> Pair to be inserted, forwarding reference.
    * @return std::pair<iterator,bool> Iterator to the inserted node and true if not already present, iterator to the already present node and false otherwise. 
    */
    template <typename O> std::pair<iterator,bool>   _insert(O&&x);

    /**
    * @brief Utility function of \p balance(). 
    * @param v Vector of key-value pairs. 
    * @param begin Iterator to the left-most node.
    * @param end Iterator to one-past the last node.
    */
    void _balance(std::vector<pair_type>& v, int begin, int end) noexcept;

    bool is_balanced (std::unique_ptr<node>& x) noexcept;                                  
    int  height(std::unique_ptr<node>& x) noexcept;

    void print_structure(const std::string& prefix, std::unique_ptr<node>& x, bool isleft) noexcept;

    std::pair<node *, const bool> my_find(const k_t& x) const;

    void _erase(node* x);
    void exchange(node* N1, node* N2);



    

  
public:
    bst() noexcept = default;
    ~bst() noexcept = default;
   
    

    bst(bst&&) noexcept = default;
    bst& operator=(bst&&) noexcept = default;
  
    
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
        auto tmp = x; 
        *this = std::move(tmp); 
        return *this;    
    }


  /**
   * @brief Used to iterate over the binary search tree.
   * @return Iterator to the leftmost node of the tree. 
   */
  iterator begin() noexcept;

  /**
   * @brief Used to iterate over the binary search tree.
   * @return Const iterator to the leftmost node of the tree. 
   */
  const_iterator begin() const noexcept;

  /**
   * @brief Used to iterate over the binary search tree.
   * @return Const iterator to the leftmost node of the tree. 
   */
  const_iterator cbegin() const noexcept;
  
  /**
   * @brief Used to iterate over the binary search tree.
   * @return Iterator to one-past the last node of the tree. 
   */
  iterator end() noexcept { return iterator{nullptr};}

  /**
   * @brief Used to iterate over the binary search tree.
   * @return Const iterator to one-past the last node of the tree. 
   */
  const_iterator end() const noexcept { return const_iterator{nullptr};}

  /**
   * @brief Used to iterate over the binary search tree.
   * @return Const terator to one-past the last node of the tree. 
   */
  const_iterator cend() const noexcept {return const_iterator{nullptr};}

  /**
   * @brief Clears the content of the binary search tree.
   */
  void clear() noexcept {root.reset(); return;}


  /**
   * @brief Balances the tree.
   */
  void balance() noexcept;
  
  

                                       
                                                                                
                                                                                
                                                                                
  bool is_balanced() noexcept {return is_balanced(root);}                                
  int height() noexcept {return height(root);}          
  
  std::pair<iterator, bool> insert(const pair_type& x){ return _insert(x);}
  std::pair<iterator, bool> insert(pair_type&& x){ return _insert(std::move(x));}          
  
  template< class... Types >
  std::pair<iterator,bool> emplace(Types&&... args){return insert(pair_type(std::forward<Types>(args)...));}

  void erase(const k_t& x);
  
  

  iterator find (const k_t& x);
  const_iterator find(const k_t& x) const;
 
    
  

  
  void print_structure() noexcept{ print_structure("", root, false); return;}



friend
std::ostream &operator<<(std::ostream& os, const bst& x) noexcept {

    for (const auto &el : x){
    	os << el.first << " " << std::endl;}

    os << std::endl;
    return os;

}





v_t& operator[](k_t&& x);
v_t& operator[](const k_t& x);





};

#endif
#include "BST.tpp"
