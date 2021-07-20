#include <iostream>

using std::cout;
using std::endl;

class Person
{
private: // data members will be as before
protected: // assume all member function are as before,
public: // but we will show only virtual functions here
    virtual ~Person(); // 4 virt fns introduced in Person
    virtual void Print() const;
    virtual void IsA();
    virtual void Greeting(const char *);

    /* V-TABLE CLASS PERSON
       Array of function pointers(vptr): 0->Person::~Person()
                                         1->Person::Print()
                                         2->Person::Isa()
                                         3->Person::Greeting()
    */
};
class Student: public Person
{
private: // data members will be as before
public: // assume all member functions are as before,
    // but we will show only virtual functions here
    virtual ~Student(); // 3 virtual fns are overridden
    virtual void Print() const override;
    virtual void IsA() override;

    /* V-TABLE CLASS STUDENT 
       Array of function pointers(vptr): 0->Student::~Student()
                                         1->Student::Print()
                                         2->Student::Isa()
                                         3->Person::Greeting() // Not overriden so wont change
    */
};

int main()
{
    Person *people[3];
    people[0] = new Person;
    people[1] = new Student;
    people[2] = new Student;

    for (int i = 0; i < 3; i++)
    {   // at compile time, modified to:
        people[i]->IsA(); // *(people[i]->vptr[2])()
        people[i]->Print();
        people[i]->Greeting('Message');
        delete people[i];
    }

    return 0;
}