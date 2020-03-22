#include <iostream> 
#include <iterator>
#include <vector>
#include <numeric>
#include <thread>
#include <mutex>

using namespace std;


/*
-mutex protects shared data
-preserves data integrity
-exclusive locing of resources
-envoked with locks
*/

#define TRANSACTIONS 100000

void deposit(int& account, mutex& m){
  for (int i = 0; i < TRANSACTIONS; i++){
    {
      lock_guard<mutex> lock(m);
      account++;
    }
    
  }
}

void withdrawl(int& account, mutex& m){
  for (int i = 0; i < TRANSACTIONS; i++){
    {
      lock_guard<mutex> lock(m);
      account--;
    }
  }
}


int main(){
  unsigned int threads = thread::hardware_concurrency();

  cout << threads << endl;
  mutex m;

  int account = 0;
  thread t1 (deposit, std::ref(account), std::ref(m));
  thread t2 (withdrawl, std::ref(account), std::ref(m));

  t1.join();
  t2.join();


  cout << "Account: " << account << endl;




}