// Using pointers with user defined types
#include <iostream>

using namespace std;

struct collection
{
    int x;
    float y;
};

int main() {
    collection *item; // pointer declaration
    item = new collection; // memory assignation
    item->x = 9; // use -> to access data member x
    (*item).y = 120.77; // alt. notation to access member y
    cout << (*item).x << " " << item->y << endl;
    delete item; // drop the memory address
    
    return 0;
}

/*

    - item->x   indicates the pointer deference followed by a
                class member selection

    - (*item).y pointer deference happens first, then we access
                to its class member

*/