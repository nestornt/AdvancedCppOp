#include <iostream>

using namespace std;

void AddOne(int &);
void AddOne(int *);
void Display(int &);

int main()
{
    int x = 10, *y;
    y = new int;
    *y = 15; 
    Display(x);
    Display(*y);

    AddOne(x); // calls reference version (with an object)
    AddOne(*y); // also calls reference version
    Display(x); // Based on prototype, we see we are passing
    Display(*y); // by reference. Without prototype, we might

    // have guessed it was by value.
    AddOne(&x); // calls pointer version
    AddOne(y); // also calls pointer version
    Display(x);
    Display(*y);

    return 0;
}

void AddOne(int &arg) // These two functions are overloaded
{
    arg++;
}
void AddOne(int *arg) // Overloaded function definition
{
    (*arg)++;
}
void Display(int &arg) // This fn passes a reference to arg
{
    cout << arg << " " << flush;
}