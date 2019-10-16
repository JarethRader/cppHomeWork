/*
Class interface and definition for dynamic array-based listType template.

Class template definition can't be in separate file because
the compiler needs to know all the implementation details of the class
so it can instantiate different versions of the code, depending on the 
parameters given for template parameters.

Remember that a template doesn't represent code directly, but a
template for several versions of that code.
*/

#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class listType
{
private:
	T *list;
	int length;
	int maxSize;
public:
	listType(unsigned int max = 10000); // constructor
	listType(const listType<T> &other); // copy constructor
	~listType(); // destructor
	bool isEmpty() const;
	// return true if list is empty
	bool isFull() const;
	// return true if list is full
	int listSize() const;
	// get the length/size of the list
	int maxListSize() const;
	// get the max list size
	void print() const;
	// print all the elements in the list
	void insertEnd(const T &item);
	// insert at the end of the list
	void insertAt(int index, const T &item);
	// insert given item at the given index
	void clearList();
	// deletes all the elements in the list and resets the list
	void replaceAt(int index, const T &item);
	// replace element at index with new item
	T retrieveAt(int index) const;
	// retrieve the element at given index
	void removeAt(int index);
	// remove the element at given index
	T& operator[](int index);
	// overload [] operator as member function
	int seqSearch(const T &searchItem);
	// do a linear search on given searchItem and return index if found -1 otherwise
	void remove(const T &item);
	// find the item in the container and remove it
};

template <class T>
listType<T>::listType(unsigned int max)
{
	this->maxSize = max;
	this->length = 0;
	this->list = new T[maxSize];
}

template <class T>
listType<T>::listType(const listType<T> &other)
{
	this->length = other.length;
	this->maxSize = other.maxSize;
	this->list = new T[maxSize];
	for (int i = 0; i<other.length; i++)
		this->list[i] = other.list[i];
}

template <class T>
listType<T>::~listType()
{
	delete[] list;
}

// return true if list is empty
template <class T>
bool listType<T>::isEmpty() const
{
	return (length == 0);
}

// return true if list is full
template <class T>
bool listType<T>::isFull() const
{
	return (length >= maxSize);
}

// return size/length of the list
template <class T>
int listType<T>::listSize() const
{
	return this->length;
}

// return the max size of list
template <class T>
int listType<T>::maxListSize() const
{
	return this->maxListSize;
}

// print all the elements in the list
template <class T>
void listType<T>::print() const
{
	cout << "max size = " << maxSize << endl;
	cout << "length = " << length << endl;
	cout << "list contents" << endl;
	for (int i = 0; i<length; i++)
		cout << list[i] << " ";
	cout << endl;
}

// insert at the end of the list
template <class T>
void listType<T>::insertEnd(const T &item)
{
	if (isFull())
		cout << "Cannot insert in a full list" << endl;
	else
	{
		list[length] = item;
		length++;
	}
}

// insert given item at the given index
template <class T>
void listType<T>::insertAt(int index, const T &item)
{
	if (index < 0 || index >= length)
		cout << "Index is out of range." << endl;
	else if (isFull())
		cout << "Cannot insert in a full list." << endl;
	else
	{
		// move the elements down from the index
		// starting from the end
		for (int i = length; i > index; i--)
			list[i] = list[i - 1];
		list[index] = item; // insert the item at the specified index
		length++; // increment the length
	}
}

// deletes all the elements in the list and resets the list
template <class T>
void listType<T>::clearList()
{
	length = 0;
}

// replace element at index with new item
template <class T>
void listType<T>::replaceAt(int index, const T &item)
{
	if (index < 0 || index >= length)
		cout << "Index is out of range." << endl;
	else
		list[index] = item;
}

// retrieve the element at given index
template <class T>
T listType<T>::retrieveAt(int index) const
{
	if (index < 0 || index >= length)
		cout << "Index is out of range." << endl;
	else
		return list[index];
}

// remove the element at given index
template <class T>
void listType<T>::removeAt(int index)
{
	if (index < 0 || index >= length)
		cout << "Index is out of range." << endl;
	else
	{
		// move elements up one position one at a time 
		for (int i = index; i < length - 1; i++)
			list[i] = list[i + 1];
		length--; // decrease list length by 1
	}
}

//return the reference to the value at given index
template <class T>
T& listType<T>::operator[](int index)
{
	assert(0 <= index && index < length);
	return list[index];
}

// do a linear search on given searchItem and return index if found, -1 otherwise
template <class T>
int listType<T>::seqSearch(const T &searchItem)
{
	int index = 0;
	bool found = false;
	while (index < length && !found)
	{
		if (list[index] == searchItem)
			found = true;
		else
			index++;
	}
	if (found)
		return index;
	else
		return -1;
}

// find the item in the container and remove it
template <class T>
void listType<T>::remove(const T &item)
{
	int index = -1;
	if (isEmtpy())
		cout << "Cannot delete from an empty list!" << endl;
	else
	{
		index = seqSearch(item);
		if (index != -1)
			removeAt(index);
		else
			cout << "The item to be deleted is not in the list." << endl;
	}
}




