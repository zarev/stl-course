
#include <vector>
#include <iostream>
#include <string>
#include <locale>
#include <fstream>

using namespace std; 

int main(){
 ofstream os("out.txt");
 int i = 231;
 double d = 3.14;
 char c = 'k';
 string name = "mochi";

 os << i << "  " << d << " " << name;
 os.close();

 os.open("out.txt", ios::app);
 os << "a[[end this";
 os.close();

 ifstream  is("out.txt");

 int ii;
 double dd;
 string namename;

 is >> ii >> dd >> namename;
 is.close();


  return 0;
};