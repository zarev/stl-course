#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

int main(){
  string s = "This is some string";
  vector<int> n(11);
  iota(begin(n), end(n), 0);

  for_each(begin(n), end(n), [](int i){cout << i << " ";});  
  replace_if(begin(n), end(n), [](int i) -> bool {return i>= 7;}, 6);
  for_each(begin(n), end(n), [](int i){cout << i << " ";});  

  cout << s << endl;
  replace(begin(s), end(s), 's', 'B');
  cout << s << endl;




  return 0;
}