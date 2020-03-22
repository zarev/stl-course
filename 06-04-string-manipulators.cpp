
#include <vector>
#include <iostream>
#include <string>
#include <locale>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std; 

int main(){
 int byte = 0xA9;
 cout << byte << endl;
 cout << std::dec << byte << endl;
 cout << std::oct << byte << endl;
 cout << std::hex << byte << endl;
 cout << std::showbase << byte << endl;

 string name = "mochi mochovytsch";
 cout << setfill('-');
 cout << name << endl;
 cout << setw(40) << name << endl;
 cout << setw(40) << std::left << name << endl;
 cout << setw(40) << std::right << name << endl;
 
 long double d = 4 * atan(1);
 cout << d << endl;
 cout << std::setprecision(20) << d << endl;
 cout << std::setprecision(3) << d << endl;
 cout << std::scientific << d << endl;

 long double cash = 12345;
//  cout.imbue(std::locale("")); 
 cout << put_money(cash) << endl;
 cout << put_money(cash, true) << endl;


  return 0;
};