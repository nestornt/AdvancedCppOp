#include <iostream>

class Person // base class
{
public:
    virtual void Print() const;
};
class Student: public Person
{
public:
    // Newly introduced virtual fn. --
    // Not a redefinition of Person::Print()
    virtual void Print(const char *) const;
};

int main()
{
    Person *people[2];
    people[0] = new Person;
    people[1] = new Student;
    people[1]->Print(); // ok, Person::Print() defined
    // people[1]->Print("Go Team!"); // error!
    // explicit downcast to derived type assumes you
    // correctly recall what the object is
    ((Student *)people[1])->Print("I have to study");
    // Student stored in its own type
    Student s1;
    // s1.Print(); // error, base class version hidden
    s1.Print("I got an A!"); // works for type Student
    s1.Person::Print(); // works using scope resolution
    // to base class type
    return 0;
}