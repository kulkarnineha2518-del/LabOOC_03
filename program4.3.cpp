//Function area() is overloaded three times
#include<iostream>
using namespace std;

//Declaration of Function Prototypes
int area (int);
int area (int, int);
float area (float);

int main()
{
    cout<< "Calling the area() function for computing the area of a square (side = 3) - " <<area(3)<<"\n";
    cout<< "Calling the area() function for computing the area of a rectangle (length = 3, breadth = 6) - " <<area(3,6)<<"\n";
    cout<< "Calling the area() function for computing the area of a circle (radius =3.3) - " <<area(3.3f);
    return 0;
}

int area (int side)                     //Area of square
{
    return(side*side);
}

int area (int length, int breadth)      //Area of rectangle
{
    return(length*breadth);
}

float area (float radius)               //Area of circle
{
    return(3.14*radius*radius);
}
