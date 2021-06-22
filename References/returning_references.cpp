#include <iostream>

using namespace std;

int &CreateId();


int main()
{
    int &id1 = CreateId();
    int &id2 = CreateId();
    cout << "Id1: " << id1 << " Id2: " << id2 << endl;
    delete &id1; // Here, '&' is address-of, not reference
    delete &id2; // to calculate address to pass delete()

    return 0;
}

//$ With return by reference and static variable keyword
//$ we can return the value created within the function
int &CreateId() // Function returns a reference to an int
{
    static int count = 100;  // initialize with first id

    // heap memory allocation to hold the 
    // variable after the function ends up
    int *memory = new int;  
    *memory = count++; // use count as id, then increment

    return *memory;
}