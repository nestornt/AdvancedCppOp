#include <iostream>
#include <cstring>

using namespace std;

char suffix = 'A';
const char *genId(const char *); // function prototype

int main()
{
    const char *newId1, *newId2; // pointer declarations
    newId1 = genId("Group"); // function will allocate memory
    newId2 = genId("Group");
    cout << "New ids: " << newId1 << " " << newId2 << endl;
    delete newId1; // delete allocated memory
    delete newId2;
    return 0;
}

const char *genId(const char *base)
{
    char *temp = new char[strlen(base) + 2];
    strcpy(temp, base); // use base to initialize string

    // Adds suffix variable at the end of the string literal array,
    // Where the null character "\0" was, so we add it again
    temp[strlen(base)] = suffix++; // Append suffix to base
    temp[strlen(base) + 1] = '\0'; // Add null character

    return temp; // temp will be up-cast to a const char *
}

// Just a const char * value can capture the result of a 
// const char * function return value