#include <iostream>

using namespace std;

const int NUMROWS = 4;

int main() {

    // declare an array of pointers
    float *TwoDimArray[NUMROWS];
    int numColumns;
    cout << "Enter the number of rows " << flush;
    cin >> numColumns;

    for (size_t i = 0; i < NUMROWS; i++)
    {
        // allocate column quantaty for each row
        TwoDimArray[i] = new float[numColumns];

        for (size_t j = 0; j < numColumns; j++)
        {
            TwoDimArray[i][j] = i + j + 0.5;
            cout << TwoDimArray[i][j] << "  ";
        }
        cout << endl;
    }

    // deallocate the memory of each row
    // it will delete each memory address
    // each memory address(row) cointains n columns
    for (size_t i = 0; i < NUMROWS; i++)
    {
        delete TwoDimArray[i];
    }

    return 0;
}