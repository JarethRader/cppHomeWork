//
//  main.cpp
//  Demo of Friend Function & Operator Overloading
//
//  Created by Ram Basnet on 1/30/16.
//  Copyright © 2016 Ram Basnet. All rights reserved.
//

// Example program
#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
    friend Rectangle operator-(const Rectangle &x, const Rectangle &y);
    friend istream& operator>>(istream &cin, Rectangle &x);
    friend void print(Rectangle r);
    friend ostream& operator<<(ostream &cout, const Rectangle &x);
    friend bool operator==(const Rectangle &x, const Rectangle &y);
private:
    int len, width;
public:
    Rectangle()
    {
        len=1;
        width=1;
    }
    int getLen() const
    {
        return len;
    }
    int getWidth() const
    {
        return width;
    }
    void setLen(int len)
    {
        this->len = len;
    }
    void setWidth(int width)
    {
        this->width=width;
    }
};

// function that overloads + operator to add two rectangles x and y without using
// private members
Rectangle operator+(const Rectangle &x, const Rectangle &y)
{
    Rectangle z;
    int len = x.getLen()+y.getLen();
    //cout << "len = " << len << endl;
    z.setLen(len);
    z.setWidth(x.getWidth()+y.getWidth());
    //z.print();
    return z;
}

// function that adds two rectangles x and y and returns new rectangle
Rectangle add(const Rectangle &x, const Rectangle &y)
{
    Rectangle z;
    int len = x.getLen()+y.getLen();
    //cout << "len = " << len << endl;
    z.setLen(len);
    z.setWidth(x.getWidth()+y.getWidth());
    //z.print();
    return z;
}

// function that overloads - operator to subtract y rectangle from x rectangle
// function can access private members because it's a freind to Rectangle class
Rectangle operator-(const Rectangle &x, const Rectangle &y)
{
    Rectangle z;
    z.len = x.len - y.len;
    z.width = x.width - y.width;
    return z;
}

istream& operator>>(istream &cin, Rectangle &x)
{
    cin >> x.len >> x.width;
    return cin;
}

ostream& operator<<(ostream &cout, const Rectangle &x)
{
    cout << "len: " << x.len << " width: " << x.width;
    return cout;
}

bool operator==(const Rectangle &x, const Rectangle &y)
{
    if (x.len == y.len && x.width == y.width)
        return true;
    else
        return false;
}

void print(Rectangle r)
{
    cout << "len = " << r.len << endl << " width = " << r.width << endl;
}

int main()
{
    Rectangle r1, r2;
    //print(r1);
    //print(r2);
    Rectangle r3 = r1 + r2;
    //Rectangle r3 = add(r1, r2);
    //Rectangle r3 = r1 + r2;
    //print(r3);
    //print(add(r1, r2));
    Rectangle r4 = r1 - r2;
    print(r4);
    //Rectangle r5;
    //cout << "Enter length and width of a rectangle separated by space: ";
    //cin >> r5;
    //print(r5);
    //cout << r5;
    
    if (r1 == r2)
        cout << r1 << " and " << r2 << " are equal!" << endl;
    else
        cout << r1 << " and " << r2 << " are not equal " << endl;
    
    if (r1 == r3)
        cout << r1 << " and " << r3 << " are equal!" << endl;
    else
        cout << r1 << " and " << r3 << " are not equal " << endl;
    return 0;
}
