#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "LinkedStack.h"
using namespace std;

string infixToPostfix(string infix);

int main(){
	string infix, postfix;
	cout << "Enter an infix notation: ";
	cin >> infix;
	postfix = infixToPostfix(infix);
	cout << "Infix Notation = " << infix << "\nPostfix Notation = " << postfix << endl;
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}

string infixToPostfix(string infix)
{
	LinkedStack<char> ls1;
	string postfix;
	while(infix.length() > 0)
	{
		if(infix[0].isdigit)
		{
			postfix.insert(postfix.length()-1,(infix[0].c_str()));
			infix.erase(infix.begin());
		}	
		else if(infix[0] == '(')
		{
			ls1.push(infix[0]);
			infix.erase(infix.begin());
		}
		else if(infix[0]=='*' || infix[0]=='/' || infix[0]=='+' ||  infix[0]=='-')
		{
			if(ls1.isEmpty || ls1.top() == '(')
			{
				ls1.push(infix[0]);
				infix.erase(infix.begin());
			}
			else
			{
				if(infix[0]=='*' || infix[0]=='/' && ls1.top()=='+' || ls1.top()=='-')
				{
					ls1.push(infix[0]);
					infix.erase(infix.begin());
				}
				else if(infix[0]=='+' || infix[0]=='-' && ls1.top()=='*' || ls1.top()=='/')
				{
					while(ls1.top()=='+' || ls1.top()=='-')
					{
						postfix.insert(postfix.length()-1,(infix[0].c_str()));
						ls1.pop();
					}
					ls1.push(infix[0]);
					infix.erase(infix.begin());
				}
				else
				{
					if(infix[0]=='*' || infix[0]=='/' && ls1.top()=='*' || ls1.top() =='/')
					{
						postfix.insert(postfix.length()-1,(infix[0].c_str()));
						ls1.pop();
						ls1.push(infix[0])
						infix.erase(infix.begin());
					}
					if(infix[0]=='+' || infix[0]=='-' && ls1.top()=='+' || ls1.top() =='-')
					{
						postfix.insert(postfix.length()-1,(infix[0].c_str()));
						ls1.pop();
						ls1.push(infix[0])
						infix.erase(infix.begin());
					}
				}
			}
		}
		else if(infix[0] == ')')
		{
			while(!ls1.top()=='(')
			{
				postfix.insert(postfix.length()-1,ls1.top());
				ls1.pop();
			}
			if(ls1.top()=='(')
				ls1.pop();
			infix.erase(infix.begin());
		}
		else if(infix.length()==0)
			while(!ls1.isEmpty())
			{
				postfix.insert(postfix.length()-1,ls1.top());
				ls1.pop();
			}
	}
	if(infix.length()==0)
		while(!ls1.isEmpty())
		{
			postfix.insert(postfix.length()-1,ls1.top());
			ls1.pop();
		}
	return postfix;
}