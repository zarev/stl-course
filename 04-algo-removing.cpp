#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

bool isValidChar(char c){
    return !(isalpha(c));
}


int main() {
    string word = "h3llo, h0w @re you?";
    string other;

    cout << word << endl;

    auto it = remove_if(word.begin(), word.end(), &isValidChar);
    cout << word << endl;

    word.erase(it, word.end());
    cout << word << endl;

    word = "h3llo, h0w @re you?";

    remove_copy_if(word.begin(), word.end(), back_inserter(other), &isValidChar);

    cout << word << endl; 
    cout << other << endl;
    
    

    cout << word << endl;
    cout << other << endl;

    return 0;
}