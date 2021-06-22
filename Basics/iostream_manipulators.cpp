#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    

    char name[20];
    // grade point average (Calificacion media)
    float gpa;
    cout << "Please enter a name and a gpa: ";
    // Sets the names size to 20 as max
    cin >> setw(20) >> name >> gpa;
    cout << "Hello " << name << flush;
    cout << ". GPA is: " << setprecision(3) << gpa << endl;
    return 0;
}



//$ • endl: Places a newline character in the buffer associated with cout then flushes
//$         the buffer
//$ • flush: Clears the contents of the output stream
//!   Avoid using endl where the new-line character is required but buffer flushing
//!   is not because endl has a much higher overhead than using the new-line character
//$ • setprecision(int): Sets floating-point precision
//$ • setw(int): Sets width for input and output
//$ • ws: Removes whitespace characters from the buffer
//std::ios::sync_with_stdio(false);