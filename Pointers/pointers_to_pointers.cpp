#include <iostream>

using namespace std;

int main()
{
    int numRows, numColumns;
    float **TwoDimArray; // pointer to a pointer (->->)
    cout << "Enter number of rows: " << flush;
    cin >> numRows;

    // This allocation creates numRows quantity of float pointers
    //! Creates numRows memory addresses inside TwoDimArray address
    TwoDimArray = new float * [numRows];

    cout << "Enter number of Columns: ";
    cin >> numColumns;

    for (int i = 0; i < numRows; i++)
    {
        // allocate column quantity for each row
        TwoDimArray[i] = new float [numColumns];
        // load each column entry with data
        for (int j = 0; j < numColumns; j++)
        {
            TwoDimArray[i][j] = i + j + .05;
            cout << TwoDimArray[i][j] << " ";
        }
            cout << endl; // print newline between rows
    }
    for (int i = 0; i < numRows; i++)
        delete TwoDimArray[i]; // delete columns for each row

    delete TwoDimArray; // delete allocated rows

    return 0;
}