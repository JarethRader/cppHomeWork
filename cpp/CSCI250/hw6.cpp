#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void astrisk(int n);
void triangle(int n);

int main(){
	triangle(4);
	
	triangle(0);
	
	triangle(10);
	
	cin.get();
	return 0;
}

void astrisk(int n){
	if(n == 0);
	else
	{
		cout << "*";
		astrisk(n-1);
	}
}

void triangle(int n){
	if(n == 0);
	else{
		astrisk(n);
		cout << endl;
		triangle(n-1);
		cout << endl;
		astrisk(n);
	}
}