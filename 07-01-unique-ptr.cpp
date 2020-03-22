#include <iostream>
#include <memory>
#include <string>

using namespace std; 

/*
-disposes of object when out of scope
-deleters can be defined
-object can be moved but not copied
-const ptr cannot be moved or copied
*/ 

class Student {
  private:
    int id;
    string first;
    string last; 
  public: 
    Student(int id, const string& first, const string& last):
      id(id), first(first), last(last){}
    Student(): id(), first({}), last({}) {}

    int get(){return id;}
    const string& getFirst() const {return first;}
    const string& getLast()  const {return last;}
};

class StudentDeleter {
  public : 
    void operator()(Student* s) const {
      cout << "Deteting student: " << s->getFirst() << " " << s->getLast() << endl;
      delete s;
    }
};

int main(){
    unique_ptr<Student> s1(new Student(1, "Mochi", "Mochovytsch"));
    unique_ptr<Student> s2 = make_unique<Student>(2, "Birdie", "Johnson");
    unique_ptr<Student> s3 = make_unique<Student>();

    StudentDeleter d;
    Student* mariyan = new Student(3, "Mariyan", "Zarev");

    unique_ptr<Student, StudentDeleter> m (mariyan, d);

    unique_ptr<Student> n = nullptr;

    




  return 0;
};