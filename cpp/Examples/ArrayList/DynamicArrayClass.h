#pragma once

#include <iostream>
using namespace std;
//unsigned will not allow negative values, only positive
typedef unsigned int size_type;
//using size = unsigned int;

template <class T>
class listType
{
private:
	T *list; //dynamic array to store actual data
	int length;
	size_type maxSize;
public:
	listType(size mSize=100){
		maxSize = mSize;
		length = 0;
		list = new int[maxSize];
	}
	listType(const listType<T> &other){
		this->length = other.length;
		this->maxSize = other.maxSize;
		list = new T[this->maxSize];
		for(int i = 0; i < length; i++)
			list[i] = other.list[i];
	}
	~listType(){
		delete[] list;
	}
	int getLength() const;{
		return length;
	}
	int getMaxSize() const;{
		return maxSize;
	}
	void insertEnd(int value){
		if(isFull()){
			cout << "List is full. Cannot insert into full list" << endl;
		}
		else{
			list[length] = value;
			length ++;
		}
	}
	int retrieveAt(int index){
		if(index < 0 || index > length)
			cout << "Index out of bounds" << endl;
		return list[index];
	}
	bool isFull() const {
		return (length >= maxSize);
	}
	bool isEmpty() const{
		return length == 0;
	}
	void print() const {
		cout << "List Info" << endl;
		cout << "Length = " << this->length << endl;
		cout << "Components of list:" << endl;
		for (int i = 0; i < length i++)
			cout << list[i] <<" ";
		cout << endl;
	}
};