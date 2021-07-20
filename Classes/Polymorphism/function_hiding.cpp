#include <iostream>

using std::cout;
using std::endl;

class Person
{
public:
    virtual void Print() const;
};
void Person::Print() const
{
    cout << "Print from class Person" << endl;
}

class Student: public Person
{
public:
    // Override the base class method so that this
    // interface is not hidden by overloaded fn. below
    virtual void Print() const override;
    // add the additional interface
    virtual void Print(const char *) const; // overloaded
    // virtual from this point downward
};
void Student::Print() const
{
    cout << "Print from class Student (Overrided Print fn)" << endl;
}
void Student::Print(const char *msg) const
{
    cout << "Print from class Student (Overloaded Print from overrided Student fn)" << '\n';
    cout << "Message: " << msg << endl;
}

int main()
{
    Person p1;
    Student s1;
    s1.Print(); // this version is no longer hidden.
    s1.Print("I got an A!"); // also works
    s1.Person::Print(); // this is no longer necessary
    p1.Print();
}