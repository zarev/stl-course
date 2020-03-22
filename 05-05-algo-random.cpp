#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>
#include <random>

using namespace std; 

int main(){
  mt19937 rng1(100);
  mt19937 rng2(100);

  for(int i = 0; i < 10; ++i){
    cout << "RNG1: " << rng1() << ", ";
    cout << "RNG2: " << rng2() << ", ";
    cout << endl;
    
  }
  
  cout << endl;

  rng1.seed(random_device{}());
  rng2.seed(random_device{}());

 for(int i = 0; i < 10; ++i){
    cout << "RNG1: " << rng1() << ", ";
    cout << "RNG2: " << rng2() << ", ";
    cout << endl;
    
  }  
  
  vector<int> i(10);
  iota(begin(i),end(i),0);

  for_each(begin(i),end(i), [](int i){cout << i << " ";}); cout << endl;

  shuffle(begin(i), end(i), rng1);

  for_each(begin(i),end(i), [](int i){cout << i << " ";}); cout << endl;

  
  return 0;
};