
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std; 

int main(){
  ifstream fs("in.txt");
  string text;

  if(fs){
    char c = fs.peek();
    cout << "peek saw: " << c << endl;

    fs.seekg(0, ios_base::end);

    int size = fs.tellg();
    cout << size << endl;

    text.resize(size);

    fs.seekg(0, ios_base::beg);

    fs.read(text.data(), size);

    cout << text << endl;

    fs.close();
  }
  else{cerr << "input err"; return 1;}

  ofstream out("out.txt");

  if(out){
    for_each(begin(text), end(text), [&out](char c){
      out.put(c);
    });
  }
  else{
    cerr << "uanble to open file" << endl;
    return 2;
  }

  out.close();



  return 0;
};