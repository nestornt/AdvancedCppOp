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
    string currentCourse;
    const int studentId;   // constant data member
public:
    // member function prototypes
    Student();  // default constructor
    Student(const string &, const string &, char, float, const string &, int);
    Student(const Student &);  // copy constructor
    ~Student();  // destructor
    void Print() const;            // most of these member functions are const
    const string &GetFirstName() const { return firstName; }  
    const string &GetLastName() const { return lastName; }    
    char GetMiddleInitial() const { return middleInitial; }
    float GetGpa() const { return gpa; }
    const string &GetCurrentCourse() const { return currentCourse; }
    int GetStudentId() const { return studentId; }
    void SetCurrentCourse(const string &);  // prototype only
};

inline void Student::SetCurrentCourse(const string &c)
{
    currentCourse = c;   // the implementation using the string is far simplier
}


// default constructor 
Student::Student() : firstName(""), lastName(""), middleInitial('\0'), gpa(0.0), currentCourse(""), studentId(0)
{
   // even though string data members, firstName, lastName, currentCourse are initialized with empty strings
   // (string is a class and does so for us), it is still better practice to initialize all members yourself (see mbr init list above)
   // note: you may still initialize data members here, but using member initialization list is more efficient

}

// alternate constructor 
Student::Student(const string &fn, const string &ln, char mi, float avg, const string &course, int id) :
                 firstName(fn), lastName(ln), middleInitial(mi), gpa(avg), currentCourse(course), studentId (id)
{
   // note: for string data members, the above initialization is calling the constructor matching the signature of item in ()'s
   // this is inevitably more efficient than default constructing the data member and then assigning it with a new value in the method body
   // note: any pointer data members often need to be set within body of function (but can sometimes be set in init. list too)
}

// copy constructor 
Student::Student(const Student &s) : firstName(s.firstName), lastName(s.lastName), middleInitial(s.middleInitial),
                                     gpa(s.gpa), currentCourse(s.currentCourse), studentId (s.studentId)
{
   // remember to do a deep copy for any data members that are pointers
}

Student::~Student()
{
   // remember to delete memory for any data members that are pointers
}

// Data members pointed by this cant be modified in this function
// Functions called inside Print must be const to avoid mofifying this
void Student::Print() const
{
    cout << firstName << " " << middleInitial << ". ";
    cout << lastName << " with id: " << studentId;
    cout << " and gpa: " << gpa << " is enrolled in: ";
    cout << currentCourse << endl;
    // SetCurrentCourse(); // Error
}

int main()
{
   Student s1("Zack", "Moon", 'R', 3.85, "C++", 1378); 
   cout << s1.GetFirstName() << " " << s1.GetLastName();
   cout << " Enrolled in " << s1.GetCurrentCourse() << endl;
   s1.SetCurrentCourse("Advanced C++ Programming");  
   cout << s1.GetFirstName() << " " << s1.GetLastName();
   cout << " New course: " << s1.GetCurrentCourse() << endl;

   const Student s2("Gabby", "Doone", 'A', 3.9, "C++", 2239);
   s2.Print();
   
   // s2.SetCurrentCourse("Advanced C++ Programming"); // Not allowed, s2 is const

   return 0;
}