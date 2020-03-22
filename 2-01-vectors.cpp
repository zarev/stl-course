#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printVector(const vector<T>& vec){
  cout << "Used: " << vec.size() << "/" << vec.capacity() 
      << " max_size: " << vec.max_size() << endl;
  
  for (const T& t : vec){
    cout << t << " ";
  }
  cout << endl;
}

int main(){

  vector<int> numbers;
  vector<string> strings {"Hello", "How", "Are", "You", "Doing", "?"};

  numbers.push_back(100);
  numbers.push_back(200);
  numbers.push_back(300);

  printVector(numbers);
  printVector(strings);

  strings.resize(3);
  printVector(strings);

  strings.resize(10, "XXXX");
  printVector(strings);

  numbers.push_back(400);
  numbers.push_back(500);
  printVector(numbers);

  for (int* p = &numbers[0]; p < (&numbers[0] + numbers.size()); p++){
    cout << *p << endl;
  }

  //bad access
  cout << numbers[10] << endl;

  try{
    cout << numbers.at(10);
  } catch (out_of_range& e){
    cerr << e.what() << endl;
  }

  return 0;
}

/*
- sequence containers that can change in size after creation
- they can be accessed via pointers or [index] like arrays
- efficient at acessing elements
- efficient at adding and deleting from the *edges*
- inefficient at adding and deleting at arbitrary positions because
all the other elements have to be shifted
- when it grows beyond the initial capacity, memory for the new bigger
vector is created and then the whole old vector is copied over
*/

/*
When & is used in a declaration, it is a reference operator.
When & is not used in a declaration, it is an address operator.

When * is used in a declaration, it is creating a pointer.
When * is not used in a declaration, it is a dereference operator.
*/
