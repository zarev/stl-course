#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

int main(){
  vector<int> v = {1,2,3,4,5,6,7,8,9,0};
  vector<int> v_copy;

  for_each(begin(v), end(v), [](int i){cout << i << " ";}); cout << endl;

  replace_copy(begin(v), end(v), back_inserter<vector<int>>(v_copy), 4, 87878);

  for_each(begin(v_copy), end(v_copy), [](int i){cout << i << " ";}); cout << endl;

  v_copy.clear();

  replace_copy_if(begin(v), end(v), back_inserter<vector<int>>(v_copy), 
  [](int i){return i < 7;}, 55);

  for_each(begin(v_copy), end(v_copy), [](int i){cout << i << " ";}); cout << endl;


  return 0;
}