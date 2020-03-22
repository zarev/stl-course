#include <iostream> 
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;


/*
-atomic wraps datatypes
-atomic ref wraps objects
-atomic automates locking
-
*/

void deposit(std::atomic<int>& account){
  account++;
}

void withdrawl(std::atomic<int>& account){
  account--;
}

int main(){
  atomic<int> account(1000);

  cout << account.load() << endl;

  for(int i = 0; i < 100; i++){
    thread t(&deposit, std::ref(account));
    t.detach();
  }

  for(int i = 0; i < 250; i++){
    thread t(&withdrawl, std::ref(account));
    t.detach();
  }

  this_thread::sleep_for(2s);

  cout << account.load() << endl;
  
  return 0;


}