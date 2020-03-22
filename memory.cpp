#include <iostream>
#include <memory>

using namespace std;

class Widget {
  int num;

  public : 
    Widget(int num) : num(num) {
      cout << "Making a widget: " << num << endl;
    }

    virtual ~Widget() {
      cout << "Destroying widget: " << num << endl;
    }
};

int main(){
  Widget* w = new Widget(1);
  delete w;

  unique_ptr<Widget> uw = make_unique<Widget>(2);

  return 0;
}