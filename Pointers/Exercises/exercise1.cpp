#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Student
{
public:
   
    char *first_name;
    char *second_name;
    char *current_course_enrolled;

    void ReadData(Student *);
    void PrintData(const Student *);
    void PrintData();
};

void Student::ReadData(Student *p)
{
    char first_name[15];
    char second_name[20];
    char course[15];

    cout << "Introduce tu nombre, primer apellido y curso actual ";
    cin >> setw(15) >> first_name >> setw(20) >> second_name >> setw(15) >> course;

    p->first_name = new char[sizeof(first_name)];
    p->second_name = new char[sizeof(second_name)];
    p->current_course_enrolled = new char[sizeof(course)];

    strcpy(p->first_name, first_name);
    strcpy(p->second_name, second_name);
    strcpy(p->current_course_enrolled, course);
}

void Student::PrintData(const Student *p)
{
    cout << "Nombre: " << p->first_name << '\n';
    cout << "Apellido: " << p->second_name << '\n';
    cout << "Curso Actual: " << p->current_course_enrolled << endl;
}

void Student::PrintData()
{
    cout << "Nombre: " << first_name << '\n';
    cout << "Apellido: " << second_name << '\n';
    cout << "Curso Actual: " << current_course_enrolled << endl;
}


int main()
{
    Student *s1;
    s1 = new Student;
    
    s1->ReadData(s1);
    s1->PrintData(s1);
    s1->PrintData();
    
    delete s1->first_name;
    delete s1->second_name;
    delete s1->current_course_enrolled;
    delete s1;
                
    return 0;
}
