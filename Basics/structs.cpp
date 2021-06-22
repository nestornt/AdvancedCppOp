#include <iostream>
#include <cstring>

using namespace std;

struct Student
{
    char name[20];
    float semesterGrades[5];
    float gpa;
};

int main()
{
    Student s1;
    // We use strcpy to set the value of an array of characters
    strcpy(s1.name, "George Katz");
    s1.semesterGrades[0] = 3.0;
    s1.semesterGrades[1] = 4.0;
    s1.gpa = 3.5;
    cout << s1.name << " has GPA: " << s1.gpa << endl;
    return 0;
}

/* 

$ strcpy() 
$ Is a standard library function in C/C++ and is used to copy
$ one string to another. In C it is present in string.h header
$ file and in C++ it is present in cstring header file.

Parameters: This method accepts the following parameters:  

dest: Pointer to the destination array where the content is to be copied.
src: string which will be copied

Return Value: After copying the source string to the destination string, 
the strcpy() function returns a pointer to the destination string.  

*/