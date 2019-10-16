/*
	CS2
	Lab4
	
	Updated by: Jareth Rader
	Date: 10.6.2016
	
	Program: number system converter
	
	the program uses recursion to find the binary, and octal representation of given decimal number and vice versa.
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

//System specific macro function sysclear that cleas console text
#ifdef _WIN32
#define sysclear() system("cls")
#else //Must be *nix system
#define sysclear() system("clear")
#endif

//Recursively converts decimal number to binary representation
string decToBin(long num);
//Recursively converts binary number to decimal representation
long binToDec(string binaryNum, int position);
//Recursively converts decimal number to octal representation
string decToOct(long num);
//Recursively converts octal number to decimal representation
long octToDec(string octNum, int position);
//Recursively converts decimal to hex representation
string decToHex(long num);
//Recursively converts hex to decimal representation
long hexToDec(string hexNum, int position);

int main()
{
	int decimalNum;
	int numPosition;
	int binaryNum;
	
	numPosition = 0;
	bool valid = false;
	
	string response = "yes";
	while (response == "yes")
	{
		sysclear();
		valid = false;
		cout << "Program converts decimal number into binary \n and octal number systems and vice versa. \n\n";
		//User input with validation
		do{
			cout << "Enter a number in decimal: ";
			try
			{
				cin >> decimalNum;
				if (cin.fail())
				{
					throw "Invalid input, try again!";
				}
				valid = true;
			}
			catch (const char *error)
			{
				cin.clear(); // clear the cin faliure state
				cin.ignore(100, '\n'); //ignore next 100 characters of up to the \n char
				printf("%s\n, error");
			}
		}while (!valid);
		cout << endl;
		
		string binary = decToBin(decimalNum);
		
		printf("(%u) base 10 = (%s) base 2\n", decimalNum, binary.c_str());
		printf("(%s) base 2 = (%u) base 10\n", binary.c_str(), binToDec(binary, numPosition));
		
		//FIXME - call decToOct functions passing proper arguments and display the values with proper descriptions
		string octal = decToOct(decimalNum);
		printf("(%u) base 10 = (%s) base 2\n", decimalNum, octal.c_str());
		// FIXME - call octToDec function passing proper arguments and dilspay the values with proper descriptions.
		printf("(%s) base 2 = (%u) base 10\n", octal.c_str(), octToDec(octal, numPosition));
		cin.ignore();
		cout << "Would you like to convert another number? enter yes/no:\n";
		cin >> response;
	}
	cin.ignore();
	cout << "Good bye! Enter to quit!";
	cin.get();
	return 0;
}

string decToBin(long num)
{
	/*
		Algorithm steps:
		1. base case: binary of decimal num 0 is 0
		2. otherwise,
			a. Get the first remainder after dividing num by 2
			b. Get the rest of the remainder one at a time recursively
			c. insert the rest of remainder at the front of binary string variable
		3. return the final binary value_comp
	*/
	string binary = "";
	int base = 2;
	if (num == 0) //1
		return "0";
	else
	{
		string remainder = to_string(num%base); //2.a
		num = num / base;
		binary = remainder;
		remainder = decToBin(num); //2.b
		binary.insert(0, remainder); //2.c
		return binary; // 3
	}
}

long binToDec(string binaryNumber, int position)
{
	/*
	binary number is recieves as a string value
	Algorithm steps;
	1. base case: if binaryNumber is empty or 0, decimal is 0
	2.otherwise,
		i. extract the rightmost bitset
		ii. convert char bit into int ,e.g., '1' is converted to 1
		iii. get the decimal value for the bit position by using formal bit*pow(2, position)
		iv. recursively find the decimal of the rest of the bits and add all the returned values
	3. return the final decimal value
	*/
	char bit;
	long dec = 0;
	
	if(binaryNumber.length() == 0) //base case
		return 0;
	else
	{
		unsigned long index = binaryNumber.length() -1;
		bit = binaryNumber[index]; // 2.i
		bit = int(bit) - int('0'); // 2.ii
		long bitValue = bit * static_cast<int>(pow(2.0, position)); // 2.iii
		dec = bitValue;
		binaryNumber = binaryNumber.substr(0, binaryNumber.length() -1); //remove the last bit
		position++; // increment the position
		dec += binToDec(binaryNumber, position); //2.iv
		return dec; //3
	}
}

