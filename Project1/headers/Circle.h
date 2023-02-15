// Circle.h : This file contains the Circle class header for program 1B
//  
// Author: Drew Early
// email: jae0025@uah.edu
// For: CS221-02, Spring 2023 
// For Mrs. Delugach 

#pragma once
#include "Shape.h"
#include <string>

using namespace std;

class Circle : public Shape
{
private:
    int radius;
    const float PI = 3.14;

public:
    Circle();
    Circle(int radius, string fillColor, string borderColor);
    ~Circle();

    int GetRadius();
    void SetRadius(int newRadius);

    int GetPerimeter();
    float GetArea();
};