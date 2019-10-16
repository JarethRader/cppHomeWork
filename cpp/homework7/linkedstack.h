//
//  LinkedStack.h
//  Linked list-based Stack
//

#ifndef LinkedStack_h
#define LinkedStack_h

#include <stdio.h>
#include <iostream>
#include <cassert>

using namespace std;

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class LinkedStack
{
private:
    nodeType<Type> *stackTop; // pointer to the stack
public:
    LinkedStack(); // default constructor
    LinkedStack(const LinkedStack<Type> & otherStack); // copy constructor
    ~LinkedStack(); // destructor
    // method to return the top element of the stack
    Type top() const;
    // method to remove the top element of the stack
    void pop();
    // method to determine whether the stack is empty
    bool isEmpty() const;
    // method to add a newItem to the stack
    void push(const Type &newItem);
    // clear or initialize stack
    void clear();
};

#endif /* LinkedStack_h */

template<class Type>
LinkedStack<Type>::LinkedStack()
{
    stackTop = nullptr;
}

template<class Type>
LinkedStack<Type>::LinkedStack(const LinkedStack<Type> &otherStack)
{
    nodeType<Type> *newNode, *current, *last;
    stackTop = nullptr; //initialize stackTop to nullptr
    if(otherStack.stackTop != nullptr)
    {
        
        current = otherStack.stackTop; // set current to point to the stack top to be copied
        // cop the stackTop element of the stack
        stackTop = new nodeType<Type>; // create the node
        stackTop->info = current->info;
        stackTop->link = nullptr; // set the link field of the node to nullptr
        last = stackTop;
        current = current->link;
        // copy the remaining stack
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template<class Type>
void LinkedStack<Type>::clear()
{
    nodeType<Type> *temp;
    while(stackTop != nullptr) // while there are elements in the stack
    {
        temp = stackTop; // set temp to point to the current node
        stackTop = stackTop->link; // advance stackTop to the next node
        delete temp; // deallocate memory occupied by temp
    }
}

template<class Type>
LinkedStack<Type>::~LinkedStack()
{
    clear();
}

template<class Type>
bool LinkedStack<Type>::isEmpty() const
{
    return (stackTop == nullptr);
}

template<class Type>
void LinkedStack<Type>::push(const Type &newItem)
{
    nodeType<Type> *newNode; // pointer to create the new node
    newNode = new nodeType<Type>; // create the node
    newNode->info = newItem; // store newItem in the node
    newNode->link = stackTop; // insert newNode before stackTop
    stackTop = newNode; // set stackTop to point to the top node
}

template<class Type>
Type LinkedStack<Type>::top() const
{
    assert(stackTop != nullptr); // if stack is empty, terminate the program
    return stackTop->info; // return the top element
}

template<class Type>
void LinkedStack<Type>::pop()
{
    nodeType<Type> *temp; // pointer to deallocate memory
    if (stackTop != nullptr)
    {
        temp = stackTop; // set temp to point to the top node
        stackTop = stackTop->link; // advance stackTop to the next node
        delete temp; // deallocate the memory
    }
    else
    {
        cout << "Cannot remove from an empty stack." << endl;
    }
}