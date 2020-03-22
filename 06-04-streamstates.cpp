
#include <vector>
#include <iostream>
#include <string>
#include <locale>
#include <fstream>

using namespace std; 

int main(){
  ifstream fs("input.txt");

  if(fs){
    cout << "ifstream good" << endl;
    int count = 0;
    while(fs.good()){
      string line;
      fs >> line;
      if(line.size() < 0){++count;}
    }
    cout << count << endl;
  }
  if (fs.bad()){cout << "stream bad!";}
  if (fs.fail()){cout << "stream fatal";}
  if (fs.eof()){cout << "stream end";}

  cout << std::showbase << std::hex << (int)fs.rdstate() << endl;
  fs.setstate(ios::eofbit);
  cout << std::showbase << std::hex << (int)fs.rdstate() << endl;

  return 0;
};