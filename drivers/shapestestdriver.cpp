#include "Triangle.h"
#include "Circle.h"
#include <string>
#include <iostream>

void outputTestInt(int expected, int actual) {
    if (expected == actual) {
        std::cout << "\033[32mPASS\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: " << actual << std::endl;
    } else {
        std::cout << "\033[31mFAIL ->\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: \033[31m" << actual << "\033[0m" << std::endl;
    }
}

void outputTestFloat(float expected, float actual) {
    if (abs(expected - actual) <= 0.01) {
        std::cout << "\033[32mPASS\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: " << actual << std::endl;
    } else {
        std::cout << "\033[31mFAIL ->\t\033[0m";
        std::cout << "Expected: " << expected << "\tActual: \033[31m" << actual << "\033[0m" << std::endl;
    }
}

void outputTestString(std::string expected, std::string actual) {
    if (expected == actual) {
        std::cout << "\033[32mPASS\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: " << actual << std::endl;
    } else {
        std::cout << "\033[31mFAIL ->\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: \033[31m" << actual << "\033[0m" << std::endl;
    }
}

int main() {   
    Shape shape1;
    outputTestString("undefined shape", shape1.GetShapeType());
    outputTestInt(0, shape1.GetNumSides());
    outputTestString("clear", shape1.GetFillColor());
    outputTestString("clear", shape1.GetBorderColor());
    shape1.SetFillColor("red");
    shape1.SetBorderColor("blue");
    outputTestString("red", shape1.GetFillColor());
    outputTestString("blue", shape1.GetBorderColor());
    std::cout << std::endl;
    Circle circle1;
    outputTestString("circle", circle1.GetShapeType());
    outputTestInt(1, circle1.GetNumSides());
    outputTestInt(1, circle1.GetRadius());
    outputTestInt(6, circle1.GetPerimeter());
    outputTestFloat(3.14, circle1.GetArea());
    outputTestString("red", circle1.GetFillColor());
    outputTestString("orange", circle1.GetBorderColor());
    Circle circle2(5, "purple", "blue");
    outputTestString("circle", circle2.GetShapeType());
    outputTestInt(1, circle2.GetNumSides());
    outputTestInt(5, circle2.GetRadius());
    outputTestInt(31, circle2.GetPerimeter());
    outputTestFloat(78.5, circle2.GetArea());
    outputTestString("purple", circle2.GetFillColor());
    outputTestString("blue", circle2.GetBorderColor());
    std::cout <<  std::endl;
    Triangle triangle1;
    outputTestString("triangle", triangle1.GetShapeType());
    outputTestInt(3, triangle1.GetNumSides());
    outputTestInt(2, triangle1.GetSides());
    outputTestInt(6, triangle1.GetPerimeter());
    outputTestFloat(1.73, triangle1.GetArea());
    outputTestString("yellow", triangle1.GetFillColor());
    outputTestString("green", triangle1.GetBorderColor());
    Triangle triangle2(5, "red", "blue");
    outputTestString("triangle", triangle2.GetShapeType());
    outputTestInt(3, triangle2.GetNumSides());
    outputTestInt(5, triangle2.GetSides());
    outputTestInt(15, triangle2.GetPerimeter());
    outputTestFloat(10.83, triangle2.GetArea());
    outputTestString("red", triangle2.GetFillColor());
    outputTestString("blue", triangle2.GetBorderColor());

    system("pause");
    return 0;
}