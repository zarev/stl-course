#include <iostream>
#include <string>
#include <fstream>
#include <set>


using namespace std;


int main(){
 ifstream in("illiad.txt");
 set<string> words;
string word = " ";

unsigned long long totalCount = 0;

while (!in.eof()){
  in >> word;
  totalCount++;
  words.insert(word);
  
}

cout << "the text contains " << words.size() << " unique words out of " << totalCount << endl; 
  
return 0;

}


/*
- items stored by key (which is also the value)
- inserted items can only be inspected or removed
- multisets can have multiple, but unique keys
- unordered can be faster for searching and retreival

*/