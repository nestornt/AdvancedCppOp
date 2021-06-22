// Initialization lists with const data members
#include <iostream>  

using std::cout;
using std::endl;
using std::string;

class Student
{
private: 
    // data members
    string firstName;
    string lastName;
    char middleInitial;
    float gpa;
    string currentCourse;  // let's finally convert this to a std::string -- we've illustrated most ptr special needs within classes by now 
    const int studentId;   // constant data member
public:
    // member function prototypes
    Student();  // default constructor
    Student(const string &, const string &, char, float, const string &, int); 
    Student(const Student &);  // copy constructor
    ~Student();  // destructor
    void Print();
    const string &GetFirstName() { return firstName; }  
    const string &GetLastName() { return lastName; }    
    char GetMiddleInitial() { return middleInitial; }
    float GetGpa() { return gpa; }
    const string &GetCurrentCourse() { return currentCourse; }
    void SetCurrentCourse(const string &);  // prototype only
};

inline void Student::SetCurrentCourse(const string &c)
{
    currentCourse = c;   // the implementation using the string is far simplier
}

// Member init. list is used to set data members 
Student::Student() : firstName(""), lastName(""), middleInitial('\0'), gpa(0.0), currentCourse(""), studentId(0)  
{
   // even though string data members, firstName, lastName, currentCourse are initialized with empty strings
   // (string is a class and does so for us), it is still better practice to initialize all members yourself (see mbr init list above)
   // note: you may still initialize data members here, but using member initialization list is more efficient
}

// member init. list is used to set data members 
Student::Student(const string &fn, const string &ln, char mi, float avg, const string &course, int id) : 
                 firstName(fn), lastName(ln), middleInitial(mi), gpa(avg), currentCourse(course), studentId (id)
{
   // note: for string data members, the above initialization is calling the constructor matching the signature of item in ()'s
   // this is inevitably more efficient than default constructing the data member and then assigning it with a new value in the method body
   // note: any pointer data members often need to be set within body of function (but can sometimes be set in init. list too)
}

// member init. list used to set studentId
Student::Student(const Student &s) : firstName(s.firstName), lastName(s.lastName), middleInitial(s.middleInitial), 
                                     gpa(s.gpa), currentCourse(s.currentCourse), studentId (s.studentId)
{
   // remember to do a deep copy for any data members that are pointers
}

Student::~Student()
{
   // remember to delete memory for any data members that are pointers
}

void Student::Print()
{
    cout << firstName << " " << middleInitial << ". ";
    cout << lastName << " with id: " << studentId;
    cout << " and gpa: " << gpa << " is enrolled in: ";
    cout << currentCourse << endl;

}

int main()
{
    Student s0; // Call default constructor
    Student s1("Renee", "Alexander", 'Z', 3.7, "C++", 1290);
    s1.SetCurrentCourse("Python");

    cout << s1.GetFirstName() << " " << s1.GetLastName();
    cout <<  " has gpa of: " << s1.GetGpa();
    cout << " and is cursing " << s1.GetCurrentCourse() << endl;

    return 0;
}