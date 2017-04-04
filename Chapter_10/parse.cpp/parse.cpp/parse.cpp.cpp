// parse.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring> //for strlen(), etc

const int LEN = 80;
const int MAX = 40;
//-----------------------------------------------------------------
class Stack {
private:
	char st[MAX];
	int top;
public:
	Stack() { top = 0; } //constructor
	void push(char var) { //put char on stack
		st[++top] = var;
	}
	char pop() {
		return st[top--];
	}
	int gettop() {
		return top;
	}
};
//-----------------------------------------------------------------
class express {
private:
	Stack s;
	char*pStr;
	int len;
public:
	express(char*prt) : pStr(prt), len(std::strlen(pStr)) { std::cout << "\n\ttest string = " << *pStr << "\n\ttest addres reference = " << &pStr << "\n\ttest length = " << len << std::endl; }
	void parse(); //parse the input string
	int solve(); //evaluate the stack
};
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void express::parse() {
	char ch;
	char lastval;
	char lastop;

	for (int j = 0; j < len; j++) {
		ch = pStr[j];
		if (ch >= '0' && ch <= '9')
			s.push(ch - '0');
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			if (s.gettop() == 1)
				s.push(ch);
			else {
				lastval = s.pop();
				lastop = s.pop();
			//if this is * or / AND last operator was + or -
				if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-')) {
					s.push(lastop);
					s.push(lastval);
				}
				else {
					switch (lastop)
					{
						case '+' : s.push(s.pop() + lastval); break;
						case '-' : s.push(s.pop() - lastval); break;
						case '*' : s.push(s.pop() * lastval); break;
						case '/' : s.push(s.pop() / lastval); break;
					default:
						std::cout << "\nUnknown operator\n"; system("pause"); exit(1);
						break;
					} //end switch
				} //end else
				s.push(ch);
			} //end else, not first operator
		} //end else if, not first operator
		else {
			std::cout << "\nUnknown input character\n";
			system("pause");
			exit(1);
		}
	} //end for
} //end parse()
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int express::solve() { //remove items from stack
	char lastvar;
	while (s.gettop() > 1) {
		lastvar = s.pop();
		switch (s.pop())
		{
			case '+': s.push(s.pop() + lastvar); break;
			case '-': s.push(s.pop() - lastvar); break;
			case '*': s.push(s.pop() * lastvar); break;
			case '/': s.push(s.pop() / lastvar); break;
		default:
			std::cout << "\nUnknow operator\n"; system("pause"); exit(1);
		} //end switch()
	} //end while()
	return int(s.pop());
} //end solve()
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main()
{
	char ans;
	char string[LEN];

	std::cout << "\nEnter an arethmetic expression"
				 "nof the form 2+3*4/3-2"
				 "\nNo number may have more than one digit."
				 "\nDon't use any spaces or parentheses.";
	do
	{
		std::cout << "\nEnter expression: ";
		std::cin >> string;
		express* ex = new express(string);
		ex->parse();
		std::cout << "\nThe numerical value is: "
			<< ex->solve();
		delete ex;
		std::cout << "\nDo another (y/n)";
		std::cin >> ans;
	} while (ans == 'y');
    return 0;
}

