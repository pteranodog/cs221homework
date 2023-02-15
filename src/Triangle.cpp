// Triangle.cpp : This file contains the Triangle class implementation for program 1B
//  
// Author: Drew Early
// email: jae0025@uah.edu
// For: CS221-02, Spring 2023 
// For Mrs. Delugach 

#include "Triangle.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

Triangle::Triangle()
{
    SetShapeType("triangle");
    SetNumSides(3);
    SetSides(2);
    SetFillColor("yellow");
    SetBorderColor("green");
}

Triangle::Triangle(int newSide, string newFillColor, string newBorderColor)
{
    SetShapeType("triangle");
    SetNumSides(3);
    SetSides(newSide);
    SetFillColor(newFillColor);
    SetBorderColor(newBorderColor);
}

Triangle::~Triangle()
{
    std::cout << "Target neutriangleized. Recalibrating." << std::endl;
}

int Triangle::GetSides()
{
    return side;
}

void Triangle::SetSides(int newSide)
{
    side = abs(newSide);
}

int Triangle::GetPerimeter()
{
    return side * 3;
}

float Triangle::GetArea()
{
    float semiPerimeter = (float)side * 1.5;
    return sqrt(semiPerimeter * (semiPerimeter - (float)side) * (semiPerimeter - (float)side) * (semiPerimeter - (float)side));
}