#pragma once
#include <iostream>
#include <string>
#include <fstream>

#ifndef FRACTION_H
#define FRACTION_H

#include <string>
using namespace std;

class Fraction
{
	//overload + operator
	friend Fraction operator+(const Fraction &, const Fraction &);
	//overload - operator
	friend Fraction operator-(const Fraction &, const Fraction &);
	//overload * operator
	friend Fraction operator*(const Fraction &, const Fraction &);
	//overload / operator
	friend Fraction operator/(const Fraction &, const Fraction &);
	//overload << operator
	friend ostream & operator<<(ostream &, Fraction &);
	//overload >> operator
	friend istream & operator >> (istream &, Fraction &);
	//overload == operator
	friend bool operator==(const Fraction &, const Fraction &);
	//overload < operator
	friend bool operator<(const Fraction &, const Fraction &);
	//overload > operator
	friend bool operator>(const Fraction &, const Fraction &);
public:
//Class variables
	int numerator;
	int denominator;
//Function to reduce fractions (use Euclidian Greatest Common Divisor)
//constructors
	Fraction();
	Fraction(int num, int denom);
//destructors
	~Fraction();
	
	//setter and getter functions
	void setNumerator(int num);
	void setDenominator(int denom);
	void setFraction(int num, int denom);
	
	int getNumerator();
	int getDenominator();
};

#endif