// Circle.cpp : This file contains the Circle class implementation for program 1B
//  
// Author: Drew Early
// email: jae0025@uah.edu
// For: CS221-02, Spring 2023 
// For Mrs. Delugach 

#include "Circle.h"
#include <string>
#include <iostream>

using namespace std;

Circle::Circle()
{
    SetShapeType("circle");
    SetNumSides(1);
    radius = 1;
    SetFillColor("red");
    SetBorderColor("orange");
}

Circle::Circle(int radius, string fillColor, string borderColor)
{
    SetShapeType("circle");
    SetNumSides(1);
    SetRadius(radius);
    SetFillColor(fillColor);
    SetBorderColor(borderColor);
}

Circle::~Circle()
{
    cout << "Target destroyed. Recircalibrating." << endl;
}

int Circle::GetRadius()
{
    return radius;
}

void Circle::SetRadius(int newRadius)
{
    radius = abs(newRadius);
}

int Circle::GetPerimeter()
{
    // Circumference should not be int, but spec requires int, so I let int be!
    // I'm sure that was un-int-entional.
    return (int)(2.0 * PI * (float)radius);
}

float Circle::GetArea()
{
    return PI * (float)radius * (float)radius;
}