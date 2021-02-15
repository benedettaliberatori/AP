#include "BST.hpp"

#include <chrono>
#include <string>


using namespace std::chrono;


int main(){


    using k_type = const int;	    // set type of key
    using v_type = std::string;   // set type of value
    
    bst<k_type,v_type> tree{};
    std::string s = "ciao";
    std::pair<k_type,v_type> x{100,s};
    std::pair<k_type,v_type> k{8,"monte"};
    std::pair<k_type,v_type> z{9,s};
    std::pair<k_type,v_type> b{10,s};
    std::pair<k_type,v_type> g{12,s};
    std::pair<k_type,v_type> f{11,s};
    
    tree.insert(x);
    tree.insert(k);    
    tree.insert(z);
    tree.insert(b);

    tree.insert(f);
    std::cout << tree;
    tree.balance();
    
    std::cout << "Test of emplace\n";
    tree.emplace(5,s);
    int u=6;
    tree.emplace(u,s);
    std::cout << tree;

    std::cout << "Test of []\n";
    std::cout << tree[10] << std::endl;
    tree[10]="changed";
    std::cout << tree[10]<< std::endl;
    tree[10]=s;
    std::cout << tree[10]<< std::endl;
    
    

    // measure time of finding a key
    auto start = high_resolution_clock::now();
    for (int i=0; i<100; i++) {
        const int j = rand() % 100 + 1;
        std::pair<k_type,v_type> bb{j,s};
        tree.insert(bb);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>((stop - start)/1000);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    // end measure
    tree.balance();
    tree.find(123);
    
    
    bst<k_type,v_type> t{};   // custom ctor
    bst<k_type,v_type> p{tree};  // copy ctor - deepcopy
    std::cout << p;	  // print copied tree
    

    for(auto &el : p){

        tree.erase(el.first);
    }
    std::cout << "Tree after erasing\n";
    std::cout << tree;	

   


  
}
