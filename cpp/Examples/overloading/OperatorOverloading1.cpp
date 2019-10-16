#include <iostream>
#include <string>

using namespace std;

class Rectangle {
	friend void print (const Rectangle &); //friend function is not a member function
	//friend Rectangle add(const Rectangle &r1, const Rectange &r2)//can add this as a friend function to avoid making getter/setter functions
	friend Rectangle operator+(const Rectangle &lhs, const Rectangle &rhs);
	friend istream& operator>>(istream &isObj, Rectangle &r);
private: double len, width;
public:
	Rectangle(double l=0, w=0){
		this->len = l;
		this->width = w;
	}
	double getLen(){
		return this->len;
	}
	void setLen(double l){
		this->len = l;
	}
}

//passing class object to friend function example
//this function will not be able to change the member variables of this object r
void print(const Rectangle &r)
{
	cout << "len = " << r.len << "width = " << r.width << endl;
}

//functions can me overloaded as global, member, or friend functions
//syntax( return type -> 'operator"+ ->operatorToOverload"' (parameters);)
Rectangle operator+(const Rectangle &r1, const Rectangle &r2)
{
	Rectangle r;
	r.len=(r1.len+r2.len);
	r.width=(r1.width+r2.width);
	return r;
	
}

Rectangle add(const Rectangle &r1, const Rectangle &r2)
{
	Rectangle r;
	r.setLen=(r1.getLen()+r2.getLen());
	return r;
}

//friend function definition
/*
Rectangle add(const Rectangle &r1, const Rectange &r2)
{
	Rectangle r;
	r.len=(r1.len+r2.len);
	r.width=(r1.width+r2.width);
	return r;
}*/

//istream must be passed by reference because you must keep track of the input data stream
istream& operator>>(istream &isObj, Rectangle &r)
{
	//with this function, you read in to variables then pass them into an object class
	isObj >> r.len >> r.width;
	return isObj;
	
}

int main()
{
	/*
	Rectangle rect;
	print(rect);*/
	
	Rectangle rect, rect1;
	cout << "Enter len and width separated by a space: ";
	cin >> rect >> rect1;
	// >>(>>(cin, rect)),rect1;
	Rectangle myRect = Rectangle(10, 2);
	Rectangle yourRect = Rectangle(5, 3);
	Rectangle r1 = Rectangle(2, 1);
	//Rectangle ourRect;
	//ourRect = add(myRect, youRect);
	
	//Rectangle ourRect = myRect + yourRect + r1;
	//ourRect = operator+(operator+(myRect, yourRect),r1);
	
	print(ourRect);//ourRect = ()len = 15, width = 5)
	
	cin.ignore(1000,'\n');
	cin.get();
	return 0;
}

/*
operator loading

int num 5+7;
	     ^ + is an operator
string name = "John " + "Smith";
					  ^ + here is a different type of operator
string is a user defined class

==============
Rectangle r1, r2, r3;
r3 = r1+r2;
	   ^ + operator is not defined for this class to add multiple instances of this class together
cin >> r1;
cout << r1;
*/