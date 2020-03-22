#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

int main(){

   vector<int> numbers {1,1,2,3,3,3,3,4,5,6,7,7,7,7,8,9,10,10,11};
   bool exists = binary_search(begin(numbers), end(numbers),7);

  if(exists){ cout << "found" << endl;}
  else{ cout << "not found" << endl;};

  auto [lower, upper] = equal_range(begin(numbers), end(numbers), 3);

  cout << "Found 3 between " << distance(begin(numbers), lower) << " and " <<
  distance(begin(numbers), upper) << ")" << endl;

  lower = lower_bound(begin(numbers),end(numbers), 10);
  upper = upper_bound(begin(numbers),end(numbers), 10);
  
  cout << "Found 10 between [" << distance(begin(numbers), lower) << " and " 
  << distance(begin(numbers), upper) << ")" << endl; 




    return 0;
}