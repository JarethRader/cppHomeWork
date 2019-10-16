#include <iostream>
#include <string>

using namespace std;
//variables declared/defined here are defined in a global scope
int myGlobal = 1;

//no memory is allocated until the class is insantiated somewhere later on; this is just a class definition
class myClass {
public:
	int x, y; // object variable; specific per each instantiation of this class
	static int stVar; // class variable
	myClass(){
		x = 1;
		y = 1;
		stVar++;
	}
	//function can be static
	static void print()
	{
		//you can call object variables in a static function
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		//value of stVar will be incremented by 1
		cout << "stVar = " << stVar << endl;
	}
};

//initilized value of stVar outside of the class to 0
int myClass::stVar = 0;

void myFunc() {
	int num = 1
	static int stNum = 1;
	myGlobal += 1;
	//Predecrement/increment adds 1 then uses the value postdecrement/increment uses value then adds 1
	//++num;
	//incrementing/decrementing a varialbe with a cout wont permanently modify the value
	cout << "num = "<< num << endl;
	//num++;
	//cout << "num = "<< num << endl;
	//static variables will tell the compiler to save the variable in a new memory location even when variable goes out of scope.
	//Static=stick/dynamic=stay
	cout << "stNum = "<< ++stNum << endl;
}

//instantiating a class is the same as declaring a variable
int main(){
	myClass::print();//x and y are never allocated because they ar object variables. This will only access static variables
	/*myFunc();
	myFunc();
	cout <, "myGlobal = " << myGlobal << endl;*/
	myClass m;
	m.print();//stVar will = 1; incremented by 1 from 0;
	myClass m1;//stVar will = 2; memory location for stVar is shared between m and m1
	m1.print();
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}


//memory
//ordered sequence of memory cells
/*
							|-----------|
	lower Address(1000)		| Text/Code |<-static
							|-----------|
							|	data	|<-Global/variables/initializer - address of myGlobal will be stored here
							|-----------|
							|	lost	|<-uninitilized - address of myClass is stored here
							|-----------|
							|   heap	|<-dynamic variables
							|			|
							|-----------|
							|			|
	Higher Address(500)		|  ^stack^	|<-auto variables
							|			|
							|-----------|
*/