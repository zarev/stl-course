#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>
#include <random>
#include <cstdint>

using namespace std; 

int main(){
  string s = "Hello world! I am pleased to be here!";
  string out;

  transform(begin(s), end(s), back_inserter<string>(out), [](const char& c){return clamp(c, 'd', 'o');});

  cout << s << endl; 
  cout << out << endl;

  return 0;
};