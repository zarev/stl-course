#include <iostream> 

using namespace std;

template<typename T>
class Container {
  T t;

  public :
  explicit Container(T t) : t(t) {}

  friend ostream& operator<<(ostream& os, const Container<T>& c){
    return (os << "Container contains: " << c.t);
  }
};

template<typename X>
bool isGreater(X x1, X x2){
  return x1 > x2;
}

template<>
bool isGreater(int x1, int x2){
  cout << "Specaial;ised for int" << endl;
  return x1 > x2;
}


int main(){

  cout << boolalpha;

  Container<int> c(100);
  Container<string> s("Some string");

  cout << c << endl;
  cout << s << endl;

  cout << isGreater(5,10) << endl;
  cout << isGreater("AAA", "ZZZ") << endl;

  auto f = [] <typename T> (T t1, T t2){
    return t1 == t2;
  };

  cout << "LAMBDA: " << f(10,10) << endl;

  return 0;

}
