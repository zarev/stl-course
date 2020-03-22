#include <iostream>
#include <memory>
#include <string>

using namespace std; 

/*
-shared and auto deleted
-deleter can be defined
-can be copied
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

void printStudent(weak_ptr<Student> s){
  cout << s.use_count() << " references open" << endl;
  if(shared_ptr<Student> l = s.lock()){
    cout << l->getFirst() << " " << l->getLast() << endl;
  }else{
    cout << "point has expired" << endl;
  }
}

//s passed by value! not reference
void printSharedStudent(shared_ptr<Student> s){
  cout << s.use_count() << " references open" << endl;
  cout << s->getFirst() << " " << s->getLast() << endl; 
}

int main(){
    weak_ptr<Student> w;

    {
      shared_ptr<Student> s(new Student(1, "Mochi", "Mochovytsch"));
      
      StudentDeleter sd;
      Student* j = new Student(2, "Birdie", "Johnson");

      shared_ptr<Student> student(j, sd);

      printStudent(s);
      printStudent(student);

      printSharedStudent(s);
      printSharedStudent(student);

      w = student;

      printStudent(w);
      
    }
    
    printStudent(w);

  


  return 0;
};