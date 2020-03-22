#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

int main(){
  
int i = 35, j = 13;

cout << gcd(i, j) << " " << endl;
i = 8, j = 12;

cout << gcd(i, j) << " " << endl;
  
vector<int> num1 {6,3,8,12,24,13,5,35};
vector<int> out;

adjacent_difference(begin(num1), end(num1), back_inserter<vector<int>>(out), std::gcd<int, int>);

copy(begin(out), end(out), ostream_iterator<int>(cout, " "));


  return 0;
};