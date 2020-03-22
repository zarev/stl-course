#include <iostream>
#include <string>

using namespace std;

int main(){
  string name = "James";
  string n2("James2");
  string n3(name);

  string n4{'j', 'a','m','e','s'};

  string initial(name, 0, 1);
  string line(20,'*');
  string reverse(name.rbegin(), name.rend());

  cout << name << endl;
  cout << n2 << endl;
  cout << n3 << endl;
  cout << n4 << endl;
  cout << initial << endl;
  cout << reverse << endl;
  cout << line << endl;

  // finding
  size_t pos = name.find(initial);

  if(pos !=string::npos){
    cout << "Found at: " << pos << endl;
  }
  
  // appending

  string about = "is a programmer";
  name.push_back(' ');
  for (char c : about){
    name.push_back(c);
  }
  cout<<name<<endl;
  return 0;
}