#include <iostream>

using namespace std;

int maximum (int, int); // overloaded function prototypes
float maximum (float, float);

int main()
{
    char a = 'A', b = 'B';
    float x = 5.7, y = 9.89;
    int m = 6, n = 10;
    cout << "The max is: " << maximum(a, b) << endl;
    cout << "The max is: " << maximum(x, y) << endl;
    cout << "The max is: " << maximum(m, n) << endl;
    // The following (ambiguous) line generates a compiler
    // error since there are two equally good fn. candidates
    // cout << "The maximum is: " << maximum(a, y) << endl;
    //! We can force a choice by using an explicit typecast
    cout << "The max is: " << maximum((float)a, y) << endl;
    return 0;
}

int maximum (int arg1, int arg2) // function definition
{
    return (arg1 > arg2)? arg1 : arg2;
}
float maximum (float arg1, float arg2) // overloaded function
{
    return (arg1 > arg2)? arg1 : arg2;
}

// Return types are not part of the function signature, so they need not match 