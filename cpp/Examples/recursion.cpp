#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
/*
recursion:
	Problem solving technique where you reduce the problem to smaller versions of itself
	
	n! = n*(n-1)!
			|->0

	note:0! = 1
	3!
	3*2!
	3*2*1!
	3*2*1*0!
	3*2*1*1
	=6
*/

//find GCD of two numbers
//base case; if seconds denominator = 0, return first
//else; swap position of numbers, seconds number = first%second
int gcd(int num1, int num2)
{
	if(num2 == 0)
		return num1;//base case
	else
		return gcd(num2, num1%num2);//general case
}
//recursive solutions are not necessarily efficient e.g. fibonacci(100)
int fibonacci(int nth){
	if(nth == 1)
		return 1;//base case
	else
		return fibonacci(nth-1)+fibonacci(nth-2);//general case
}

//goal of recursion is to reach the base case; variable must decriment toward base case here
int factorial(int n)
{
	if(n == 0)
		return 1;//base case
	else
		return n*factorial(n-1);//general case
}

void countdown(int n){
	if(n==0){
		system("color 27");
		cout << "Happy New Year 2017 ..." << endl;
		system('cls');
		Sleep(1000);
		system("color 49");
		cout << "!@)#&^#(*^!)@*#@*" << endl;
		Sleep(1000);
		system('cls');
		system("color SF");
		cout << "!@)#&^#(*^!)@*#@*" << endl;
	}
	else{
		cout << n << endl;
		Sleep(1000);
		n--;
		//tail recursion: when the last step in the function is the recursive call
		countdown(n-1);
	}
}

int findMax(vector<int> &list, int index){
	//base case:first case == last case
	if(list.front==list.back)
		return list.front();
	//general case: store number from other index into temp int Max, and compare to first value
	else{
		int max = findMax(list, index++);
		if( max > list.front())
			return max;
		else
			return list.front();
	}
}

void towerOfHanoi(int n, string src, string help, string dst){
	if( n >= 1){
		towerOfHanoi(n-1, src, help, dst);
		//towerOfHanoi(n, src, help, dst);
		cout << "Move " << n << " from " << src << " to " << dst << endl;
		towerOfHanoi(n - 1, help, src, dst);
	}
}

int main()
{
	int n = 10;
//	cout << n << "!" << factorial(n);
//	cout << fib(20);
//	cout << "gcd (100, 40)" << gcd(100, 40) << endl;
//	countDown(n);
//	countDown(n);
	towerOfHanoi(4, "needle1", "needle2", "needle3")
	cout << "All Done" << endl;
//	int list[] = {5, 1, 10, 15, 25 };
//	cout << "max " << findMax(list, 0, 4);
	
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}