//FIXME - implement decToOct function
string decToOct(long num)
{
/*
	Algorithm steps:
	1. base case: octal of decimal num 0 is 0
	2.otherwise,
		a. Get the first remainder after dividing num by 8
		b. Get the rest of the remainder one at a time recursively and insert them at the front of the octal string variable
	3. return the final octal value
*/
	string octal = "";
	int base = 8;
	if(num == 0) // 1
		return 0;
	else
	{
		string remainder = to_string(num % base); // 2.a
		num = num / base;
		octal = remainder;
		remainder = decToOct(num); // 2.b
		octal.insert(0, remainder);
		return octal; // 3
	}
}

//FIXME - implement octToDec function
long octToDec(string octNum, int position)
{
/*
	Octal number is recieves as a string value and the first position from the back
	Algorithm steps:
	1. base case: if octal number is empty or 0, decimal is 0
	2. otherwise,
		i. extract the rightmost number
		ii. convert char value into int, e.g.m '7' is converted to 7
		iii. get the decimal value for the octal position using formula octal*pow(8, position)
		iv. recursively find the decimal vaue of the rest of the octal numbers and add all the returned values
	3. return the final decimal value
*/
	char bit;
	long dec;
	
	if(octNum.length() == 0)
		return 0;
	else
	{
		unsigned long index = octNum.length() -1;
		bit = octNum[index]; // 2.i
		bit = int(bit) - int('0'); // 2.ii
		long bitValue = bit * static_cast<int>(pow(8.0, position)); // 2.iii
		dec = bitValue;
		octNum = octNum.substr(0, octNum.length() -1); //remove the last bit
		position++; // increment the position
		dec += binToDec(octNum, position); //2.iv
		return dec; //3
	}
}

string decToHex(long num)
{
	/*
	// A, B, C, D, E, F represents 10 - 15
	Algorithm steps:
	1. base case: hex of decimal num 0 is 0
	2. otherwise,
		a. Get the first remainder by dividing number by base 16
		b. Get A-F value for 10 - 15
		c. Get the rest of the remainder one at a time recursively and insert them at the front of the hex string variable
	3. return hex value
	*/
	string hex = "";
	int base = 16;
	if(num == 0) // 1
		return 0;
	else
	{
		string remainder = to_string(num % base); // 2.a
		num = num / base;
		if((num%base) >= 10) // 2.b
		{
			switch(num%base)
			{
				case 10:
					hex.insert(0, "A");
					break;
				case 11:
					hex.insert(0, "B");
					break;
				case 12:
					hex.insert(0, "C");
					break;
				case 13:
					hex.insert(0, "D");
					break;
				case 14:
					hex.insert(0, "E");
					break;
				case 15:
					hex.insert(0, "F");
					break;
			}
		}
		remainder = decToHex(num); // 2.c
		hex.insert(0, remainder);
		return hex; // 3
	}
}


long hexToDec(string hexNum, int position)
{
	/*
	Hex number is recieves as a string value and the first position from the back
	Algorithm steps:
	1. base case: if Hex number is empty or 0, decimal is 0
	2. otherwise,
		i. extract the rightmost number
		ii. convert char value into int, e.g. '7' is converted to 7
		ii.a. Convert A-F value into 10-15 respectivly
		iii. get the decimal value for the hex position using formula hex*pow(16, position)
		iv. recursively find the decimal vaue of the rest of the hex numbers and add all the returned values
	3. return the final decimal value
	*/
	
	char bit;
	long dec;
	
	if(hexNum.length() == 0) // 1
		return 0;
	else
	{
		unsigned long index = hexNum.length() - 1;
		bit = hexNum[index]; // 2.i
		if(isdigit(bit))
			bit = int(bit) - int('0'); // 2.ii
		else
		{
			switch(bit)
			{
				case 'A':
					bit = 10;
					break;
				case 'B':
					bit = 11;
					break;
				case 'C':
					bit = 12;
					break;
				case 'D':
					bit = 13;
					break;
				case 'E':
					bit = 14;
					break;
				case 'F':
					bit = 15;
					break;
			}
		}
		long bitValue = bit * static_cast<int>(pow(16.0, position)); // 2.iii
		dec = bitValue;
		hexNum = hexNum.substr(0, hexNum.length() - 1); //remove the last bit
		position++; // increment the position
		dec += hexToDec(hexNum, position); // 2.iv
		return dec;	
	}
}