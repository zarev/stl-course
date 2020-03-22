#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

int main(){

    string s = "This Is Some String Of Text In Mixed Case and some chars like: , 2 1 ! ";
    vector<int> num(100);
    iota(begin(num), end(num), 1);

    cout << "String now: " << s << "\n";

   auto it = find(begin(s), end(s), ',');

   cout << "Found the comma at pos: " << distance(begin(s), it) << endl;

   auto number = find_if(begin(num), end(num), [](int i){return (i % 3 == 0 && i % 5 == 0);});

   cout << "Found first number divisible by 3 and 5 at pos: " << 
   distance(begin(num), number) << " (" << *number << ")\n";
   cout << endl;

   number = begin(num);
   while(number != end(num)){
       number = find_if(number, end(num), [](int i){return (i % 3 == 0 && i % 5 == 0);});
       if(number != end(num)){ 
           cout << *number << " ";
           advance(number, 1);
        }
   }

    return 0;
}