#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

/*
-rotates left
-for right rotate rbegin, rend
*/

int main(){
  vector<int> i(8);
  iota(begin(i),end(i),0);

  for_each(begin(i),end(i), [](int i){cout << i << " ";}); cout << endl;

  rotate(begin(i),begin(i) + 2, end(i));

  for_each(begin(i),end(i), [](int i){cout << i << " ";}); cout << endl;

  rotate_copy(rbegin(i),rbegin(i) + 5, rend(i), ostream_iterator<int>(cout, " "));

  
  return 0;
}