//Pointers
//Pointer = variable that stores memory address that may store some value
//'*' - Defereance operator
//pointer variables will let you allocate memory for variables

/*
					|				|
					|---------------|
					| Heap Segment  |
			10000	|	(some int)	|(you can allocate the memory dynamicall, but you must tell the data type)
					|				|
					|				|
					|---------------|
					| Stack Segment |
			*numP	|	nullptr		|(replaced will 10000 from heap segment; memory address stored in numP)
					|				|
					|---------------|

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num = 100;
	//only numP is a pointer; numP1 is an int
	int *numP, numP1, *numP3;
	//int *numP = nullptr;	//Can initialize as a null pointer
	double *numP2 = NULL; 	//Can initilize as null pointer this way too
	numP = &num;			//Pointer numP can store address of num
	numP3 = new int;			// dynamically allocated memory in heap segment and return the address and store into heap
	cout << "enter how many numbers would you like to store" << endl;
	int var;
	//cin >> var;		//define static variable var to be used with dynamic double pointer array
	//cin >> numP 		//doesn't work, you can store an int into a variable ment to store an address
	cin >> *numP; 		//does work. to store something, you must defererence it
						//dereferencing gets you a reference to the actual object the pointer is pointing to
	var = *numP;
	//Dynamically created array
	//keyword (nothrow) tells the compiler to not throw and exception
	double *dblPtr = new (nothrow) double[/*var*/*numP];	//var here is a static value; it's fixed and cannot change. numP is a dynamic value, and is defined while the program is running
	if (dblPtr == nullptr)
	{
		cout << "Memory could not be allocated" << endl;
	}
	else
	{
		for(int i = 0; i < var; i++)
		{ 
			cout << "Enter a nubmer: " << endl;
			cin >> dblPtr[i];
		}
		cout << endl;
		for(int i = 0; i < var; i++)
		{
			cout << dblPtr[i] << endl;
		}
		delete[] dblPtr; 		//delete array after it has been used
	}
	delete numP;
	//when you're done with a function, be sure to delete any dynamically allocated memory
	//Dynamic members are powerful but require more responsibility
	
	/*
			|---------------|
			| Heap Segment  |
	10000	|int size of arr|
	5000	|doubles for arr|
			|---------------|
			| Stack Segment |
	*numP	|	  10000		|
	dblPtr	|	  5000  	|
			|---------------|

*/
	
	numP = new int; //Dynamically allocating memory in heap segment
	
																					//output
	cout << "value of num = " << num << endl;		//passing num by value			// = 100
	cout << "address of num = " << &num << endl;	//passing num by referance		// = 0037F80C\--\	
	cout << "value of numP = " << numP << endl;		//passing numP by value			// = 0037F80C/-- refering to same address
	cout << "address of numP = " << &numP << endl;	//passing numP by referance		// = 0037F800
	*numP = 200; // dereferencing the value pointed to by num
	
	cout << "value of num = " << num << endl;			//passing num by value				// = 200		---Changed---
	cout << "address of num = " << &num << endl;		//passing num by referance			// = 0037F80C	---Same---
	cout << "value of numP = " << numP << endl;			//passing numP by value				// = 0037F80C	---Same---
	cout << "address of numP = " << &numP << endl;		//passing numP by referance			// = 0037F800	---Same---
	cout << "value pointed to by numP = " << *numP << endl;	//Passing numP with dereference operator 	// = 200		--numP is pointing at the value of num--
	
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}
/*
				   Address
				|			|
int num 		|	 100	|5000		stores memory location
num p			|	5000	|5004		Stores some value
				|			|
				|			|

after line 24				
				   Address
				|			|
int num 		|	 200	|5000		stores memory location
num p			|	5000	|5004		Stores some value
				|			|
				|			|
*/