
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std; 

class Student{
  private:
    int s_id;
    string f_name;
    string l_name;
    int age;
  
  public:
    Student() : s_id{}, f_name({}), l_name({}), age{} {}

    Student(int studentId, const string& first, const string& last, int age):
      s_id(studentId), f_name(first), l_name(last), age(age){}
    
    int           getStudentId()  {return this->s_id;}
    const string& getFirst()      {return this->f_name;}
    const string& getLast()       {return this->l_name;}
    int           getAge()        {return this->age;}

  friend ostream& operator<<(ostream& os, const Student& s){
    os << "Student: ID : " << s.s_id << ", ";
    os << "Fist name: " << s.f_name << ", ";
    os << "Last name: " << s.l_name << ", ";
    os << "Age: " << s.age << ". ";
    return os; 
  }

  friend istream& operator>>(istream& is, Student& s){
    is >> s.s_id;
    is >> s.f_name;
    is >> s.l_name;
    is >> s.age;
    return is;
  }

};
int main(){
  Student s{1, "Mochi", "Mochovytsch", 21};
  cout << s << endl;



  return 0;
};