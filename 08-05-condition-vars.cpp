#include <iostream> 
#include <thread>
#include <atomic>
#include <chrono>
#include <future> 
#include <vector>
#include <numeric>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;


/*
-
*/
struct DataSource{
  mutex m;
  condition_variable cv;
  queue<int> workUnits;
};

void consumer(DataSource& ds){
  while(true){
    unique_lock lock(ds.m);
    cout << "Waiting on thread: " << this_thread::get_id() << endl;
    ds.cv.wait(lock, [&ds]{return ds.workUnits.size() > 0;});

    int workUnit = ds.workUnits.front();
    ds.workUnits.pop();

    cout << "Processing thread: " << this_thread::get_id() << " : " << workUnit << endl;

    lock.unlock();
    this_thread::sleep_for(1s);
  }
}

void producer(DataSource& ds){
  int i = 0;
  while(true){
    {
      unique_lock lock(ds.m);
      if(ds.workUnits.size() > 40){
        cout << "Waiting for production to catch up" << endl;
      }
      else{
        cout << "Producing: " << i << endl;
        ds.workUnits.push(i++);
      }
    }
    ds.cv.notify_all();
    this_thread::sleep_for(200ms);
  }
}

int main(){
  DataSource ds;

  for(int i = 0; i < 5; i++){
    thread t(&consumer, std::ref(ds));
    t.detach();
  }
  thread t(&producer, std::ref(ds));
  t.join();



  
  return 0;


}