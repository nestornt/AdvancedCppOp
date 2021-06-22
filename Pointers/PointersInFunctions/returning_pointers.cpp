// Using operator New to allocate the mememory on the heap,
// then will be possible to obtain the function´s return value
// since it won't be placed on the stack as copy value
#include <iostream>
#include <iomanip>

using namespace std;
const int MAX = 20;

char *createName(); // function prototype

int main()
{
    char *name; // pointer declaration
    name = createName(); // function will allocate memory
    cout << "Name: " << name << endl;
    delete name; // delete allocated memory

    return 0;
}
// When returning a pointer from a function, always ensure that
// the memory that the pointer points to exists beyond the
// extent of the function.
char *createName()
{
    char *temp = new char[MAX]; // Declaration + memory allocation
    cout << "Enter name: " << flush;
    cin >> setw(MAX) >> temp;

    return temp;
}