#include <iostream>

using namespace std;

// function prototypes
void TryToAddOne(int);
void AddOne(int *);

int main()
{
    int x = 10, *y; // int variable and mem address declaration
    y = new int; // allocate y's memory of an INT size
    *y = 15; // dereference y to assign a value
    cout << "x: " << x << " and *y: " << *y << endl;

    TryToAddOne(x); // unsuccessful, call by value
    TryToAddOne(*y); // still unsuccessful
    cout << "x: " << x << " and *y: " << *y << endl;
    
    AddOne(&x); // successful, passing an address
    AddOne(y); // also successful
    cout << "x: " << x << " and *y: " << *y << endl;

    return 0;
}

void TryToAddOne(int arg)
{
    arg++;
}
void AddOne(int *arg)
{
    (*arg)++;
}   