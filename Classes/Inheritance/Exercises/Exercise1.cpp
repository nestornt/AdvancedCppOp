#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

/*
                                INSTRUCTIONS

Create a C++ program to build an inheritance hierarchy, generalizing Person 
as a base class from the derived class of Student:

a. Decide which data members and member functions of your Student class
are more generic and would be better positioned in a Person class. Build your
Person class with these members, including appropriate constructors (default,
alternate, and copy), a destructor, access member functions, and a suitable public
interface. Be sure to place your data members in the private access region.

b. Using a public base class, derive Student from Person. Remove members
from Student that are now represented in Person. Adjust constructors and
the destructor accordingly. Use the member initialization list to specify base class
constructors as needed.

c. Instantiate both Student and Person several times and utilize the appropriate
public interfaces on each. Be sure to dynamically allocate several instances.

d. Add a message using cout as the first line in each of your constructors and as the
first line in your destructors

*/

class Person
{
private:
    // Data members
    string name;
    string second_name;
    int age;
    char middleInitial;
    char *title;

protected:
    // Protected Function
    void ModifyAge(int age){ this->age = age; }

public:
    //Constructors
    Person();
    Person(const string &, const string &, int, char, const char *);
    Person(const Person &);
    ~Person();
    // Function Protoypes
    void Print() const;
    // Inline Functions
    const string &GetName() const { return name; }
    const string &GetSecondName() const { return second_name; }
    int GetAge() const { return age; }
    char GetInitial() const { return middleInitial; }
    const char *GetTitle() const { return title; }

};
// Default Constructor
Person::Person() : name(""), second_name(""), age(0), middleInitial('\0'), title(nullptr)
{
    cout << "Person default constructor called" << endl;
}
// Specific Constructor
Person::Person(const string &n, const string &sn, int age, char mi, const char *t)
{
    cout << "Person specific constructor called" << endl;
    name = n;
    second_name = sn;
    this->age = age;
    middleInitial = mi;
    title = new char[strlen (t) + 1];
    strcpy(title, t);
}
// Copy Constructor
Person::Person(const Person &p) : name(p.name), second_name(p.second_name), age(p.age), middleInitial(p.middleInitial)
{
    cout << "Person copy constructor called" << endl;
    title = new char(strlen(p.title) + 1);
    strcpy(title, p.title);
}
// Destructor
Person::~Person()
{
    cout << "Person destructor called, deleted object -> " << this << endl;
    delete title;
}
// Function Definitions
void Person::Print() const
{
    cout << "The Person " << name << " " << second_name;
    cout << " is " << age << " years old, ";
    cout << "and have earned a title of " << title << endl;
}

class Student : public Person
{
private:
    string classroom;
    float gpa;

public:
    Student();
    Student(const string &, const string &, int, char, const char *, const string &, float);
    Student(const Student &);
    ~Student();
    // Function Protoypes
    void Print();
    //Inline functions
    const string &GetClassroom() const { return classroom; }
    float Getgpa() const { return gpa; }
    // Inline protype
    void SetClassroom(const string &);

};
// Inline Function Definition
inline void Student::SetClassroom(const string &c)
{
    classroom = c;
}
// Default Constructor
Student::Student() : classroom(""), gpa(0.0)
{
  cout << "Student default constructor called" << endl;  
}
// Specific Constructor
Student::Student(const string &n, const string &sn, int age, char mi, const char *t, const string &c, float g) :
                Person(n, sn, age, mi, t), classroom(c), gpa(g)
{
    cout << "Student specific constructor called" << endl;
}
// Copy Constructor
Student::Student(const Student &s) : Person(s), classroom(s.classroom), gpa(s.gpa)
{
    cout << "Student copy constructor called" << endl;
}
Student::~Student()
{
    cout << "Student destructor called, object -> " << this << " will be deleted after calling parent destructor" << endl;
}
// Functions
void Student::Print()
{
    Person::Print();
    cout << "Also is assisting to " << classroom;
    cout << " having earned a GPA of " << gpa << endl;
}

int main()
{
    Person p1("Nestor", "Navarro", 27, 'N', "C++ title");
    Person *p2 = new Person("John", "Doe", 129, 'J', "Unknown");
    Student *s1 = new Student("Pierre", "Crane", 30, 'J', "Graduated", "Medicine", 4.1);

    cout << "The first person assisting is " << p1.GetName() << " " << p1.GetSecondName() << '\n';
    s1->Print();

    delete p2;
    delete s1;
    
    return 0;
}