#include <iostream> 
#include <thread>
#include <atomic>
#include <chrono>
#include <future> 
#include <vector>
#include <numeric>
#include <mutex>

using namespace std;


/*
-atomic wraps datatypes
-atomic ref wraps objects
-atomic automates locking
-
*/
void partialSum(vector<int>::iterator start, vector<int>::iterator end, promise<int> promise){
  int x = 0;
  x = accumulate(start, end, x);
  promise.set_value(x);


}


int main(){
  mutex m;
  cout << "vec create" << endl;
  vector<int> numbers(900'000'000, 2);

  int numberOfThreads = thread::hardware_concurrency();
  vector<future<int>> futures;

  int offset = 0;
  int chunk = numbers.size() / numberOfThreads;

  cout << "running threads: " << numberOfThreads << endl;

  for(int i = 0; i < numberOfThreads; i++){
    promise<int> p;
    futures.push_back(p.get_future());
    cout << "Summing " << offset << " to " << offset + chunk << endl;
    thread t(partialSum, numbers.begin() + offset, numbers.begin() + offset + chunk, std::move(p));
    t.detach();
    offset+=chunk;
  }

  int sum = 0;


  for(future<int>& f : futures){
    f.wait();
    sum += f.get();
  }

  cout << sum << endl;
  
  return 0;


}