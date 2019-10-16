#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Fraction.h"

using namespace std;



int main(){
	Fraction f1;
	Fraction f2;
	cout << "Enter first fraction in this form numerator/denominator: ";
	cin >> f1;
	cout << "Enter second fraction in this form numerator/denominator: ";
	cin >> f2;
	
	cout << f1 << "," << f2 << endl;
	Fraction f3;
	f3 = f1 + f2;
	cout << f1 << "+" << f2 << "=" << f3 << endl;
	//cout << f1 << "-" << f2 << "=" << f1-f2 << endl;
	//cout << f1 << "*" << f2 << "=" << f1*f2 << endl;
	//cout << f1 << "/" << f2 << "=" << f1/f2 << endl;

	cin.get();
	return 0;
}