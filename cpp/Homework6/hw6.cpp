#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//struct to store student data
struct studentType{
	studentType(string id, string first, stirng last, int test1, int test2, int test3)
	{
		this->id = id;
		this->first = first;
		this->last = last;
		this->test1 = test1;
		this->test2 = test2;
		this->test3 = test3;
	}
	string id;		//student id
	string first;	//first name
	string last;	//last name
	int test1;		//test 1 score
	int test2; 		//test 2 score
	int test3; 		//test 3 score	
	double testAvg;	//Test score average
}
//struct for singly linked list to hold type studentType
struct node{
	studentType info;
	node *link;
}
//create ordered linked list and read in data from file into list
void node *createOrderedLinkedList(ifstream &in, numNode * &last);
//function to add new node to end of linked list
void insertNewNode(numNode * &first, numNode * &last, numNode *newNode);
//function to read in student data fron file
studentType readStudentData(ifstream &in,);
//function to take find average test score of in studentType
double findAvg(studentType student);



int main(){
	
	node *first = nullptr;
	node *last = nullptr;
	
	//ask user for name of file to open
	string fileName;	//variable to hold user-defined filename
	cout << "Enter name of file" << endl;
	cin >> fileName;
	//open file
	ifstream in;
	in.open(fileName+"txt".c_str());
	if(!in)
	{
		cout << "Input file does not exist. Program Terminating" << endl;
		cin.get();
		return 0;
	}
	else
	{
		first = createOrderedLinkedList(in, last);
	}
	
		
	while (true){
		//menu options
			//add new student
			//delete student using ID
			//display students data in nice tabular format with heading for each column; Sorted by ascending student ID
			//save data back into file
			//exit program
			//BONUS: search for player and edit their test scores		
		int response;	// int to store user menu choice
		cout << "Menu\n 1. Display Students\n 2. Add Student\n 3. Delete Student\n 4. Save Data\n 5. Exit Program" << endl;
		switch(response)
		{
			case 1:{		//display students;
				
			}
			case 2:{		//add student
			
			}
			case 3:{		//delete students
				
			}
			case 4:{		//save data
				
			}
			case 5:{		//exit program
				
			}
		}
	}	
	
	cin.get();
	return 0;
}

node *createOrderedLinkedList(ifstream &in, numNode * &last)
{
	numNode *first = nullptr, *newNode = nullptr;
	numNode *current;
	bool done = false;
	studentType student;
	while(!done)
	{
		newNode = new numNode;
		while(!in.eof)
		{
			try
			{
				student = readStudentData(in)
				if(!student)
					throw "error";
				newNode->info = student; // store student data into node
				newNode->link = nullptr;
				insertNewNode(first, last, newNode); //insert the new node into linked list
			}
			catch (const char *err)
			{
				cin.clear();
				cin.ignore(100, '\n');
				done = true;
			}
		}
	}
	return first;
}

studentType readStudentData(ifstream &in)
{
	studentType temp;
	string id;
	string first;
	string last;
	int test1;
	int test2;
	int test3;
	in >> id >> first >> last >> test1 >> test2 >> test3;
	studentType temp = new studentType(id, first, last, test1, test2, test3);
	return temp;
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