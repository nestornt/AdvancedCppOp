#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    //! Using pointers to constant objects
    // const qualified strings; the data pointed to will be const
    const char *constData = "constant";
    const char *moreConstData;
    // regular strings, defined. One is loaded using strcpy()
    char *regularString;
    char *anotherRegularString = new char[8];
    strcpy(anotherRegularString, "regular");
    // Trying to modify data marked as const will not work
    // strcpy(constData, "Can I do this? "); // NO!
    // Trying to circumvent by having a char * point to
    // a const char * also will not work
    // regularString = constData; // NO!
    //$ But we can treat a char * more strictly by assigning it to
    //$ a const char *. It will be const from that viewpoint only
    moreConstData = anotherRegularString; // Yes, I can do this!
    

    cout << &anotherRegularString << " " << moreConstData << endl;

    /* -------------------------------------------------------------------- */
    //! Using constant pointers to objects
    // Define, allocate, load two regular strings using strcpy()
    char *regularString2 = new char[36];
    strcpy(regularString2, "I am a string which can be modified");
    char *anotherRegularString2 = new char[21];
    strcpy(anotherRegularString2, "I am also modifiable");

    // Define a const pointer to a string. It must be initialized
    char *const constPtrString = regularString2; // Ok

    //$ You may not modify a const pointer to point elsewhere
    // constPtrString = anotherRegularString; //No!
    // But you may change the data which you point to
    strcpy(constPtrString, "I can change the value"); // Yes 
    // It works because its modifying only its value no the mem address

    /* -------------------------------------------------------------------- */
    //! Using constant pointers to constant objects
    // Define two regular strings and load using strcpy()
    char *regularString3 = new char[36];
    strcpy(regularString3, "I am a string which can be modified");
    char *anotherRegularString3 = new char[21];
    strcpy(anotherRegularString3, "I am also modifiable");

    // Define a const ptr to a const object. Must be initialized
    const char *const constStringandPtr = regularString3; // Ok
    cout << &constStringandPtr << " " << &regularString3 << endl;

    //$ Trying to change the pointer or the data is illegal
    // constStringandPtr = anotherRegularString; //No! Can't mod addr
    // strcpy(constStringandPtr, "Nope"); // No! Can't mod data
    
    return 0;
}