#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>

using namespace std; 

int main(){
    function<bool(unsigned char)> pred = [](unsigned char c) -> bool { return isupper(c);};

    string s = "This Is Some String Of Text In Mixed Case";

    if(!is_partitioned(begin(s), end(s), pred)){ partition(begin(s), end(s), pred);};

    cout << "String now: " << s << "\n";

   auto part = partition_point(begin(s), end(s), pred);

   cout << "True partitioned bucket: ";
   copy(begin(s), part, ostream_iterator<char>(cout, ""));
   cout << endl;
   cout << "False bucket: ";
   copy(part, end(s), ostream_iterator<char>(cout,""));
   cout << endl;

   

    return 0;
}