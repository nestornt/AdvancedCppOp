#include <iostream>

using namespace std;

int main()
{
    void *unspecified; // void * may point to any data type
    int *x;
    unspecified = new int; // the void * now points to an int
    // void * must be cast to int * before it is dereferenced
    *((int *) unspecified) = 89;
    // let x point to the memory which unspecified points to
    x = (int *) unspecified;
    cout << *x << " " << *((int *) unspecified) << endl;
    
    return 0;
}