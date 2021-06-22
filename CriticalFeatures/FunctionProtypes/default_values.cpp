#include <iostream>
using namespace std;

int minimum(int arg1, int arg2 = 4); // function prototype
                                          // with one default value
int main()
{
    int x = 5, y = 89;
    cout << minimum(x) << endl; // function call with only
                                // one argument (uses default)

    cout << minimum(x, y) << endl; // no default values used
    return 0;
}
int minimum(int a, int b) // function definition
{
    return (a < b)? a : b;
}