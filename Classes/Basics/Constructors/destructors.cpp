#include <iostream>  
#include <cstring>

using std::cout;
using std::endl;
using std::string;

class University
{
private:
    char *name;
    int numStudents;   
public: 
    // constructor prototypes
    University(); // default constructor
    University(const char *, int);  // alternate constructor
    University(const University &);  // copy constructor
    ~University();  // destructor prototype
    void Print();
};

University::University()  // default constructor
{
    name = nullptr;  
    numStudents = 0;
}

University::University(const char * n, int num)  // alt constructor
{
    name = new char [strlen(n) + 1];      // allocate memory for ptr data members
    strcpy(name, n);
    numStudents = num;
}

University::University(const University &u) // copy const
{
    name = new char [strlen(u.name) + 1];  // deep copy data members that are pointers
    strcpy(name, u.name);
    numStudents = u.numStudents;
}

University::~University()  // destructor definition
{
    delete name;   // be sure to deallocate any dynamically allocoated memory
    cout << "Destructor called " << this << endl;
}

void University::Print()
{
    cout << "University: " << name;
    cout << " Enrollment: " << numStudents << endl;
}

int main()
{
    University u1("Temple University", 39500);
    University *u2 = new University("Boston U", 32500);
    University u3("Rand Univeristy", 232000);
    u1.Print();
    u2->Print();
    u3.Print();
    cout << "Print u1 address: " << &u1 << "\n";
    cout << "Print u2 address: " << u2 << "\n";
    cout << "Print u3 address: " << &u3 << "\n";

    delete u2;   // destructor will be called before delete()
                 // destructor for u2 and u1 will be called before program completes 
    return 0;    
}