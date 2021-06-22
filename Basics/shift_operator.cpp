#include <iostream>

using namespace std;

int main() {

    // a = 5(00000101), b = 6(00000110)
    int a1 = 5, b1 = 6;
    int a2 = a1<<3, b2 = b1>>1;

    cout << "a1: " << a1 << " | b1: " << b1 << '\n';
    cout << "a2: " << a2 << " | b2: " << b2 << endl;
}

//$ Left shifting an integer “x” with an integer “y” denoted as ‘(x<<y)’
//$ is equivalent to multiplying x with 2^y (2 raised to power y). 