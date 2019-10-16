/*
lab 2
CS 2 
date: 8.31.16
Updated By: Jareth Rader

This program reads three sides of triangles from an input file
The program calculates various properties of triangles such as
area, perimeter, type, etc. using class.
The	program	creates and output report file with all the information caluculated
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Triangle.h"

using namespace std;
#define MAX_TRIANGLES 100

//function to check data stored in triangles array
void checkData(Triangle ts[], int arraylength);

//THis function reads triangle information from input file into
//the triangles array provided
//returns total number of triangles' read from the file
int readTriangles(Triangle ts[]);

//this function writes triangle information as a report to an output file
//provided by the user
void writeReport(Triangle ts[], int arraylen);

//this function draws a line with give char ch of length len
void drawLine(ofstream &fout, char ch, int len);

//function to sort triangles in ascending order
//based on their area using bubble sort algorithm
void sortTriangles(Triangle triangles[], int arrayLen);

int main(int argc, char *argv[])
{
	//Declare array of triangles that can hold upto MAX_TRIANGLES triangles
	Triangle triangles[MAX_TRIANGLES];
	// set output for floating point numbers to always display up to 2 decimal points
	cout << fixed << showpoint << setprecision(2);
	//checkData(triangles, MAX_TRIANGLES);
	
	int triangleCount = readTriangles(triangles);
	
	//Data before sorting
	cout << "Before sorting\n\n";
	checkData(triangles, triangleCount);
	//FIXME
	//Call sort Triangles function by passing proper arguments
	sortTriangles(triangles, triangleCount);
	cout << "After sorting\n";
	checkData(triangles, triangleCount);
	writeReport(triangles, triangleCount);
	cout << "All done! hit enter to exit...";
	cin.get();
	return 0;
}

void checkData(Triangle ts[], int arrayLength)
{
	double side1, side2, side3;
	for (int i = 0; i < arrayLength; i++)
	{
		ts[i].getSides(side1, side2, side3);
		cout << i + 1 << ". " << side1 << " " << side2 << " " << side3 << " " << ts[i].getPerimeter() << endl;
	}
}

int readTriangles(Triangle ts[])
{
	int count = 0;
	double side1, side2, side3;
	string file;
	cout << "Enter file name with triangles' info in it:" << endl;
	cin >> file;
	//getline(cin, file);
	ifstream fin;
	fin.open((file+".txt").c_str());
	if(!fin)
	{
		cout << "Input file does not exist. Program Terminates!\n";
		cin.get();
		return 1	;
	}	
	int i = 0;
	while(i < MAX_TRIANGLES && !fin.eof())
	{
		fin >> side1 >> side2 >> side3;
		ts[i].setSides(side1, side2, side3);
		//FIXME
		//set there sides' length for ith triangle in ts array
		++i;
	}
	return i; //return total number of triangles read from input file
}

void sortTriangles(Triangle triangles[], int arrayLen)
{
	//Use improved version of bubble sort to sort
	// Triangle objects stored in triangles array based on area
	bool inOrder = true;
	
	for (int i = 0; i < arrayLen; i++)
	{
		inOrder = true;
		for (int j = 0; j < arrayLen - i - 1; j++)
		{
			cout << triangles[j].getArea() << endl;
			if (triangles[j].getArea() > triangles[j+1].getArea())
			{
				//inOrder = false;
				//FIXME
				//swap two triangles as they're not in order
				swap(triangles[j], triangles[j+1]);
			}
		}
		if (inOrder)//data is all sorted
			break;
	}
}

void writeReport(Triangle ts[], int arrayLen)
{
	string file, type;
	ofstream fout;
	double side1, side2, side3, area, perimeter;
	do
	{
		cout << "Enter a file name to write output to:" << endl;
		cin >> file;
		fout.open((file+".out").c_str());
		if(!fout)
			cout << "Output file coud NOT be opened, try again...\n";
	}while (!fout);
	
	fout << fixed << showpoint << setprecision(2);
	int len = 65;
	drawLine(fout, '*', len);
	fout << setw(40) << "Triangle Information" << endl;
	//FIXME
	//draw line with * character
	drawLine(fout, '*', len);
	fout << setw (5) << "#" << setw(8) << "side 1" << setw(8) << "side 2" << setw(8) << "side3" << setw(8) << "area" << setw(10) << "perimeter" << setw(17) << "type" << endl;
	drawLine(fout, '=', len);
	for (int i = 0; i < arrayLen; i++)
	{
		//FIXME
		//output each triangle's information as shown in the sample output.
		//use proper formatting
		
		ts[i].getSides(side1, side2, side3);
		area = ts[i].getArea();
		perimeter = ts[i].getPerimeter();
		type = ts[i].getType();
		fout << setfill(' ') << i+1 << setw(8) << side1 << endl << setw(8) << side2 << setw(8) << side3 << setw(8) << area << setw(10) << perimeter << setw(17) << type << endl;
		//cout << "FIXME" << endl; //comment this out when fixed
	}
	//FIXME
	//draw line with = character
	drawLine(fout, '=', len);
	cout << "Done writing data to output file!\n";
}

void drawLine(ofstream &fout, char ch, int len)
{
	fout << setfill(ch);
	fout << setw(len) << "" << endl;
	fout << setfill (' '); //reset fill character to space
}