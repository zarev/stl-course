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
  cout << min("Hello", "world") << " is smaller" << endl;
  cout << min(45, 21) << " is smaller" << endl;

  cout << min("AAAA"s, "XX"s, [](string s1, string s2){return s1.size() < s2.size();}) << endl;

  vector<int> i(100);
  iota(begin(i),end(i),0);

  cout << *min_element(begin(i), end(i)) << endl;

  return 0;
};