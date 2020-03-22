#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>
#include <functional>
#include <numeric>

using namespace std; 

int main(){

    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";

    string needle = "pisci";

    auto it = search(text.begin(), text.end(), boyer_moore_horspool_searcher(needle.begin(), needle.end()));

    if(it != text.end()){
        cout << "String: " << needle << " found at pos " << distance(text.begin(), it) << endl;
    } else{
        cout << "string not found";
    }


   

    return 0;
}