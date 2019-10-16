/*
lab 3
Date: 9.21.2016
Name: Jareth Rader
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <list>
#include <queue>

using namespace std;

//Function prototype for vectorSolution, takes a vector object and finds and prints min, max, sun, and average of numbers stored in the vector
void vectorSolution(const vector<double> &);

//Function prototype for stackSolution takes a stack object and finds and priuints min, max, sun, and average of numbers stored in the stack
void stackSolution(stack<double> &);

//function prototype for queueSolution takes a list object and finds and prints min, max, sun and average of numbers stored in queue
void queueSolution(queue<double> &);

//function prototype for listSolution takes a list object and finds and prints min, max, sun and average of numbers stored in list
void listSolution(list<double> &);

//function takes two values of type T and returns the smaller of the two
void queueSolution(queue<double> &);
template <class T>
T smaller(T, T);

//function takes two values of type T and returns the greater of the two
template <class T>
T greater(T, T);

int main(int argc, char *argv[])
{
	vector<double> vNums; //empty vector vNums to store numbers
	stack<double> sNums; //empty vector sNums to store numbers
	queue<double> qNums;//FIXME - declare queue object to store nubmers
	list<double> lNums;//FIXME - declare list object to store numbers
	
	double num;
	cout << "This program allows users to enter as many numbers as they wish \n" << " and prints Min, Max, Sum, and Avg of the entered numbers.\n\n";
	do{
		cout << "Enter a number (enter done to end): ";
		try{
			cin >> num;
			if (cin.fail()) //if non-numeric values entered, cin enters in failed state
			{
				throw "done";
			}
			vNums.push_back(num);
			sNums.push(num);
			qNums.push(num);// FIXME - store numbers in queue object
			lNums.push_front(num);// FIXME - store number in list object
		}
		catch (const char *error) // catch the exception and correct the problem
		{
			cin.clear(); // clear the failure state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ingore the rest of the streams data
			break; // break while llop; done entereing numbers
		}
	} while (true); // done entering nubmers
	
	cout << "=============================\n\n";
	vectorSolution(vNums);
	stackSolution(sNums);
	queueSolution(qNums);// FIXME - call queueSolution passing proper argument
	listSolution(lNums);// FIXME - call listSolution passing proper argument
	
	std::cin.get();
	return 0;
}

void vectorSoulution(const vector<double> &v)
{
	double min, max, sun, avg;
	min = v.front(); // say min is the front elemment of the vector
	max = v.front(); // say max in the fron element
	sun = min;
	avg = 0;
	cout << "**** Solution using Vector****" << endl;
	printf("Total Elements in vector: %u\n", v.size());
	cout << "Elements:\n";
	printf("%.2f", v.front());
	for (unsigned int i = 1; i < v.size(); i++)
	{
		min = smaller<double>(min, v[i]);
		max = greater<double>(max, v[i]);
		sum += v[i];
		printf("%.2f ",v[i]);
	}
	avg = sum / double(v.sive());
	
	printf("\n\nMin: %.2f\tSum: %.2f\tAvg: %.2f\n", min, max, sum, avg);
	cout << "========================" << endl;
}

void stackSolution(stack<double> &s)//LIFO
{
	double min, max, sun, avg;
	min = v.front(); // say min is the front elemment of the vector
	max = v.front(); // say max in the fron element
	sun = min;
	avg = 0;
	cout << "**** Solution using Stack****" << endl;
	unsigned int size = s.size();
	printf("Total Elements in stack: %u\n", size());
	cout << "Elements:\n";
	for (!s.empty())
	{
		min = smaller<double>(min, s.top());
		max = greater<double>(max, s.top());
		sum += s.top();
		s.pop();
	}
	avg = sum / double(v.size());
	
	printf("\n\nMin: %.2f\tSum: %.2f\tAvg: %.2f\n", min, max, sum, avg);
	cout << "========================" << endl;
}

// FIXME - implement queueSolution function
queueSolution(queue<double> &q){//FIFO
	double min, max, sun, avg;
	min = v.front(); // say min is the front elemment of the vector
	max = v.front(); // say max in the fron element
	sun = min;
	avg = 0;
	cout << "**** Solution using Queue****" << endl;
	printf("Total Elements in vector: %u\n", q.size());
	cout << "Elements:\n";
	for (!q.empty())
	{
		min = smaller<double>(min, q.front());
		max = larger<double>(max, q.front());\
		sum += q.front();
		q.pop();
	}
	avg = sum / double(q.size());
	
	printf("\n\nMin: %.2f\tSum: %.2f\tAvg: %.2f\n", min, max, sum, avg);
	cout << "========================" << endl;
}

listSolution(list<double> &l){// FIXME - implement listSolution function
	double min, max, sun, avg;
	min = v.front(); // say min is the front elemment of the vector
	max = v.front(); // say max in the fron element
	sun = min;
	avg = 0;
	cout << "**** Solution using List****" << endl;
	printf("Total Elements in vector: %u\n", l.size());
	cout << "Elements:\n";
	for (!l.empty())
	{
		min = smaller<double>(min, l.front());
		max = smaller<double>(max, l.front());
		sum += l.front();
		l.pop();
	}
	avg = sum / double(l.size());
	
	printf("\n\nMin: %.2f\tSum: %.2f\tAvg: %.2f\n", min, max, sum, avg);
	cout << "========================" << endl;
}

template <class T>
T smaller(T value1, T value2)
{
	return (value1 < value2) ? value1 : value2;
}

template <class T>
T greater(T value1, T value2)
{
	return (value1 > value2) ? value1 : value2;
}