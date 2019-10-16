#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Fraction.h"

using namespace std;

//constructors
Fraction::Fraction() {
	this->numerator = 0.0;
	this->denominator = 0.0;
}
Fraction::Fraction(int num, int denom) {
	this->numerator = num;
	this->denominator = denom;
}
//destructors
Fraction::~Fraction() {

}

//setter and getter functions
void Fraction::setNumerator(int num) {
	this->numerator = num;
}
void Fraction::setDenominator(int denom) {
	this->denominator = denom;
}
void Fraction::setFraction(int num, int denom) {
	this->numerator = num;
	this->denominator = denom;
}

int Fraction::getNumerator() {
	return this->numerator;
}
int Fraction::getDenominator() {
	return this->denominator;
}

//overload + operator
Fraction operator+(const Fraction &left, const Fraction &right){
	Fraction temp;
	int gcd;
	if(left.denominator < right.denominator){
		gcd = left.denominator/right.denominator;
		temp.numerator = (left.numerator*gcd)+right.numerator;
		temp.denominator = (left.denominator*gcd)+right.denominator;
	}
	else if(left.denominator > right.denominator){
		gcd = right.denominator/left.denominator;
		temp.numerator = left.numerator+(right.numerator*gcd);
		temp.denominator = left.denominator*gcd+(right.denominator*gcd);
	}
	return temp;
}
//overload - operator
Fraction operator-(const Fraction &left, const Fraction &right){
	Fraction temp;
	int gcd;
	if(left.denominator < right.denominator){
		gcd = left.denominator/right.denominator;
		temp.numerator = (left.numerator*gcd)-right.numerator;
		temp.denominator = (left.denominator*gcd)-right.denominator;
	}
	else if(left.denominator > right.denominator){
		gcd = right.denominator/left.denominator;
		temp.numerator = left.numerator-(right.numerator*gcd);
		temp.denominator = left.denominator*gcd-(right.denominator*gcd);
	}
	return temp;
	
}
//overload * operator
Fraction operator*(const Fraction &left, const Fraction &right){
	Fraction temp;
	temp.numerator = left.numerator*right.numerator;
	temp.denominator = left.denominator*right.denominator;
	return temp;
}
//overload / operator
Fraction operator/(const Fraction &left, const Fraction &right){
	Fraction temp;
	temp.numerator = left.numerator/right.numerator;
	temp.denominator = left.denominator/right.denominator;
	return temp;
}
ostream & operator<<(ostream &out, Fraction &f)
{
	return out << f.numerator << "/" << f.denominator << endl;
}
istream & operator>>(istream &is, Fraction &f)
{
	char ch;
	is >> f.numerator >> ch >> f.denominator;
	return is;
}
//overload == operator
bool operator==(const Fraction &left, const Fraction &right){
	return((left.numerator/left.denominator)==(right.numerator/right.denominator));
}
//overload < operator
bool operator<(const Fraction &left, const Fraction &right){
	return((left.numerator/left.denominator)<(right.numerator/right.denominator));
}
//overload > operator
bool operator>(const Fraction &left, const Fraction &right){
	return((left.numerator/left.denominator)>(right.numerator/right.denominator));
}
