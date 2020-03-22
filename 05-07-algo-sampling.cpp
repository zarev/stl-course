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
  vector<int> i(10);
  iota(begin(i),end(i),0);

  string pop = "abcdefghijklmnopqrstuvwxyz";
  string select;

  mt19937 rng{random_device{}()};
  sample(begin(pop), end(pop),back_inserter<string>(select), 5, rng);

  cout << select << endl;
  
  return 0;
};