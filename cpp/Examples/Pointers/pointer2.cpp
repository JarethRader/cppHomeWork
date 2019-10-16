// Example program
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int *numP = nullptr;
    numP = new int;
    *numP = 100;
    cout << "numP = " << numP << endl;      //print address numP is pointing to
    cout << "*numP = " << *numP << endl;    //print object numP is points to
/*
           address      value
    *numP  |0X1000| --- |100| 0X1000
*/

    
    cout << "numP = " << *numP << endl;     //print object numP is points to 
    *numP = 200;                            //change value of object numP is pointing to
    cout << "numP = " << *numP << endl;     //print object numP is points to
    
    /*
    if you change memory address, you must delete the old memory address, or you'll createe a memory leak
    you can never use the same memory address (0X1000) again
    
           address      value
    *numP  |0X1000| -|->|100| 0X1000 <--- memory leak
               |______->|200| 0X2000
*/
//keyword delete to deallocate memory

    cout << "numP = " << *numP << endl;     //print object numP is points to 
    delete numP;                            //deallocate old numP address
    numP = nullptr;                         //it's a good idea to mark numP as null pointer after its deallocated if it's going to be used again
    numP = new int;                         //allocate a new address to store a new object in numP
    *numP = 200;                            //change value of object numP is pointing to
    cout << "numP = " << *numP << endl;     //print object numP is points to

}

