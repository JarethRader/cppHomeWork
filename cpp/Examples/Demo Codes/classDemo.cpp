#include <iostream>

using namespace std;

//Struct + user defined name
//by default, the members are public
struct RectangleType
{	//List of components; just variables
	float len;
	float width;
	
};

//class + user defined name
class Rectangle 
{
/*
{
private:
	list all private memebers
	accessible only from other members of the same class
	and are from their "friends" (friends class)
protected:
	list all protected members
	accessible from other members of the same class
	also from members of derived classes (inheritance)
public:
	list all public members
	can be accessed from anywhere that the object is visible
}
*/
	//List of components; members can be both vaiables and functions
	float len;
	float width;
	//Members are private by default
	//can be set to public
 public:
	void set_values (int, int);
	int area() {return width*len}
};

//define set_values functions declared in Rectangle class
void Rectangle::set_values (int x, int y)
{
	len = x;
	width = y;	
}

int main(int ardc, char* argv[])
{
	RectangleType r1;
	Rectangle r2;
	int wid, heig;
	
	cout << "Enter width: " << endl;
	cin >> wid;
	cout << "Enter height: " << endl;
	cin >> heig;
	r2.set_values(heig, wid);
	cout << "area: " << rectangle.area();
	
	cin.get();
	return 0;
}