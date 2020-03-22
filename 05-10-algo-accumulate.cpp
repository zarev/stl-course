#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

int main(){
  vector<int> i(5);
  iota(begin(i),end(i),1);

  for_each(begin(i), end(i), [](int n){cout << n << " ";}); cout << endl;

  int sum = accumulate(begin(i), end(i), 0);
  long  product = accumulate(begin(i), end(i), 1, std::multiplies<long>());

  cout << "SUM:   " << sum << endl;
  cout << "Prod: " << product << endl;



  return 0;
};