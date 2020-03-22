#include <iostream> 
#include <iterator>
#include <vector>
#include <typeinfo>

using namespace std;

int main(){

  vector<string> vec = {"1", "2", "3"};

  using traits =iterator_traits<vector<string>::iterator>;

  cout << boolalpha;

  cout << "value_type == string: " <<
  (typeid(traits::value_type) == typeid(string)) << endl;

  cout << "value_type == string*: " <<
  (typeid(traits::pointer) == typeid(string*)) << endl;

  cout << "value_type == string&: " <<
  (typeid(traits::reference) == typeid(string&)) << endl;

  cout << "value_type == ptr_ddiff_t: " <<
  (typeid(traits::difference_type) == typeid(ptrdiff_t)) << endl;

  

  
    

}



/*
- can be for input, output, forward, bidirectional, random access, contiguous
- all algorithms in the STL operate on iterators
- allow iterating in a container agnostic way
- iterator_traits differentiate between the different types
*/