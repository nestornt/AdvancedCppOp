#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

/*
a. Create or modify your previous Student class to fully encapsulate a student.
Be sure to include several data members that are dynamically allocated. Provide
several overloaded constructors to provide a means to initialize your class. Be sure
to include a copy constructor. Also, include a destructor to release any dynamically
allocated data members.

b. Add an assortment of access functions to your class to provide safe access to
data members within your class. Decide for which data members you will offer a
GetDataMember() interface, and if any of these data members should have the
ability to be reset after construction with a SetDataMember() interface. Apply
the const and inline qualifiers to these methods as appropriate.

c. Be sure to utilize appropriate access regions – private for data members, and
possibly for some helper member functions to break up a larger task. Add public
member functions as necessary above and beyond your access functions above.

d. Include at least one const data member in your class and utilize the member
initialization list to set this member. Add at least one static data member and one
static member function.

e. Instantiate a Student using each constructor signature, including the copy
constructor. Make several instances dynamically allocated using new(). Be sure
to delete() each of these instances when you are done with them (so that their
destructor will be called).
*/

class Student
{
private:
    // Data members
    string firstName;
    string lastName;
    char middleInitial;
    float gpa;
    char* currentCourse;
    const int studentID;
    static int numStudents;

public:
    // Constructors
    Student();
    Student(const string &, const string &, char, float, const char*, int);
    Student(const Student &);
    ~Student();

    // Inline function declarations
    const string &getFirstName() const { return firstName; }
    const string &getLastName() const { return lastName; }
    char getMiddleInitial() const { return middleInitial; }
    float getGpa() const { return gpa; }
    const char* getCurrentCourse() const { return currentCourse; }

    // Member functions
    static int getNumberStudents();
    void setCurrentCourse(const char*);
    void Print();

};
// Static variables
int Student::numStudents = 0;

// Class member functions declarations
inline int Student::getNumberStudents()
{
    return numStudents;
}
inline void Student::setCurrentCourse(const char* course)
{
    currentCourse = new char[strlen(course) + 1];
    strcpy(currentCourse, course);
}
Student::Student() : firstName(""), lastName(""), middleInitial('\0'), gpa(0), currentCourse(nullptr), studentID(0)
{
    numStudents++;
}    
Student::Student(const string &fn, const string &ln, char mi, float gpa, const char* course, int id) : studentID(id)
{
    firstName = fn;
    lastName = ln;
    middleInitial = mi;
    this->gpa = gpa;
    currentCourse = new char[strlen(course) + 1];
    strcpy(currentCourse, course);
    numStudents++;
}
Student::Student(const Student &s) : studentID(s.studentID)
{
    firstName = s.firstName;
    lastName = s.lastName;
    middleInitial = s.middleInitial;
    gpa = s.gpa;
    currentCourse = new char[strlen(s.currentCourse) + 1];
    strcpy(currentCourse, s.currentCourse);
    numStudents++;
}
Student::~Student()
{
    delete currentCourse;
    numStudents--;
    cout << "Student " << this->firstName << " has been deleted from memory" << endl;
}
void Student::Print()
{
    cout << "\nSTUDENT WITH ID " << studentID << '\n';
    cout << firstName << " " << lastName;
    cout << " has earned a gpa of " << gpa << " ";
    cout << "in " << currentCourse << '\n';
    cout << "Total number of students: " << Student::getNumberStudents() << endl;
}

int main()
{
    // Default constructor call
    Student* s1 = new Student;
    // Alternate constructor call
    Student s2("Nestor", "Na", 'N', 4.0, "Advanced C++ OP", 11);
    s2.Print();
    // Copy constructor call
    Student s3(s2);
    s3.setCurrentCourse("UE5");
    s3.Print();

    delete s1;
    return 0;
}