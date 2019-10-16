// #pragma once
// Definition/Interface for Triangle class
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
using namespace std;

class Triangle
{
private:
	double sides[3];
	double area;
public:
	Triangle(double side1 = 0, double side2 = 0, double side3 = 0);
	~Triangle();
	void setSides(double side1, double side2, double side3);
	void getSides(double &sides1, double &side2, double &side3);
	double getPerimeter();
	void findArea();
	double getArea();
	string getType();
};

#endif