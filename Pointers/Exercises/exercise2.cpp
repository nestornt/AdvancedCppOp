#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

struct Student
{
    const char *name;
    char second_name[20];
    char group[15];
    float gpa = 1.5;

};

int main()
{
    Student s1;

    //$ 1. Asssign a pointer to a constant object, filling it.
    char *ptr_a = new char[4];
    strcpy(ptr_a, "Name");
    s1.name = ptr_a;

    //$ 2. Declaration for a constant pointer to a non-constant object
    strcpy(s1.second_name, "Second Name");
    char *const ptr_b = s1.second_name;
    strcpy(ptr_b, "New Second Name");

    //$ 3. Declaration for a constant pointer to a constant object
    strcpy(s1.group, "Art");
    const char *const ptr_c = s1.group;

    cout << s1.name << '\n';
    cout << ptr_b << '\n';
    cout << ptr_c << endl; 

    delete ptr_a;
    
    return 0;
}