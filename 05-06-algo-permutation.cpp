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
  string vowels = "aeiou";
  string test = "iuoea";
  string test2 = "iuoe";

  cout << std::boolalpha;

  cout << is_permutation(begin(test), end(test), begin(vowels)) << endl;
  cout << is_permutation(begin(test2), end(test2), begin(vowels)) << endl;
  
  while(next_permutation(begin(vowels), end(vowels))){ cout << vowels << endl;}

  cout << vowels << endl;
  
  return 0;
};