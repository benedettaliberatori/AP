#include <iostream>
#include <memory> // std::unique_ptr
#include <utility> // std::move



template<typename k_t, typename v_t, typename OP=std::less<k_t>>
class bst{

	using pair_type = std::pair<const k_t, v_t>;

	struct node{
	std::unique_ptr<node> left;
	std::unique_ptr<node> right;
	pair_type pair;
	node* parent=nullptr;


	// custom ctor node starting from pair_type
	explicit node(const pair_type& p): pair{p} {}; //{std::cout << "l-value\n";}
	// custom ctor node starting from pair_type
	explicit node(pair_type&& p) : pair{std::move(p)} {}; //{std::cout << "r-value" << std::endl;}


	};


	std::unique_ptr<node> root;
	OP op;





public:

 
	bst() = default;                      // default ctor
	~bst() = default;                     // default dctor

	bst(bst &&) = default;                // default move ctor
	bst &operator=(bst &&) = default;     // default move assignment

 
	void copy_rec(const std::unique_ptr<node> &x);	// accessory function for copy ctor
	  

	bst(const bst& x);					// copy ctor 

	bst& operator=(const bst& x);			// copy assignment


	
	
	template <typename O> class _iterator;

	using iterator = _iterator< pair_type>;
	using const_iterator = _iterator< const pair_type>;



	iterator begin() noexcept;
	const_iterator begin() const noexcept; 
	const_iterator cbegin() const noexcept; 


	iterator end() noexcept {return iterator{nullptr};}
	const_iterator end() const noexcept {return const_iterator{nullptr};}
	const_iterator cend() const noexcept {return const_iterator{nullptr};}


	v_t& operator[](const k_t& x);
	v_t& operator[](k_t&& x);
	
	//friend
	template<typename k_t, typename v_t, typename OP>
	friend std::ostream& operator<<(std::ostream& os, const bst& x){ 
	    for (const auto &el : x){ os << el.first << " ";}
	    os << std::endl;
	    return os;
	}

};



