#include<iostream>
#include<fstream>
#include<map> 
#include<unordered_map> 
#include<memory>
#include<utility>
#include<algorithm> 
#include<chrono>
#include<vector>
#include <numeric>


#include "BST.hpp"

int N=10000000;

template<class T>
void test(std::ofstream& file, T& B)
{

  for(int j=100000; j<N; j+=100000){  
  std::vector<float> times(10);
  std::vector<int> v(j);
  for(int i=0; i<j; ++i){
   
    v.push_back(rand()%j +1); }
    
  for(auto x : v){
    B.insert({x,x});
  }
      B.balance();
      int c=0;

      std::random_shuffle(v.begin(), v.end());
      for(int time=0; time <10; time++){
      auto begin =std::chrono::high_resolution_clock::now();
      for (int i=0u; i<v.size(); ++i){
 
        if(B.find(v[i])->first==v[i]){ c++;}
 
      }
      auto end = std::chrono::high_resolution_clock::now();
      auto total = std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count();
      times.push_back(total/(double)j);
      }
      double init = 0;
      float sum = std::accumulate(times.begin(),times.end(),init);

      file << "Mean:" << sum/(double)times.size() << "  Err:" << (*max_element(times.begin(),times.end())-*min_element(times.begin(),times.end()))/2 << "\n";
      std::cout << c << std::endl;
  }

}



int main(){

  
  bst<int,int> BST;
  

  std::map<int,int> M;
  std::unordered_map<int,int> UM;
  
  

  // std::ofstream myfile;
  // myfile.open("fileBST.txt");
  // myfile << "Writing this to a file.\n";
  // test(myfile, BST);
  // myfile.close();  
  
  // std::ofstream myfile2;
  // myfile2.open("fileM.txt");
  // myfile2 << "Writing this to a file.\n";
  // test(myfile2, BST);
  // myfile2.close();  
  
  

  // std::ofstream myfile3;
  // myfile3.open("fileUM.txt");
  // myfile3 << "Writing this to a file.\n";
  // test(myfile3, UM);
  // myfile3.close();


  
  

  


  //timings BST M UM


 
  
  std::ofstream myfile3;
  myfile3.open("fileBB.txt");
  myfile3 << "Writing this to a file.\n";
  test(myfile3, BST);
  myfile3.close();


  //timings balanced BST

  
  

  

  
  
  
 





}