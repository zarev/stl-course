#include <iostream>
#include <list>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main(){
  deque<int> transactions; 

  transactions.push_front(100);
  transactions.push_front(300);

  transactions.push_back(500);
  transactions.push_back(600);

  for (unsigned int i = 0; i < transactions.size(); i++){
    cout << transactions[i] << " ";
  }
  cout << endl;


  stack<int> stack;
  stack.push(100);
  stack.push(200);
  stack.push(300);
  stack.push(400);
  stack.push(500);
  stack.push(600);
  stack.push(700);

  while(!stack.empty()){
    cout << stack.top() << " ";
    stack.pop();
  }
  cout << endl;

  queue<int> queue;
  queue.push(100);
  queue.push(200);
  queue.push(300);

  while (!queue.empty()){
    cout << queue.front() << " ";
    queue.pop();
  }
  cout << endl;

  return 0;
}

/*
- based on deques
- deques are double ended queues
- deques are similar to vectors, but internally different
- deques might not store elements sequencially
- more complex internally than vectors, but able to grow 
more efficiently when storing large sequences
- worse than lists at frequent insertion and deletion at random indices

- queues typically overlay deques
- operate in FIFO
- elements are pushed back and popped from front

- stacks also overlays deques
- operates LIFO
- elements only inserted and popped from the back


*/

/*
When & is used in a declaration, it is a reference operator.
When & is not used in a declaration, it is an address operator.

When * is used in a declaration, it is creating a pointer.
When * is not used in a declaration, it is a dereference operator.
*/