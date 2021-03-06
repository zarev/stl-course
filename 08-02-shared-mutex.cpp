#include <iostream> 
#include <iterator>
#include <vector>
#include <numeric>
#include <thread>
#include <mutex>
#include <shared_mutex>

using namespace std;


/*
-mutex protects shared data
-preserves data integrity
-exclusive locing of resources
-envoked with locks
*/

struct DataSource{
    private: 
      shared_mutex mut;
      int value = 0;
    public:
      DataSource() = default;
      
      int get(){
        shared_lock lock(mut);
        cout << "Getting value: " << value << endl;
      }
      void set(int v){
        unique_lock lock(mut);
        cout << "Setting value: " << v << endl;
      }
};

void readWorker(DataSource& ds){
  while(true){
    ds.get();
    this_thread::sleep_for(500ms);
  }
}

void writeWorker(DataSource& ds){
  while(true){
    int val = ds.get();
    ds.set(val+1);
    this_thread::sleep_for(2s); 
  }
}

int main(){
  DataSource d;
  thread writeThread(&writeWorker, std::ref(d));

  for(int i = 0; i < 50; i++){
    thread r(&readWorker, std::ref(d));
    r.detach();
  }

  writeThread.join();

  return 0;


}