#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

int main(){

   vector<int> numbers {10,11,0,1,2,3,3,4,5,6,6,7,8,9,10,10,10,11};
   auto it = adjacent_find(begin(numbers), end(numbers));

   cout << "The number " << *it << " occures at least twice in a row. " << endl;

   vector<int> values {7,2,4};

   it = find_first_of(begin(numbers), end(numbers), begin(values), end(values));

   cout << "Found " << *it << " first" << endl;

   vector<int> seq {10,10};

   it = find_end(begin(numbers), end(numbers), begin(seq), end(seq));

   cout << "last occurance of 10 and 11 found at pos: " << 
   distance(begin(numbers), it) << endl;

    return 0;
}