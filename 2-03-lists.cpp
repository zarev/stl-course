#include <iostream>
#include <list>

using namespace std;

int main(){

list<int> myList{10,20,25,30,40,50};
list<int> other{15,25,35,45,50,55};

myList.merge(other);

cout << myList.size() << endl;
cout << other.size() << endl;

for (auto i = myList.begin(); i != myList.end(); i++){
  cout << *i << " ";
}
cout << endl;
return 0;

 

}

/*

-dynamic containers
- constant time for insertion and deletion anywhere in the list
- doubly linked lists
- each element can have an arbitrary address, not adjacent 
to the other elements in the list
- list are better and arbitrarily insertion, deletion and moving
of elemets
- forward lists only keep track of the next elements
- not random access, must iterate from beginning
- takes slightly more memory due to pointers 
*/

/*
When & is used in a declaration, it is a reference operator.
When & is not used in a declaration, it is an address operator.

When * is used in a declaration, it is creating a pointer.
When * is not used in a declaration, it is a dereference operator.
*/
