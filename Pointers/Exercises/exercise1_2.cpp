#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Student
{
public:
    const size_t students = 3;
    char first_name[15];
    char second_name[20];
    char course[15];

    void PrintData(const Student *, int position);
    void SetStudents(Student *, int size);
};


void Student::PrintData(const Student *p, int position)
{
  
    cout << "Nombre: " << p->first_name[position] << '\n';
    cout << "Apellido: " << p->second_name[position] << '\n';
    cout << "Curso Actual: " << p->course[position]<< endl;

}

void Student::SetStudents(Student *arr, int size)
{
    char temp_first_name[15];
    char temp_second_name[20];
    char temp_course[15];

   for(size_t i = 0; i < size; i++)
   {
    cout << "Introduce tu nombre, primer apellido y curso actual "; 
    cin >> setw(15) >> arr->first_name[i] >> setw(20) >> arr->second_name[i] >> setw(15) >> arr->course[i];
    cout << "Nombre: " << arr->first_name[i] << '\n';
    cout << "Apellido: " << arr->second_name[i] << '\n';
    cout << "Curso Actual: " << arr->course[i] << '\n'; 
   }
   cout << endl;
}

int main()
{
    const size_t students = 3;

    Student *arr_students;
    arr_students = new Student[students];

    arr_students->SetStudents(arr_students, students);
    delete arr_students;
                
    return 0;
}