#include <iostream>

using namespace std;

struct collection
{
    int x;
    float y;
};

int main()
{
    int numElements;
    int *intArray; // pointer declarations
    collection *collectionArray; // pointer declaration to eventual arrays

    cout << "How many elements would you like? " << flush;
    cin >> numElements;

    // allocate array with size of an INT of nunElements
    intArray = new int[numElements];
    // allocate array with size of collection struct of nunElements 
    collectionArray = new collection[numElements];

    // load each array with values
    for (int i = 0; i < numElements; i++)
    {
        intArray[i] = i; // load each array w values
        collectionArray[i].x = i; // using array notation []
        collectionArray[i].y = i + .5;

        // alternatively use ptr notation to print two values
        cout << *(intArray + i) << " ";
        // We first add "i" to the starting address of collectionArray,
        // then using () we deference it
        cout << (*(collectionArray + i)).y << endl;
    }
    
    delete intArray; // mark memory for deletion
    delete [] collectionArray; // [] is necessary for delettion of user
                               // defined types like a struct
    return 0;
}