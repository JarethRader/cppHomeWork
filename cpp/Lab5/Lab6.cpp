/*
Program uses forward singly liked list to sroe some unique numbers in order
Program uses menu options ot perform various operations on the numbers stored in the linked list
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//data structure to reresent number for forward singly-linked list
struct numNode
{
	double num;
	numNode *next;
};

//function that create ordered linked list
numNode *createOrderedLinkedList(numNode * &last);

//function that prints numbers on the screen
void printData(numNode *current, bool all=true);

//function that will inser a new node in ascending order
void insertNewNode(numNode * &first, numNode * &last, numNode *newNode);

//search and return a node
numNode *getNode(numNode *current);

//search node given its value
bool searchList(numNode *current, double num);

//delete node given its value
void deleteNode(numNode * &first, numNode * &last, double num);

//displau menu options
void showMenu();

//function that finds the average of numbers stored in linked list
double findAverage(numNode *current);

int main(int argc, char* argv[])
{
	int choice;
	
	numNode *first = nullptr;
	numNode *last = nullptr;
	numNode *node = nullptr;
	numNode *newNode = nullptr;
	double num;
	bool found;
	
	first = createOrderedLinkedList(last);
	
	do
	{
		showMenu();
		cin >> choice;
		cout << endl;
		cin.ignore(100, '\n');
		switch(choice)
		{
		case 1: //display data
			system("cls");
			printData(first);
			break;
		case 2: //Search a Number
			system("cls");
			node = getNode(first);
			
			//FIXME
			//Call printData Functions to print just the data stored in the node
			
			break;
		case 3: //add a new node
			system("cls");
			newNode = new numNode;
			newNode->next = nullptr;
			found = false;
			do
			{
				cout << "Enter a new number to add: " << endl;
				cin >> newNode->num;
				found = searchList(first, newNode->num);
				if(found)
					cout << "Node with that value already exists!" << endl;
			}while(found);
			
			insertNewNode(first,last, newNode);
			cout << "New number added successfully in the list! hit enter to continue...\n";
			cin.ignore(100, '\n');
			cin.get();
			break; //done add new value
		case 4: //delete a node
			cout << "enter number to be deleted: " << endl;
			cin >> num;
			deleteNode(first, last, num);
			break;
		case 5:
			//FIXME
			//call findAverage function and print the average with proper description
			system("cls"); 
			cout << "Average of list: " << findAverage(first) << endl;
			cout << "Enter  to continue...";
			cin.get();
			break;
		case 6:
			//FIXME
			//Print the smallest number in the list
			system("cls");
			cout << "Smallest number in the list: " << first->num << endl;
			cout << "Enter  to continue...";
			cin.get();
			break;
		case 7:
			//FIXME
			//Prints the largest number in the list
			system("cls");
			cout << "Largest number in the list: " << last->num << endl;
			cout << "Enter  to continue...";
			cin.get();
			break;
		case 0:
			break;
		default:
			cout << "Invalid selection." << endl;
		} // end switch
	}while(choice !=0);
	//cin.ignore(100, '\n');
	cout << "Good Bye... Enter to exit the program.";
	cin.get();
	return 0;
}

void showMenu()
{
	cout << setw(50) << setfill('=') << ' ' << endl;
	cout << "*** Numbers stored in ordered linked list ***" << endl << endl;
	cout <<	"Select one of the following options:" << endl;
	cout << setw(50) << ' '<<	endl << endl;
	cout << setfill(' ');
	cout <<	"1:	Print all numbers in list"<< endl;
	cout <<	"2:	Search a number in list"<< endl;
	cout <<	"3:	Add a new number "<< endl;
	cout <<	"4:	Delete a number "<< endl;
	cout <<	"5.	Print average of numbers "<< endl;
	cout <<	"6.	Print the min number "<< endl;
	cout <<	"7.	Print the max number "<< endl;
	cout <<	"0:	Quit the program"<<	endl;
}

numNode *createOrderedLinkedList(numNode * &last)
{
	numNode *first = nullptr, *newNode = nullptr;
	numNode *current;
	bool done = false;
	double num = 0;
	while(!done)
	{
		newNode = new numNode;
		cout << "Enter a number, or done when done ->";
		try
		{
			cin >> num;
			if(cin.fail())
				throw "error";
			newNode->num = num; // store num into nimNode's num member
			newNode->next = nullptr;
			insertNewNode(first, last, newNode); //insert the new node  into linked list
		}
		catch (const char *err)
		{
			cin.clear();
			cin.ignore(100, '\n');
			done = true;
		}
	}
	return first;
}

void printData(numNode *current, bool all)
{
	if (all)
		cout << setw(30) << right << "All Values un Ordered Linked List" << endl;
	else
		cout << setw(30) << right << "Individuale Value Found in Linked List" << endl;
	cout << setw(80) << setfill('=') << ' ' << endl;
	cout << setfill(' ');
	cout << fixed << setprecision(2);
	while (current != nullptr)
	{
		cout << current->num << ' ';
		if(all)
			current = current->next;
		else
			break;
	}
	cout << endl;
	cout << setw(80) << setfill('=') << ' ' << endl;
}

numNode *getNode(numNode *current)
{
	double num;
	cout << "Enter a number search: ";
	cin >> num;
	bool found = false;
	bool again = false;
	do
	{
		while(current != nullptr && !found)
		{
			if(current->num == num)
			{
				found = true;
				again = false;
			}
			else
				current = current->next;
		}
		if(!found)
		{
			cout << "Given number " << num << " not found. Enter another number to search for: ";
			cin >> num;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				again = false;
			}
		}
	}while(again);
	return current;
}

bool searchList(numNode *current, double num)
{
	bool found = false;
	
	while(current != nullptr && !found)
	{
		if(current->num == num)
			found = true;
		else if(current->num < num) //no need to continue to search in ordered linked list
			break;
		else
			current = current->next;
	}
	return found;
}

void insertNewNode(numNode * &first, numNode * &last, numNode *newNode)
{
	numNode *current = nullptr;
	numNode *trailCurrent = nullptr;
	
	bool found;
	if(first == nullptr) // case 1: empty list
	{
		first = newNode;
		last = newNode;
	}
	else // find the current node to inser right at that position
	{
		current = first;
		found = false;
		while(current != nullptr && !found)
		{
			if(current->num >=newNode->num)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		}
		if(current == first) // Case 2 if newNode's value is smaller than first node
		{
			newNode->next = first; // insert at the first node
			first = newNode; // update first node
		}
		else
		{
			trailCurrent->next = newNode; // insert new node at the current node
			newNode->next = current; // insert new node fter the current nodel update links
			if(current == nullptr) // case 3; newNode's value is larger than the last node
				last = newNode;
		}
	}
}

void deleteNode(numNode * &first, numNode * &last, double num)
{
	numNode *current;
	numNode *trailCurrent = nullptr;
	bool found;
	if(first == nullptr) // case 1: empty listl can't delete from it
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		current = first;
		found = false;
		// Case 2: Search the list
		while(current != nullptr && !found)
		{
			if(current->num >= num) //data may or may not have been found...
				//no need to continue search in ordered list
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		}
		if(current == nullptr)
		{
			cout << "The item to be deleted is not in the ist." << endl;
		}
		else // the item to be deleted is in the list
		{
			if(current->num == num)
			{
				//case 2a: if the item to be eleted is contained in the first node of the list
				//adjust the head pointer of the list-  that is, first.
				if(current == first)
				{
					first = first->next;
					if(first == nullptr) // list becomes empty after deleteing first node
						last = nullptr;
						
					delete current; // delete the memory pointed to by current
				}
				else // case 2b:
				{
					trailCurrent->next = current->next;
					if(current == last) //case 3: if the item to be deleted is contained in the last node of the list
						//adjust the tail of the list -- that is, last.
						last = trailCurrent;
					
					delete current;
				}
				cout << "Number " << num << "deleted from the list." << endl;
			}
			else
			{
				cout << "The item to  be deleted is not in the list." << endl;
			}
		}
	}
}

//FIXME Implement findAverage function
double findAverage(numNode *current){
	double sum = 0.0;
	int count = 1;
	while(current->next != nullptr)
	{
		sum += current->num;
		current = current->next;
		count ++;
	}
	sum += current->num;
	double avg = sum/count;
	return avg;
}