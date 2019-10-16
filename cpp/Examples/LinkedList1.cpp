/*
 Unordered Linked List Example
 1. Creates dynamic linked list using forward and backward strategies
 2. Traverse nodes in the list
 3. Insert new node into the list
 4. Delete a node from the list
 5. Search the list for a given data and return the node with the data
 */

#include <iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};

nodeType *buildListForward(nodeType * &last)
{
    /*
     // just like using insertEnd method for dynamic array-based list (listType) we created earlier
     // push_back method for vector STL, etc.
     
     Algorithm steps:
     1. Initialize first and last to nullptr
     2. For each item in the list
	 a. Create the new node, newNode
	 b. Store the item/data in newNode
	 c. Store nullptr to the link of the newNode
	 d. Check if the list is empty
	 i. If the list is empty:
	 a. Make first and last point to newNode
	 ii. If the list is not empty
	 a. append newNode at the end of the list
	 b. update the last node by pointing it to the newNode
	*/
    nodeType *first=nullptr; // first/head node pointer
    last=nullptr; // last/tail node pointer
    nodeType *newNode=nullptr; // temp node to create and add a new node into the list
    int num; // temp var to read data into
    
    
    // create temp node with data
    cout << "Enter some numbers ending with -999: ";
    cin >> num;
    while(num != -999)
    {
        newNode = new nodeType;
        newNode->info = num; // store num into info
        newNode->link = nullptr;
        
        if (first == nullptr) // check if the node is empty
        {   // make the first and last node point to newNode
            first = newNode;
            last = newNode;
        }
        else // list is not empty
        {
            last->link = newNode; // append newNode at the end of the list
            last = newNode; //update the last node by pointing it to the newNode
        }
        cin >> num;
    }
    return first;
}

nodeType *buildListBackward()
{
    /*
     // just like using insertAt(0, newNode) for dynamic array-based list (listType) we created earlier
     // push_front method in list STL, etc.
     Algorithm steps:
     1. Initialize first to nullptr
     2. For each item in the list
     a. Create the new node, newNode
     b. Store the item/data in newNode
     c. Insert newNode before first
     d. Update the value of the pointer first
     */
    nodeType *first = nullptr; //1
    nodeType *newNode=nullptr; //temp node to create and add a new node into the list
    int num;
    
    // create temp node with data
    cout << "Enter some numbers ending with -999: ";
    cin >> num;
    while(num != -999)
    {
        newNode = new nodeType; // 2.a.
        newNode->info = num; // 2.b store num into info
        newNode->link = first; // 2.c
        first = newNode; // 2.d update the head pointer of the list
        cin >> num;
    }
    return first;
}

// function to traverse each node starting from head and print the value stored
// in the node
void traverseLinkedList(nodeType *head)
{
    nodeType *currentNode = head;
    while (currentNode != nullptr)
    {
        cout << currentNode->info << " ";
        currentNode = currentNode->link;
    }
    cout << endl;
}

// Recursively print linkedList in reverse order
void reversePrint(nodeType *current)
{
    if(current != nullptr)
    {
        reversePrint(current->link); // print the tail
        cout << current->info << " "; // print the node
    }
    //cout << endl;
}

// Search linked list return true if data is found
bool search(nodeType *current, int data)
{
    bool found = false;
    while(current !=nullptr and !found)
    {
        if(current->info == data)
            found = true;
        else
            current = current->link;
    }
    return found;
}

void deleteNode(nodeType * &first, nodeType * &last, int deleteItem)
{
    /*
     We need to consider several cases:
     Case 1: the list is empty
     Case 2: The first node is the node with the given info/data, we need to adjust the pointer first and may be last
     Case 3: The node with the given info is somewhere in the list. If the node to be deleted is the last node,
        we must adjust the pointer last.
     Case 4: The list doesn't contain the node with the given info
     */
    nodeType *current = nullptr;
    nodeType *trailCurrent = nullptr;
    bool found;
    if (first == nullptr) //case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        if (first->info == deleteItem) // case 2
        {
            current = first;
            first = first->link;
            if (first == nullptr)
                last = nullptr;
            delete current;
        }
        else // search the list for the node with the given info
        {
            found = false;
            trailCurrent = first; // set the trailCurrent point to the first node
            current = first->link; // set the current to point to the second node
            while(current != nullptr && !found)
            {
                if(current->info == deleteItem)
                    found = true;
                else
                {
                    trailCurrent = current;
                    current = current->link;
                }
            }
            if (found) //case 3; if found delete the node
            {
                trailCurrent->link = current->link;
                if (last == current) // if node to be deleted is the last node, adjust last pointer
                    last = trailCurrent;
                delete current; // delete the node from the list
            }
            else
                cout << "The item to be deleted is not in the list." << endl;
        }// ende else
    } // end else
}

// insert a node at the end of the non-empty list.
void insertEnd(nodeType * &last, int data)
{
    nodeType *newNode = new nodeType;
    newNode->info = data;
    newNode->link = nullptr;
    last->link = newNode; // append new node at the last
    last = newNode; // update pointer to the last node
    cout << "Data " << data << " added at the end of the linked list." << endl;
}

// insert a node as the first node or at the beginning of the non-empty list.
void insertFirst(nodeType * &first, int data)
{
    nodeType *newNode = new nodeType;
    newNode->info = data;
    newNode->link = first;
    first = newNode;
    cout << "Data " << data << " added at the beginning of the linked list." << endl;
}

nodeType *getNode(nodeType *current, int data)
{
    bool found = false;
    while(current != nullptr and !found)
    {
        if(current->info == data)
            found = true;
        else
            current = current->link;
    }
    return current;
}

int main(int argc, char *argv[])
{
    nodeType *first = nullptr; // 1.creating an empty linked list
    nodeType *last = nullptr;  // 2.
    first = buildListForward(last);
    cout << first->link->info << endl; // print 2nd node's info
    cout << first->link->link->info << endl; // print 3rd node's info
    
    traverseLinkedList(first);
    
    // insert a new node in between first and second nodes
    // Let say p points to the first node
    nodeType *p = first;
    // create and initialize new node to add to add
    nodeType *newNode = new nodeType;
    int data = 1000;
    newNode->info = data;
    newNode->link = p->link;
    p->link = newNode;
    cout << " After adding node with 1000 into the list:" << endl;
    //reversePrint(first);
    traverseLinkedList(first);
    if (search(first, data))
        cout << data << " found!" << endl;
    else
        cout << data << " NOT found!" << endl;
    
    nodeType *node = getNode(first, data);
    cout << "node value = " <<  node->info << endl;
    // delete an existing node
    // Let's say p points the node you want to delete
    //p = first->link->link->link; // forth node in the link
    //p->link = p->link->link; // remove the node from the list, however
    // this node is dangling, i.e., memory leak
    //nodeType *q = node->link;
    //node->link = p->link;
    //delete p;
    
    deleteNode(first, last, data);
    cout << " After deleting " << data << " from the list:" << endl;
    traverseLinkedList(first);
    
    insertEnd(last, data);
    cout << "After inserting a node at the end of the list." << endl;
    traverseLinkedList(first);
    
    data = 500;
    insertFirst(first, data);
    cout << "After inserting a node at the beginning of the list." << endl;
    traverseLinkedList(first);
    //first = buildListBackward();
    
    cin.ignore(1000, '\n');
    cin.get();
    return 0;
}

