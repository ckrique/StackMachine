#include<iostream> 
#include<stack>
using namespace std;
#include "StackMAchine.h"

class Example : public StackMachine {
public:
	
	void run() {
		
		
		// infix  10 + 3 * 5 / 3 
		// posfix	10  3  5 * 3/+
		vector<string> tokensPostfix;
		tokensPostfix.push_back("10");
		tokensPostfix.push_back("3");
		tokensPostfix.push_back("5");
		tokensPostfix.push_back("*");
		tokensPostfix.push_back("3");
		tokensPostfix.push_back("/");
		tokensPostfix.push_back("+");
		
		string strTokens;

		for (std::vector<std::string>::iterator c = tokensPostfix.begin(); c != tokensPostfix.end(); c++ /*  C++  :-) C++ :-/   */) 
		{
			strTokens += *c;
			strTokens += " "; 			
		}
		cout << strTokens << endl;

		for (std::vector<std::string>::iterator c = tokensPostfix.begin(); c != tokensPostfix.end(); c++ /*  C++  :-) C++ :-/   */) {
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
			else if (*c != "(" && *c != ")")
				push(stoi(*c));

			printStackItens();
		}

		print();
	}
};

int main()
{
	Example example;
	example.run();
}