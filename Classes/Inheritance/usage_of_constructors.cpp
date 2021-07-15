#include <iostream>

using std::cout;
using std::endl;

//? Simple example to illustrate the basic syntax for base class constructor selection
class Person
{
private:
    char *name;
    char *title;
public:
    Person(); // various constructors
    Person(const char *, const char *);
    Person(const Person &);
    ~Person(); // destructor
    // Assume the public interface, access functions exist
};
class Student: public Person
{
private:
    float gpa;
public:
    Student();
    Student(const char *, const char *, float);
    ~Student();
    // Assume the public interface, access functions exist
};
//$ Base class constructors
Person::Person()
{
    name = title = 0; // null pointer
}
Person::Person(const char *n, const char *t)
{ 
    // implementation as expected
}
Person::Person(const Person &p)
{ 
    // implementation as expected
}

//$ Derived class constructors
Student::Student() // default constructor
{
    gpa = 0.0;
}
Student::Student(const char *n, const char *t, float g): Person(n, t)
{ // member init. list
    gpa = g;
}
Student::Student(const Student &s): Person(s)
{ // member init. list
    gpa = s.gpa;
}

int main()
{
    return 0;
}