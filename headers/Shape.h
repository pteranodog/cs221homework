// Shape.h : This file contains the Shape class header for program 1B
//  
// Author: Drew Early
// email: jae0025@uah.edu
// For: CS221-02, Spring 2023 
// For Mrs. Delugach 

#pragma once
#include <string>

using namespace std;

class Shape
{
private:
    string shapeType;
    int numSides;
    string fillColor;
    // I definitely considered losing credit just to rename "borderColor" to "borderCollie"
    // Unfortunately I decided my grades are more important
    string borderColor;

protected:
    void SetShapeType(string newShapeType);
    void SetNumSides(int newNumSides);

public:
    Shape();
    ~Shape();

    string GetShapeType();
    int GetNumSides();
    string GetFillColor();
    string GetBorderColor();
    void SetFillColor(string newFillColor);
    void SetBorderColor(string newBorderColor);

    int GetPerimeter();
    float GetArea();
};