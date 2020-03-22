
#include <vector>
#include <iostream>
#include <string>
#include <locale>
#include <sstream>

using namespace std; 

int main(){
 stringstream ss;

 ss << 25 << " " << 50 << " " << 75 << " ";

 cout << ss.str() << endl;

 int i = 0;
 ss >> i;

 cout << i << endl;

 ss << 100;

 cout << ss.str() << endl;


  return 0;
};