#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>


using namespace std;


int main(){

  ifstream in("illiad.txt");
  multimap<string, pair<int, int>> wordPositions;
  int lineNumber, wordInLine = 0;
  string line = " ";

  while(!in.eof()){
    lineNumber++;
    getline(in,line);

    istringstream iss(line);
    string word = "";

    while (!iss.eof()){
      wordInLine++;
      iss >> word; 
      wordPositions.insert(make_pair(word, make_pair(lineNumber,wordInLine)));
    }
    wordInLine = 0;
   
  }

  cout << "lines of text: " << lineNumber << endl;

  for (auto it = wordPositions.cbegin(), it2=it; it !=wordPositions.cend(); it=it2){
    unsigned int count = wordPositions.count(it->first);
    cout << "\"" << it->first << "\" occurs " << count << " times, and is on:  \n";
    cout << "\n" << it->second.first << endl;
    for (; it2 != wordPositions.cend() && it2->first == it->first; it2++){
      auto [line, word] = it2->second;
      cout << "\tline "  << line << ", position " << word << "\n";  
    }
    
  }

  in.close();
  return 0;
}

//go through word map, print each word and its positions