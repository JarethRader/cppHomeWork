/*
Lab 1
CS2
Updated by: Jareth
Date: 8/15/16
Breakfast billing system
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Max # of menu items allowed
const int NO_OF_ITEMS = 8;

//Data struct on menu to store info
struct menuItemType
{
	string itemName;
	double itemPrice;
};

// init menu list with default values
void initMenuList(menuItemType menuList[], int menuListSize);
// function to read menu data into menuList array
void readMenuData(ifstream& fin, menuItemType menuList[], int menuListSize);
// function that displays the menu
void showMenu(menuItemType menuList[], int menuListSize);
// function to print checl after menu items are selected
void printCheck(menuItemType menuList[], int menuListSize, int selectedList[], int selectedMistLength);
// function to select items from menu list
void makeSelection(menuItemType menuList[], int menuListSize, int selectedList[], int& selectedListLength);
// function that returns true if the itemNo is in the selectedList otherwise false;
// this functions avoids user repeating the menu item
bool isItemSelected(int selectedList[], int selectedListLength, int itemNo);

//Main method
int main()
{
	//declare variables to be used later
	char response = 'Y';												//Variable used to continue running the program
	float fixed;														//Used to set presicion to fixed notation as opposed to scientific
	float showpoint;													//Used to set decimal point to always be written for floating point values
	menuItemType menuList[NO_OF_ITEMS];									//Initialize menuList as menuItemType with length NO_OF_ITEMS
	int choiceList[NO_OF_ITEMS];										//Initialize choiceList array variable with length NO_OF_ITEMS
	int choiceListLength;												//Initialize choiceListLength variable
	ifstream fin;														//Declare input stream and name 'fin'
	cout << fixed << showpoint << setprecision(3);						//Set precision of floating point values to go out 2 decimal points for cout

	fin.open("menu.txt");												//Open input file
	//if fin cannot be found, throw exception, prompt user, and end program
	if (!fin)
	{
		cout << "Input file does not exist. Program terminates!" << endl;
		cin.get();
		return 1;
	}
	//initialize menuList with default values
	initMenuList(menuList, NO_OF_ITEMS);
	//FIXME
	//read info from input file into menuList struct
	readMenuData(fin, menuList, NO_OF_ITEMS);

	//close input file
	fin.close();
	//loop through displaying menu, making menu selections, and printing checks until user wants to stop
	while(response == 'Y' || response =='y')
	{
		//display menu to the user
		showMenu(menuList, NO_OF_ITEMS);
		//run function to allow user to select items from the menu previously displayed
		makeSelection(menuList, NO_OF_ITEMS, choiceList, choiceListLength);
		//run function to print check of items selected by the user
		printCheck(menuList, NO_OF_ITEMS, choiceList, choiceListLength);
		//Asks user if they want to continue or not
		//store user response
		while(true)
		{
			cout << "Do you want to continue the program? Y/y (Yes), N/n (No) :" << endl;
			cin >> response;
			if(response == 'Y' || response == 'y' || response == 'N' || response == 'n')
				break;
			else
				cout << "invalid response, try again" << endl;
		}
	}	
	//wait for input from the user to continue
	cin.get();
	cin.get();
	return 0;
}

// init menu list with default values
void initMenuList(menuItemType menuList[], int menuListSize)
{
	//Run through all indexes of menuList struct
	for (int i = 0; i < menuListSize; ++i)
	{
		//FIXME
		menuList[i].itemName = "A Tasty Item";		//initialize all menu item names as "A Tasty Item"
		menuList[i].itemPrice = 0.0;				//initialize all menu prices as $0.0
	}
}

// function to read menu data into menuList array
void readMenuData(ifstream& fin, menuItemType menuList[], int menuListSize)
{
	char ch;										
	string line;									//declare string placeholder to be used later in function
	float price;									//declare float placeholder to be used later in function
	//run through all indexes of menuList
	for (int i = 0; i < menuListSize; i++)
	{
		//get first line from input file
		getline(fin,line);
		//read until newline character and store string read to string 'line'
		cout << line << '\n';
		//assign menuList itemName at index 'i' equal to line just read from file
		menuList[i].itemName = line;
		//read price of item and store in float 'price'
		fin >> price;
		//read until newline character
		getline(fin,line);
		//assign menulist itemPrice at index 'i' equal to float just read from file
		menuList[i].itemPrice = price;
	}
}

// function that displays the menu
void showMenu(menuItemType menuList[], int menuListSize)
{
	//prompt user a greeting
	cout << "Welcome to Papi Joey's Kitchen" << endl;
	cout << "----Today's Menu----" << endl;

	//run through all menuList values and display to the user
	for (int i = 0; i < menuListSize; i++)
	{
		//cout << i + 1 << ": ";
		//cout << menuList[i].itemName;
		//cout << setfill (' ') << setw(20-(menuList[i].itemName).size()) << " $" << menuList[i].itemPrice << endl;
		cout << i + 1 << ": "<<	std::left << setw(15) << menuList[i].itemName << std::right << " $"<< menuList[i].itemPrice << endl;
	}
	cout << endl;
}

// function to print checl after menu items are selected
void printCheck(menuItemType menuList[], int menuListSize, int selectedList[], int selectedListLength)
{
	string reciptName;								//variable to store user defined recipt file name
	int i, fixed, showpoint;						//declare integer variables used in function
	double salesTax;								//declare double variable to store sales tax value_comp
	double amountDue = 0;							//declare double to store final check amount
	ofstream myfile;								//declare output file
	myfile << fixed << showpoint << setprecision(3);//set precision of output file to go out 2 decimal places
	//ask user for Recipt file name
	cout << "Enter Recipt File Name: " << endl;
	//Store user input
	cin >> reciptName;
	//create .txt file from user input and open
	myfile.open((reciptName+".check").c_str());
	//Format check info that will be displayed to the user and be saved to output file
	cout << setfill('=') << setw(25) << endl;
	cout << "" << endl;
	cout << " Papi Joey's kitchen" << endl;
	cout << "     Guest Check    " << endl;
	cout << setfill(' ') << endl;
	myfile << setfill('=') << setw(25) << endl;
	myfile << "" << endl;
	myfile << " Papi Joey's kitchen" << endl;
	myfile << "     Guest Check    " << endl;
	myfile << setfill(' ') << endl;
	//read through user selected items and write name and price to check and output file
	for (i = 0; i < selectedListLength; i++)
	{
		cout << menuList[selectedList[i]].itemName << setfill(' ') << setw(20-(menuList[selectedList[i]].itemName).size())<< " $" << menuList[selectedList[i]].itemPrice << endl;
		myfile << menuList[selectedList[i]].itemName << setfill(' ') << setw(20-(menuList[selectedList[i]].itemName).size())<< " $" << menuList[selectedList[i]].itemPrice << endl;
		//Update total amount
		amountDue += menuList[selectedList[i]].itemPrice;
	}
	cout << endl;
	myfile << endl;
	//define salesTax based on total
	salesTax = amountDue * .07;
	cout << setw(7) << "Tax" << setfill(' ') << setw(10) << " $" << salesTax << endl;
	myfile << setw(7) << "Tax" << setfill(' ') << setw(10) << " $" << salesTax << endl;
	//calculate final amount with tax
	amountDue = amountDue + salesTax;
	//display final amount to user
	cout << setw(15) << "Amount Due " << " $" << amountDue << endl << endl;
	cout << setfill('=') << setw(25) << ' ' << endl;
	cout << "" << endl;
	cout << "        Thank You!        " << endl;
	//write final amount to output file
	myfile << setw(15) << "Amount Due " << " $" << amountDue << endl << endl;
	myfile << setfill('=') << setw(25) << ' ' << endl;
	myfile << "" << endl;
	myfile << "        Thank You!        " << endl;
	//close output file
	myfile.close();
	//FIXME
	
}

// function to select items from menu list
void makeSelection(menuItemType menuList[], int menuListSize, int selectedList[], int& selectedListLength)
{
	int itemNo;								//Declare variable to store user item number choice
	char response;							//Declare variable to store user response if they want to make a selection
	selectedListLength = 0;					//Define length of selected list

	//Ask user if they want to make a selection and store response
	cout << "You can make up to " << menuListSize << " single order selections" << endl;
	//loop to prevent inproper user input
	while(true)
	{
		cout << "Do you want to make a selection Y/y (Yes), N/n (NO): ";
		cin >> response;
		if(response == 'Y' || response == 'y' || response == 'N' || response == 'n')
			break;
		else
			cout << "invalid response, try again" << endl;
	}
	cout << endl;

	//if response is yes, run loop to allow them to make their menu selection(s)
	while ((response == 'Y' || response == 'y') && selectedListLength < 8)
	{
		//Ask for menu item number, or 0 if done
		cout << "Enter item number(0 if done selecting): ";
		//store user response
		cin >> itemNo;
		cout << endl;

		//End loop if response is 0
		if(itemNo == 0)
			break;
		else if(itemNo > 8)
			cout << "No item corresponding to number choosen, please pick again" << endl;
		//Check if item number has alreadt been selected, if not, store selected number into selected list
		else if (!isItemSelected(selectedList, selectedListLength, itemNo))
			selectedList[selectedListLength++] = itemNo - 1;
		//If item number has been selected, prompt user and allow to make another selection
		else
			cout << "Item already selected:" << endl;
	}
}

// function that returns true if the itemNo is in the selectedList otherwise false;
bool isItemSelected(int selectedList[], int selectedListLength, int itemNo)
{
	//FIXME
	//sort through selectedList and check if itemNo is stored
	for( int i = 0; i < selectedListLength; i++)
	{
		//If itemNo is found, return try
		if(selectedList[i]==itemNo - 1)
			return true;
	}
	//if itemNo is not found, return false
	return false;
} 	