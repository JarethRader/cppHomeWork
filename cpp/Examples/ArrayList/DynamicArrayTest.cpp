#include <iostream>
#include "DynamicArrayClass.h"
using namespace std;
class Rectangle
{
	friend ostream& operator<<(ostream&, Rectangle &);
public:
	int width, length;
	Rectangle(int i = 1, int w = 1){
		length = l; width = w;
	}
}

friend ostream& operator<<(ostream& out, Rectangle &r){
	return out << "Length = " << r.length << " Width = " << r.width << endl;
}

int main(){
	listType<int> l1;
	l1.print();
	l1.insertEnd(10);
	l1.insertEnd(20);
	l1.insertEnd(30);
	listType<int> l2 = l1;
	l2.insertEnd(40);
	l2.print();
	l1.print();
	listType<char> charList;
	charList.insertEnd('A');
	charList.insertEnd('B');
	charList.print();
	listType<double> dblList;
	dblList.insertEnd(18.90);
	dblList.insertEnd(20.98);
	dblList.print();
	listType<Rectangle> rects;
	Rectangle r;
	rects.insertEnd(r);
	rects.print();
	Rectangle r2 = Rectangle(100, 50);
	rects.insertEnd(r2);
	rects.print();
	Rectangle r3 = rects.retrieveAt(1);
	cout << r3 << endl;
	
	cin.get();
	return 0;
}