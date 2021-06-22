#include <iostream>
using namespace std;

// the name args are ignored by the compiler
int minimum(int arg1, int arg2); // function prototype with
                                 // optional argument names
int main()
{
    int x = 5, y = 89;
    cout << minimum(x, y) << endl;
    return 0;
}
int minimum(int a, int b)
{
    return (a < b)? a : b;
}