#include <iostream>
#include <cstring>

using namespace std;

class Person // base class
{
private:
    char *name;
    char *title;
public:
    Person(); // various constructors
    Person(const char *, const char *);
    Person(const Person &);
    ~Person(); // destructor
    // constructors, destructor,
    // public access functions, public interface etc …
    const char *GetTitle() const { return title; }
};
class Student: public Person // derived class
{
private:
    float gpa;
public:
    Student();
    Student(const char *, const char *, float);
    ~Student();
    // constructors, destructor specific to Student,
    // public access functions, public interface, etc …
    float GetGpa() const { return gpa; }
};

Person::Person(const char* name, const char* initials)
{
    
}

int main()
{
    // Let's assume the applicable constructors exist
    Person p1("Cyrus Bond", "Mr.");
    Student *s1 = new Student("Anne Lin", "Ms.", 4.0);
    cout << p1.GetTitle() << " " << s1->GetTitle();
    cout << s1->GetGpa() << endl;
    return 0;
}