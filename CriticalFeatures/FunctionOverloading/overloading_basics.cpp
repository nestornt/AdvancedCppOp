#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

const float PI = 3.14159;

class Circle
{
public:
   float radius;
   float area;
};

class Rectangle
{
public:
   float length;
   float width;
   float area;
};

// function prototypes
void display(Circle);     
void display(Rectangle);  // These functions are overloaded
                          // since they differ in signature

int main()
{
   Circle myCircle;
   Rectangle myRect;
   Rectangle mySquare;

   myCircle.radius = 5.0;
   myCircle.area = PI * pow(myCircle.radius, 2.0);

   myRect.length = 2.0;
   myRect.width = 4.0;
   myRect.area = myRect.length * myRect.width;

   mySquare.length = 4.0;
   mySquare.width = 4.0;
   mySquare.area = mySquare.length * mySquare.width;

   display(myCircle);
   display(myRect);
   display(mySquare);

   return 0;
}

void display (Circle c)
{
   cout << "Circle with radius " << c.radius << " has an area of ";
   cout << c.area << endl; 
}
   
void display (Rectangle r)
{
   cout << "Rectangle with length " << r.length << " and width "; 
   cout << r.width << " has an area of " << r.area << endl; 
}