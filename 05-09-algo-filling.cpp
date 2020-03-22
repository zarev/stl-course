#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std; 

struct FibGen{
  FibGen(){
    n = 1;
    n_1 = 1;
  }
  int operator()(){
    int out = n_1;
    int next = n + n_1;
    n_1 = n;
    n = next;
    return out;
  }
  private:
    int n;
    int n_1;
};

int main(){
  int values[10];

  fill(begin(values), end(values), 0);

  values[2] = 55;

  generate(begin(values), end(values), FibGen());

  copy(begin(values), end(values), ostream_iterator<int>(cout, " "));
  cout << endl;



  return 0;
};