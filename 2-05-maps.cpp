#include <iostream>
#include <map>
#include <string>

using namespace std;


struct SimpleObject {
  int x;
  int y;
  string z;

  SimpleObject() : x(1), y(2), z("stiff"){}

  SimpleObject(int x, int y, const string& z) :
    x(x), y(y), z(z){

    
  }
};

int main(){

  map<string, SimpleObject> objectMap;

  objectMap.insert(pair<string, SimpleObject>("first", SimpleObject(4,8, "Hello")));
  objectMap["second"] = SimpleObject();
  objectMap["second"] = SimpleObject(0,0, "overwritten");
  objectMap["third"] = SimpleObject(1,6, "World");
  objectMap.insert({"fourth", SimpleObject(1,1, "number 4")});

  const auto [iterator, inserted] = objectMap.insert({"third", SimpleObject()});

  if (inserted) cout << "Item inserted." << endl;
  else cout << "key already exist, not inserted." << endl;

  for (auto& x : objectMap){
    cout << x.first << " -> " << x.second.z << endl;
  }

  objectMap.erase("second");

  auto ptr = objectMap.find("third");

  if (ptr == objectMap.end()){
    cout << "Unable to find third" << endl;
  }else{
    cout << "found the key" << endl;
  }

  objectMap.clear();

  cout << objectMap.size() << endl;
  
  return 0;
}


/*
- associative arrays, based on key : value
- map, multimap, unordered_map, unordered_multimap
- dynamic
- maps generally slower than unordered_map





*/