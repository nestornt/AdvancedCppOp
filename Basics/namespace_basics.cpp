#include <iostream>
using namespace std;

namespace DataTypes
{
    int total;
    class LinkList
    {
        // full class definition …
    };
    class Stack
    {
        // full class definition …
    };
};
namespace AbstractDataTypes
{
    class Stack
    { 
        // full class definition …
    };
    class Queue
    {
        // full class description …
    };
};
// Add entries to the AbstractDataTypes namespace
//! Repeated namespace augments its first occurrence
namespace AbstractDataTypes
{
    int total;
    class Tree
    {
        // full class definition …
    };
};

int main()
{
    using namespace AbstractDataTypes; // activate namespace
    using DataTypes::LinkList; // activate only LinkList

    LinkList list1; // LinkList is found in DataTypes
    Stack stack1; // Stack is found in AbstractDataTypes
    total = 5; // we use cin to read into total from active AbstractDataTypes
    DataTypes::total = 85; // specify non-active member, total 
    cout << "total " << total << "\n";
    cout << "DataTypes::total " << DataTypes::total << endl;
    return 0;
}