// Dynamic Program
#include <iostream>
#include <string>

using namespace std;

int main()
{
  double *len=nullptr, *width=nullptr, *area=nullptr;      //len and width are pointers
  
  //define len and width as new doubles
  len = new double;
  width = new double;
  area = new double;
  cout << "enter length and width of a rectangle: " << endl;
  
  //to define objects len and width pointers are point to, you must dereference them with the '*' operator
  cin >> *len >> *width;
  
  //calculate area
  *area = *len * *width;
  
  cout << "Area = " << *area << endl;
}