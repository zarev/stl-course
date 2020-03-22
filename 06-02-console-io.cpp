
#include <vector>
#include <iostream>
#include <string>
#include <locale>

using namespace std; 

int main(){
  locale loc;
  cout << loc.name() << endl;
  cout << 18.90d << endl;
  cout << 'J' << endl;

  string face = "Face: \U0001f60a";
  cout << face << endl;

  int x = 0;
  double d = 0;
  string name = "";

  cout << "int?"<< endl;
  cin >> x;

  cout << "double?" << endl;
  cin >> d;

  cout << "name?" << endl;
  cin >> name;

  if(cin.fail()){
    cin.clear();
    cerr << "input error" << endl;
    string s;
    cin >> s;
    cout << s << endl;
  }else{
    cout << x << endl;
  }

  return 0;
};