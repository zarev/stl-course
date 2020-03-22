#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

/*
-transform does not make changes to the dataset, it copies then changes the copy
-for each can be used to make changes to the source
-transform does not guarantee ordered output
-for ordered transform use for each
*/

int main(){
  string s = "This is some string of LETTERS and Numbers 123456 21";
  vector<double> n1{1.4,0.3,-0.4,5.6,1.2};
  vector<double> n2{2.4,-0.3,1.87, 4.3, 0.8};

  string lower;
  transform(begin(s), end(s), back_inserter<string>(lower), [](unsigned char c){
    return std::tolower(c);
  });

  cout << s << endl;
  cout << lower << endl;

  vector<double> result;
  transform(begin(n1), end(n1), begin(n2), back_inserter<vector<double>>(result),
  [](double d1, double d2){return d1+d2;});

  for_each(begin(result), end(result), [](double d){cout << d << " ";}); cout << endl;

  return 0;
}