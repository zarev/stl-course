#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 



int main(){
  vector<int> num{2,2,2,2,2,2,2,2,2};
  vector<int> out;

  partial_sum(begin(num), end(num), back_inserter<vector<int>>(out));
  for_each(begin(out), end(out), [](int& a){cout << a << " ";}); cout << endl;
  out.clear();

  partial_sum(begin(num), end(num), back_inserter<vector<int>>(out), multiplies<int>());
  for_each(begin(out), end(out), [](int& a){cout << a << " ";}); cout << endl;

  vector<int> diff;

  adjacent_difference(begin(out), end(out), back_inserter<vector<int>>(diff));
  for_each(begin(diff), end(diff), [](int& a){cout << a << " ";}); cout << endl;

  vector<int> fib(15,0);
  fib[0] = 1;
  adjacent_difference(begin(fib), prev(end(fib)), next(begin(fib)), plus<int>());
  for_each(begin(fib), end(fib), [](int& a){cout << a << " ";}); cout << endl;

  



  return 0;
};