#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

constexpr int PEOPLE = 4;
constexpr int STUDENTS = 2;

/*
                                INSTRUCTIONS

1. Using your Chapter 6, Implementing Hierarchies with Single Inheritance, solution,
augment your inheritance hierarchy to further specialize Student with
GraduateStudent and NonDegreeStudent.

a. Add necessary data members to your GraduateStudent class. Data members
to consider might be dissertation topic or graduate advisor. Include appropriate
constructors (default, alternate, and copy), a destructor, access member functions,
and a suitable public interface. Be sure to place your data members in the private
access region. Do the same for NonDegreeStudent.

b. Add polymorphic operations to Person, Student, GraduateStudent, and
NonDegreeStudent as necessary. Introduce, at the Person level, virtual
functions IsA() and Print(). Override IsA() and Print() in your derived
classes, as necessary. It may be that you override IsA() in Student and
GraduateStudent, but choose to override Print() only in the Student()
class. Be sure to include virtual destructors in each of your classes.

c. Instantiate Student, GraduateStudent, NonDegreeStudent, and
Person several times and utilize the appropriate public interfaces on each.
Be sure to dynamically allocate several instances.

d. Create an array of pointers to Person and allocate instances of Person,
Student, GraduateStudent, and NonDegreeStudent to be members
of this array. Once generalized, only call polymorphic operations that are found
at the Person level (and other public methods of Person). Be sure to delete any
dynamically allocated instances.

e. Now, create an array of pointers to Student and allocate only instances of
GraduateStudent and NonDegreeStudent to be members of this array.
Now, call operations that are found at the Student level to be applied to these
generalized instances. Additionally, utilize operations found at the Person
level – they are inherited and additionally available for generalized Student
instances. Be sure to delete any dynamically allocated instances pointed to in
your array.

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
    virtual ~Person();
    // Function Protoypes
    virtual void Print() const;
    virtual void isA() const;
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
void Person::isA() const
{
    cout << "This is a Person object" << endl;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

class Student : public Person
{
private:
    string classroom;
    float gpa;

public:
    Student();
    Student(const string &, const string &, int, char, const char *, const string &, float);
    Student(const Student &);
    virtual ~Student();
    // Function Protoypes
    virtual void Print() const override;
    virtual void isA() const override;
    //Inline functions
    const string &GetClassroom() const { return classroom; }
    float Getgpa() const { return gpa; }
    void ModifyAge(int age) { Person::ModifyAge(age); }
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
// Destructor
Student::~Student()
{
    cout << "Student destructor called, object -> " << this << " will be deleted after calling parent destructor" << endl;
}

// Functions
void Student::Print() const
{
    Person::Print();
    cout << "Also is assisting to " << classroom;
    cout << " having earned a GPA of " << gpa << endl;
}
void Student::isA() const
{
    cout << "This is a Student object" << endl;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

class GraduateStudent : public Student
{
private: 
    string intership_company;
public:
    GraduateStudent();
    GraduateStudent(const string &, const string &, int, char, const char *, const string &, float, const string &);
    GraduateStudent(const GraduateStudent &);
    virtual ~GraduateStudent();

    virtual void Print() const override final;
    virtual void isA() const override;

    void setIntershipCompany(const string &);
    const string &getIntershipCompany() const { return intership_company; }
};

// Inline functions
void inline GraduateStudent::setIntershipCompany(const string &company)
{
    intership_company = company;
}

// Constructors
GraduateStudent::GraduateStudent() : intership_company("")
{
    cout << "Graduate student default constructor called" << endl;
}
GraduateStudent::GraduateStudent(const string &n, const string &sn, int age, char mi, const char *t, const string &c,
                                 float g, const string &in) : Student(n, sn, age, mi, t, c, g), intership_company(in)
{
    cout << "Graduate student specific constructor called" << endl;
}
GraduateStudent::GraduateStudent(const GraduateStudent &gs) : Student(gs), intership_company(gs.intership_company)
{
    cout << "Graduate student copy constructor called" << endl;
}
GraduateStudent::~GraduateStudent()
{
    cout << "GraduateStudent destructor called, object -> " << this << " will be deleted after calling parent destructors" << endl;
}

// Functions
void GraduateStudent::Print() const
{
    Student::Print();
    cout << "The intership was done in " << intership_company << endl;
}
void GraduateStudent::isA() const
{
    cout << "This is a GraduateStudent object" << endl;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

class NonDegreeStudent : public Student
{
private:
    bool personal_exp;
    string project;
public:
    NonDegreeStudent();
    NonDegreeStudent(const string &, const string &, int, char, const char *, const string &, float, bool, const string &);
    NonDegreeStudent(NonDegreeStudent const &);
    virtual ~NonDegreeStudent();

    virtual void Print() const override final;
    virtual void isA() const override;

    bool getPersonalExp() const { return personal_exp; }
    const string &getProject() const { return project; }
};

// Constructors
NonDegreeStudent::NonDegreeStudent() : personal_exp(false), project("")
{
    cout << "Non degree Student default constructor called" << endl;
}
NonDegreeStudent::NonDegreeStudent(const string &n, const string &sn, int age, char mi, const char *t, const string &c, float g,
                                   bool pe, const string &p) : Student(n, sn, age, mi, t, c, g), personal_exp(pe), project(p)
{
    cout << "Non degree Student specific constructor called" << endl;
}
NonDegreeStudent::NonDegreeStudent(const NonDegreeStudent &nds) : Student(nds), personal_exp(nds.personal_exp), project(nds.project)
{
    cout << "Non degree Student copy constructor called" << endl; 
}
NonDegreeStudent::~NonDegreeStudent()
{
    cout << "NonDegreeStudent destructor called, object -> " << this << " will be deleted after calling parent destructors" << endl;
}

// Functions
void NonDegreeStudent::Print() const
{
    cout << "This student has no degree" << endl;
}
void NonDegreeStudent::isA() const
{
    cout << "This is a NonDegreeStudent object" << endl;
}

int main()
{
    /* This section will just use polymorphic class functions in most cases */

    Student *s1 = new Student("Pierre", "Crane", 30, 'J', "Graduated", "Medicine", 4.1);
    GraduateStudent *gs1 = new GraduateStudent("Sandra", "Perez", 29, 'S', "Graduated", "IT", 4.5, "Google");
    NonDegreeStudent *nds1 = new NonDegreeStudent("Bill", "Connor", 36, 'B', "None", "IT", 3.0, false, "React website");
    
    // Array of pointers of type Person
    Person *people[PEOPLE] = {nullptr, nullptr, nullptr, nullptr};
    people[0] = new Person;
    people[1] = new Student;
    people[2] = new GraduateStudent;
    people[3] = new NonDegreeStudent;

    //Array of pointers of type Student
    Student *students[STUDENTS] = {nullptr, nullptr};
    students[0] = new GraduateStudent("Mary", "Adams", 22, 'M', "Professional", "Math", 4.0, "Facebook");
    students[1] = new NonDegreeStudent("Nestor", "Navarro", 27, 'N', "Graduated", "IT", 4.8, true, "Tetrix");
    
    cout << '\n';
    s1->Print();
    cout << '\n';
    gs1->Print();
    cout << '\n';
    nds1->Print();
    cout << '\n';

    for (size_t i = 0; i < PEOPLE; i++)
    {
        people[i]->isA();
        delete people[i];
    }
    cout << '\n';
    for (size_t i = 0; i < STUDENTS; i++)
    {
        cout << students[i]->GetName() << " belongs to " << students[i]->GetClassroom() << " classroom" << '\n';
        delete students[i];
    }
    cout << endl;

    delete s1;
    delete gs1;
    delete nds1;
    
    return 0;
}