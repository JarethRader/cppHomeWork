// Example Program
#include <iostream>
#include <string>

using namespace std;

class MyClass
{
public:
    int x, y;
    
    //Constructor
    MyClass()
    {
        x = 1, y = 1;   
    }
};

int main()
{
    MyClass m;          //instantiate object m of type MyClass
    cout << "x = " << m.x << endl;
    
    MyClass *mP = &m;       //pointer of type MyClass
    //copied address off of m and put it into mP
    cout << "x = " << mP->x << endl;    //in a class, you can use '->' to point to an object;dereference.
    cout << "x = " << (*mP).x << endl;  //will do the same thing as above
    
    
/*
    m
     |-----|
     |x=(1)|0X1000 --->mP|0X1000| // stores address
     |y=( )|
     |     |
     |-----|
*/
}
