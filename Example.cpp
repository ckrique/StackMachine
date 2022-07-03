#include<iostream> 
#include<stack>
using namespace std;
#include "StackMAchine.h"

/**
 * Example
 * Runs (a / b) + 3
 */
class Example : public StackMachine {
public:
	
	int a = 4;
	int b = 2;


	
	void run() {
		
		//vector<string> tokensPostfix = infixToPostfix(/*"( A + B ) * C - ( D - E ) * ( F + G )"*/"1 * 2 + 3 * 4");
		vector<string> tokensPostfix = infixToPostfix("( ( A + B ) * ( C - ( F / D ) )");

		for (std::vector<std::string>::iterator c = tokensPostfix.begin(); c != tokensPostfix.end(); c++/*  C++  :-) C++ :-/   */) {
			std::cout << *c << std::endl;

			if (*c == " ")
				continue;
			else if (*c == "+")
				add();
			else if (*c == "-")
				sub();
			else if (*c == "*")
				mul();
			else if (*c == "/")
				div();
			else
				push(stoi(*c));
		}

		print();
		

		push(1);
		push(2);		
		mul();
		push(3);
		push(4);
		mul();
		add();

		print();
	}
};

int main()
{
	Example example;
	example.run();
}