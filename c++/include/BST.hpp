#ifndef BST_HPP_
#define BST_HPP_


/**
 * @file BST.hpp
 * @authors Benedetta Liberatori, Ciro Antonio Mami, Davide Roznowicz
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
    * @brief Utility function of \p insert() and \p emplace(). 
    * @tparam x<O> Forwarding reference to the type to be inserted, 
    * @return std::pair<iterator,bool> Iterator to the inserted node and true if not already present, iterator to the already present node and false otherwise. 
    */
    template <typename O> std::pair<iterator,bool>  _insert(O&&x);

    /**
    * @brief Utility function of \p balance(). 
    * @tparam v Vector of key-value pairs. 
    * @tparam begin Integer index to the first element.
    * @tparam end Iteger index to the last element.
    */
    void _balance(std::vector<pair_type>& v, int begin, int end);


    /**
    * @brief Utility function of \p is_balance(). 
    * @tparam x Unique pointer to the root of the tree to be checked.  
    * @return Boolean, true if balanced, false otherwise.
    */
    bool is_balanced (std::unique_ptr<node>& x) noexcept;

    /**
    * @brief Utility function of \p height(). 
    * @tparam x Unique pointer to the root of the tree to be checked.   
    * @return Integer for the height of the tree. 
    */
    int  height(std::unique_ptr<node>& x) noexcept;

     


    /**
    * @brief Utility function of \p find() and \p insert(). 
    * @tparam k_t Const lvalue reference to the key to look for. 
    * @return Pair of a raw pointer and a boolean. The pointer points to the node with the given key if already present or to the parent to which the node    * with the given key will be added otherwise. The boolean is true or false accordingly. 
    */
    std::pair<node *, const bool> my_find(const k_t& x) const;

    /**
    * @brief Utility function of \p erase(). 
    * @tparam x Raw pointer to the node to remove from the tree.
    */
    void _erase(node* x);

    /**
    * @brief Utility function of \p erase(). 
    * @tparam N1 Raw pointer to the node to be replaced.
    * @tparam N2 Raw pointer to the node to replace with.
    */
    void exchange(node* N1, node* N2);



    

  
public:

    /**
    * @brief Constructs a new bst.
    */
    bst() noexcept = default;

    /**
    * @brief Destroys the bst.
    */
    ~bst() noexcept = default;
   
    
    /**
    * @brief Move constructor.
    * @tparam rvalue reference to the tree to be moved.
    */
    bst(bst&&) noexcept = default;

    /**
    * @brief Move assignment.
    * @tparam rvalue reference to the tree to be moved.
    * @return Tree moved.
    */
    bst& operator=(bst&&) noexcept = default;
  
    /**
    * @brief Utility function of the copy constuctor. 
    * @tparam x Unique pointer to the root of the tree to be copied.  
    */
    void copy_rec(const std::unique_ptr<node> &x){
        if(x)
        {
            insert(x->pair);
            copy_rec(x->left);
            copy_rec(x->right);
        }
    }


   /**
    * @brief Copy constructor. Performes a deep copy of a bst tree.
    * @tparam b const lvalue reference to the tree to be copied.
    */
   bst(const bst& x) {copy_rec(x.root);}

    /**
    * @brief Copy assignment.
    * @tparam x const lvalue reference to the tree to be copied.
    * @return The copied tree.
    */
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
  void balance();
  
                                                                       
                                                                                
  /**
    * @brief Check if the tree is balanced or not. 
    * @return A boolean, true if balanced, false otherwise. 
    */
  bool is_balanced() noexcept {return is_balanced(root);}

  /**
    * @brief Compute the height of the tree, namely the max distance between the root and a leaf. 
    * @return An integer for the height.
    */
  int height() noexcept {return height(root);}          

  /**
    * @brief Inserts a new node with the given pair. Overloaded function which calls \p _insert().
    * @tparam x const lvalue reference to the pair to be inserted in the tree.
    * @return std::pair<iterator,bool> returned by _insert().
    */
  std::pair<iterator, bool> insert(const pair_type& x){ return _insert(x);}




   /**
    * @brief Inserts a new node with the given pair. Overloaded function which calls \p _insert().
    * @tparam x const rvalue reference to the pair to be inserted in the tree.
    * @return std::pair<iterator,bool> returned by _insert().
    */
  std::pair<iterator, bool> insert(pair_type&& x){ return _insert(std::move(x));}          
  

  /**
    * @brief Inserts a new node both with a std::pair <key,value> and with a key and a value. Overloaded function which calls \p _insert().
    * @tparam args a std::pair or key and value.
    * @return std::pair<iterator,bool> returned by _insert().
    */
  template< class... Types >
  std::pair<iterator,bool> emplace(Types&&... args){return _insert(pair_type(std::forward<Types>(args)...));}


  /**
    * @brief Removes the element, if one exist, with the key equivalent to key. 
    * @param k_t Key of the element to be deleted.
    */
  void erase(const k_t& x);
  
  
  /**
    * @brief Performs a search for a node in the tree, given a key.
    * @tparam x const lvalue reference to the key to look for.
    * @return Iterator pointing to the node containing the key or to nullptr if not found.
    */
  iterator find(const k_t& x);

  /**
    * @brief Performs a search for a node in the tree, given a key.
    * @tparam x const lvalue reference to the key to look for.
    * @return Const iterator pointing to the node containing the key or to nullptr if not found.
    */
  const_iterator find(const k_t& x) const;
 

 


  /**
    * @brief Friend operator that prints the tree in-order.
    * @param os output stream object.
    * @tparam x const lvalue reference to binary search tree.
    * @return std::ostream& output stream object.
    */
  friend
  std::ostream &operator<<(std::ostream& os, const bst& x) noexcept {

    for (const auto &el : x){
    	os << el.first << " " << std::endl;}

    os << std::endl;
    return os;

}




   /**
    * @brief Looks for a key and returns the corresponding value if it is present, inserts a node with that key and a default value otherwise.
    * @tparam x const lvalue reference to key.
    * @return v_t& value of the node with the corresponding key.
    */
   v_t& operator[](k_t&& x);

   /**
    * @brief Looks for a key and returns the corresponding value if it is present, inserts a node with that key and a default value otherwise.
    * @tparam x const rvalue reference to key.
    * @return v_t& value of the node with the corresponding key.
    */
   v_t& operator[](const k_t& x);





};

#endif
#include "BST.tpp"
