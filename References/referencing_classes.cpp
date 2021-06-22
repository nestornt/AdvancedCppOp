#include <iostream>
#include <cstring>

using namespace std;

class Student
{
public:
    char name[20];
    float gpa;
};

int main()
{
    Student s1;
    Student &sRef = s1; // establish a reference to s1
    
    strcpy(s1.name, "Katje Katz"); // fill in the data
    s1.gpa = 3.75;
    cout << s1.name << " has GPA: " << s1.gpa << endl;
    cout << sRef.name << " has GPA: " << sRef.gpa << endl;

    strcpy(sRef.name, "George Katz"); // change the data
    sRef.gpa = 3.25;
    cout << s1.name << " has GPA: " << s1.gpa << endl;
    cout << sRef.name << " has GPA: " << sRef.gpa << endl;

    return 0;
}