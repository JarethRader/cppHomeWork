// Implementation of Triangle.h
#include <iostream>
#include <string>
#include <cmath>

//Must include the header file that is being implemented
#include "Triangle.h"

using namespace std;
//Constructor
Triangle::Triangle(double side1, double side2, double side3)
{
	//data validation
	if (side1 < 0)
		side1 = 0;
	if (side2 < 0)
		side2 = 0;
	if (side3 < 0)
		side3 = 0;
	this->setSides(side1, side2, side3);
}

//destructor
Triangle::~Triangle()
{
	//no clean up required for this class...
}

// function to set three sides of a triangle
void Triangle::setSides(double side1, double side2, double side3)
{
	//data validation
	if (side1 < 0)
		side1 = 0;
	if (side2 < 0)
		side2 = 0;
	if (side3 < 0)
		side3 = 0;
	this->sides[0] = side1;
	this->sides[1] = side2;
	this->sides[2] = side3;
}

//function to get the values of three sides of triangle
void Triangle::getSides(double &side1, double &side2, double &side3)
{
	side1 = this->sides[0];
	side2 = this->sides[1];
	side3 = this->sides[2];
}

//function that calculates and sets the value of area member varible
void Triangle::findArea()
{
	//Calculate area using Heron's Formula
	double s = this->getPerimeter() / 2;
	this->area = sqrt(s*((((s - this->sides[0]))*(s - this->sides[1]))*(s - this->sides[3])));
	//FIXME
	//find area using Heron's formula provided in the above link and
	//set the value for area with the calculated value;
	//this->area = 0;
}

//function to calculate and return perimeter
double Triangle::getPerimeter()
{
	//FIXME
	//Calculate the perimeter of the triangle and return it
	double perimeter = this->sides[0] + this->sides[1] + this->sides[2];
	
	return perimeter;
}

//function that returns area of a triangle
double Triangle::getArea()
{
	return this->area;
}

//function that determins the type of a triangle and returns the same
string Triangle::getType()
{
	//Equalateral triangle: all three sides must be equal
	if (this->sides[0] == this->sides[1] && this->sides[1] == this->sides[2])
		return "Equalteral";
	//FIXME
	//Add the rule for checking if the triangle is Isosceles
	else if (this->sides[0] != this->sides[1] && this->sides[1] != this->sides[2] && this->sides[0] != this->sides[2])
		return "Isosceles";
	else // no sides are equal
		return "Scalene";
}