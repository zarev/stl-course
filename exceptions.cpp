// #exceptions
#include <iostream>
#include <exception>

using namespace std;

class ResourceException : public exception {
  string w;

  public : 
    ResourceException(const string& w) : w(w) {}
    const char* what() const noexcept{
      return w.c_str();
    }

};

class SomethingImportant {
  public :
    SomethingImportant() {
      // throw ResourceException("Unable to open resource");
      // throw 10;
      throw string ("Geeeodude");
    }
};

int main(){
  try {
    SomethingImportant st;
  } catch(exception& except){
    cout << except.what() << endl;
    return 1;
  }catch(int i){
    cout << "Caught an illegal int" << endl;
    return 2;
  }catch(...){
    cout << "catchall endall" << endl;
    return 3;
  }

  return 0;
}