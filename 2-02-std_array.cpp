#include <iostream>
#include <array>

using namespace  std;


int main(){
  
  int numbers[20] = {0,1,2,0,0,2,2,1,1,0,1,2,2,1,0,0,0,0,1,1};
  std::array<int, 20> numbers2 = {0,1,2,0,0,2,2,1,1,0,1,2,2,1,0,0,0,0,1,1};

  for (int i : numbers){
    cout << i << " ";
  }
  cout << endl;

  for (int i : numbers2){
    cout << i << " ";
  }
  cout << endl;

  return 0;
}

/*
- sequencial container
- fixed size, no growing or shrinking
- swapping and moving is linear in time
- std::array knows its size unlike vanilla
- std arrays can be used as stl containers and
not just plain arrays

*/