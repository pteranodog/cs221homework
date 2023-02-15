// Shape.cpp : This file contains the Shape class implementation for program 1B
//  
// Author: Drew Early
// email: jae0025@uah.edu
// For: CS221-02, Spring 2023 
// For Mrs. Delugach 

#include "Shape.h"
#include <iostream>
#include <string>

using namespace std;

Shape::Shape()
{
    shapeType = "undefined shape";
    numSides = 0;
    fillColor = "clear";
    borderColor = "clear";
}

Shape::~Shape()
{
    cout << "Misshapion Complete." << endl;
}

string Shape::GetShapeType()
{
    return shapeType;
}

int Shape::GetNumSides()
{
    return numSides;
}

string Shape::GetFillColor()
{
    return fillColor;
}

string Shape::GetBorderColor()
{
    return borderColor;
}

void Shape::SetFillColor(string newFillColor)
{
    fillColor = newFillColor;
}

void Shape::SetBorderColor(string newBorderColor)
{
    borderColor = newBorderColor;
}

void Shape::SetShapeType(string newShapeType)
{
    shapeType = newShapeType;
}

void Shape::SetNumSides(int newNumSides)
{
    numSides = newNumSides;
}

int Shape::GetPerimeter()
{
    return 0;
}

float Shape::GetArea()
{
    return 0.0;
}