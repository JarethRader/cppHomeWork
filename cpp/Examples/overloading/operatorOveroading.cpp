// Operator overloading
#include <iostream>
#include <string>

using namespace std;

class MyClass
{
//function prototype
friend void print(MyClass);     //a class can add a function as a friend function, which is not a member of the class
                                //but will allow the function to access the private member of the class
private:
    //member variables
    int x, y;
public:
    
    //Constructor
    MyClass()
    {
        x = 1, y = 1;   
    }
};

void print(MyClass m)
{
    cout << "m.x = " << m.x << endl;    //this function cannot access int x of MyClass because it is a private member variable
}

int main()
{
    MyClass m;          //instantiate object m of type MyClass
    cout << "x = " << m.x << endl;
    
    MyClass *mP = &m;       //pointer of type MyClass
    //copied address off of m and put it into mP
    cout << "mP->x = " << mP->x << endl;    //in a class, you can use '->' to point to an object;dereference.
    cout << "(*mP).x = " << (*mP).x << endl;  //will do the same thing as above
    
    
/*
    m
     |-----|
     |x=(1)|0X1000 --->mP|0X1000| // stores address
     |y=( )|
     |     |
     |-----|
*/
}
