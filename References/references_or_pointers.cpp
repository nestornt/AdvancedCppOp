// This example illustrates when to use a pointer o reference
#include <iostream>

using namespace std;

int main()
{
    //$ Example of reference declaration under the hood
    int x = 10;
    int y = 15;
    int &intVar = x; // This is the same -> int *const intVar = &x;
                     // References are constant even if not specified

    cout << intVar << " " << x << endl;

    //! Cant do that -->  &intVar = y;
    //! But this is allowed --> intVar = 1;
    // It can modify its value, modifying the value pointed
    // to by the referenced variable as well, but it cannot point
    // to another memory address, since its a const pointer

    //$ Program
    int *ptr = new int;
    *ptr = 20;
    int *&refPtr = ptr; // Establish a reference to a pointer, the 
                        // pointer referenced is pointing to an int
                        // It is a pointer to a pointer to an int
    cout << *ptr << " " << *refPtr << endl;

    return 0;
}