// Triangle.h : This file contains the Triangle class header for program 1B
//  
// Author: Drew Early
// email: jae0025@uah.edu
// For: CS221-02, Spring 2023 
// For Mrs. Delugach 

#pragma once
#include "Shape.h"
#include <string>

using namespace std;

class Triangle : public Shape
{
private:
    int side;

public:
    Triangle();
    Triangle(int sideOne, string newFillColor, string newBorderColor);
    ~Triangle();

    int GetSides();
    void SetSides(int newSide);

    int GetPerimeter();
    float GetArea();
};