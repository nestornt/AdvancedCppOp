#include <iostream>

using namespace std;

int maximum(double, double);

int main()
{
    int result;
    int m = 6, n = 10;
    float x = 5.7, y = 9.89;
    result = maximum(x, y);
    cout << "Result is: " << result << endl;
    cout << "The maximum is: " << maximum(m, n) << endl;
    return 0;
}

// The returned value of this function will be truncated as an INT
int maximum(double a, double b)
{
    return (a > b)? a : b;
}