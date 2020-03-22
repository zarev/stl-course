#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

/*
-swap works on single elements
-swap ranges is also a thing, for more values
-iter_swap between 2 swappable elements
*/

int main(){
  int a = 10, b = 30;

  cout << a << " " << b << endl;

  swap(a,b); 

  cout << a << " " << b << endl;
  
  vector<string> s1 {"a", "b", "c", "d", "e", "f", "g"};
  vector<string> s2 {"h", "i", "j", "k", "l", "m", "n"};

  swap_ranges(begin(s1), begin(s1)+4, begin(s2));

  for_each(begin(s1), end(s1), [](string d){cout << d << " ";}); cout << endl;
  for_each(begin(s2), end(s2), [](string d){cout << d << " ";}); cout << endl;

  auto s1_last = end(s1) - 1;
  auto s2_last = end(s2) - 1;

  iter_swap(s1_last, s2_last);  

  for_each(begin(s1), end(s1), [](string d){cout << d << " ";}); cout << endl;
  for_each(begin(s2), end(s2), [](string d){cout << d << " ";}); cout << endl;
  
  return 0;
}