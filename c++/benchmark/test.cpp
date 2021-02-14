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
#include <iomanip>
#include <math.h>

#include "BST.hpp"

int N=10000000;


double calculateSD(std::vector<float> v, double mean)
{
  double sd=0;
    for(int i = 0; i < 10; ++i)
      sd += pow(v[i] - mean, 2);

    return sqrt(sd /(v.size()-1));
}

template<class T>
void test(std::ofstream& file, T& B, bool b=false)
{
   for(int k=1; k<10; k++){
  for(int kk=100; kk<N; kk*=10){
    int j=kk*k;
    file<<j<<",";
  }
   }
   file<<"\n";
  for(int time=0; time <3; time++){
  for(int k=1; k<10; k++){
  for(int kk=100; kk<N; kk*=10){
    int j=kk*k;

  std::vector<int> v(j);
  for(int i=0; i<j; ++i){
   
    v.push_back(rand()%j +1); }
    
  for(auto x : v){
    B.insert({x,x});
  }
      if(b==true) B.balance();

      int c = 0;
      std::random_shuffle(v.begin(), v.end());
      
      
      auto begin =std::chrono::high_resolution_clock::now();
      for (int i=0; i<j; ++i){
 
        if(B.find(v[i])->first==v[i]){ c++;}
 
      }
      std::cout << c << std::endl;
      auto end = std::chrono::high_resolution_clock::now();
      auto total = std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count();
      auto x = total/(double)j;
      file << x << ",";
      // double init = 0;
      // double sum = std::accumulate(times.begin(),times.end(), init);
      // double mean= sum*0.1;
      // double sq_sum = std::inner_product(times.begin(), times.end(), times.begin(), 0.0);
      // double stdev = std::sqrt(sq_sum / times.size() - mean * mean);
      // double stdev2=calculateSD(times, mean);    
      
      // file <<j<<"\t Mean:" << mean << "  SD:" << stdev  <<"\t SD2" << stdev2<< "\n";
      //std::cout << j << std::endl;
    
      
  }

}
file<<"\n";
  }
  return;
}

template<class T>
void testUM(std::ofstream& file, T& B, bool b=false)
{
   for(int k=1; k<10; k++){
  for(int kk=100; kk<N; kk*=10){
    int j=kk*k;
    file<<j<<",";
  }
   }
   file<<"\n";
  for(int time=0; time <3; time++){
  for(int k=1; k<10; k++){
  for(int kk=100; kk<N; kk*=10){
    int j=kk*k;

  std::vector<int> v(j);
  for(int i=0; i<j; ++i){
   
    v.push_back(rand()%j +1); }
    
  for(auto x : v){
    B.insert({x,x});
  }
      if(b==true) B.balance();

      int c = 0;
      std::random_shuffle(v.begin(), v.end());
      
      
      auto begin =std::chrono::high_resolution_clock::now();
      for (int i=0; i<j; ++i){
 
        if(B.find(v[i])->first==v[i]){ c++;}
 
      }
      std::cout << c << std::endl;
      auto end = std::chrono::high_resolution_clock::now();
      auto total = std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count();
      auto x = total/(double)j;
      file << x << ",";
      // double init = 0;
      // double sum = std::accumulate(times.begin(),times.end(), init);
      // double mean= sum*0.1;
      // double sq_sum = std::inner_product(times.begin(), times.end(), times.begin(), 0.0);
      // double stdev = std::sqrt(sq_sum / times.size() - mean * mean);
      // double stdev2=calculateSD(times, mean);    
      
      // file <<j<<"\t Mean:" << mean << "  SD:" << stdev  <<"\t SD2" << stdev2<< "\n";
      //std::cout << j << std::endl;
    
      
  }

}
file<<"\n";
  }
  return;
}

int main(){

  
  bst<int,int> BST;
  std::map<int,int> M;
  std::unordered_map<int,int> UM;
  
  
  
  std::ofstream myfile;
  myfile.open("fileBST.csv");
  myfile << "Writing this to a file.\n";
  test(myfile, BST);
  myfile.close();  
  
  std::ofstream myfile2;
  myfile2.open("fileM.csv");
  myfile2 << "Writing this to a file.\n";
  test(myfile2, BST);
  myfile2.close();  
  
  

  std::ofstream myfile3;
  myfile3.open("fileUM.csv");
  myfile3 << "Writing this to a file.\n";
  testUM(myfile3, UM,false);
  myfile3.close();


  
  
  std::ofstream myfile4;
  myfile4.open("fileBB.csv");
  myfile4 << "Writing this to a file.\n";
  test(myfile4, BST, true);
  myfile4.close();


  

  
  

  

  
  
  
 





}
