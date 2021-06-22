#include <iostream>
 
using std::cout;
using std::endl;

int minimum(int, int);

// local prototype with default value
void function1(int x) {
    int minimum(int arg1, int arg2 = 500);
   
    cout << minimum(x) << endl;
}

// local prototype with default value
void function2(int x) {
    int minimum(int arg1, int arg2 = 90);
   
    cout << minimum(x) << endl;
}

// function definition with formal parameters
int minimum(int a, int b) { 

    if (a < b)
        return a;
    else
        return b;
}

int main() {
    function1(30);
    function2(450);

    return 0;
}