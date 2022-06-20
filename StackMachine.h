#include<iostream> 
#include<stack>
#include<map>
#include<vector>
#include <string>
#include "bits-stdc++.h"

using namespace std;

class StackMachine {
private:

	 stack<int> javaStack;


public:
	int fullPop(stack<int>* stackParam)
	{
		int auxRegister = stackParam->top();
		stackParam->pop();
		return auxRegister;
	}

	void push(int n) {
		javaStack.push(n);
	}

	void add() {
		javaStack.push(fullPop(&javaStack) + fullPop(&javaStack));
	}

	void sub() {
		int y = fullPop(&javaStack);
		int x = fullPop(&javaStack);
		javaStack.push(x - y);
	}

	void mul() {
		javaStack.push(fullPop(&javaStack) * fullPop(&javaStack));
	}

	void div() {
		int y = fullPop(&javaStack);
		int x = fullPop(&javaStack);
		javaStack.push(x / y);
	}

	void swap() {
		int x = fullPop(&javaStack);
		int y = fullPop(&javaStack);
		javaStack.push(x);
		javaStack.push(y);
	}

	void drop() {
		javaStack.pop();
	}

	void dup() {
		javaStack.push(javaStack.top());
	}

	void over() {
		int first = fullPop(&javaStack);
		int second = javaStack.top();
		javaStack.push(first);
		javaStack.push(second);
	}

	bool jz() {
		return fullPop(&javaStack) == 0;
	}

	bool jnz() {
		return !jz();
	}

	bool jgz() {
		return fullPop(&javaStack) > 0;
	}

	bool jlz() {
		return fullPop(&javaStack) < 0;
	}

	void clear() {
		
		stack<int>().swap(javaStack);
	}
	/*
	bool matches(int a[]) {
		if ((*(&a + 1) - a) != javaStack.size()) {
			return false;
		}

		for (int i = 0; i < javaStack.size(); i++) {
			if (javaStack.get(i) != a[i]) {
				return false;
			}
		}

		return true;
	}
	*/
	void run();

	void print() {
		for(int i = 0; i < javaStack.size(); i++)
		{			
			cout << fullPop(&javaStack) << " " << endl;
		}
	}

	vector<string> split(string str, char del) {
		
		vector<string> strVec;
		string temp = "";

		for (int i = 0; i < (int)str.size(); i++) {
			// If cur char is not del, then append it to the cur "word", otherwise
			  // you have completed the word, print it, and start a new word.
			
			if (str[i] != del) {
				temp += str[i];
			}
			else {
				strVec.push_back(temp);
				temp = "";
			}
		}

		strVec.push_back(temp);

		return strVec;
	}


	vector<string> infixToPostfix(string infixExpr) 
	{
		map<string, int> prec;
		prec["*"] = 3;
		prec["/"] = 3;
		prec["+"] = 2;
		prec["-"] = 2;
		prec["("] = 1;
		stack<string> opStack;
		vector<string> postfixList;
		postfixList.push_back(" ");
		
		vector<string> tokenList = split(infixExpr,' ');

		string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string numbers = "0123456789";

		for (string token : tokenList)
			if (letters.find(token) != string::npos || numbers.find(token) != string::npos)
				postfixList.push_back(token);
			else if (token == "(")
				opStack.push(token);
			else if  (token == ")")
			{
				string topToken = opStack.top();
				opStack.pop();
					while (topToken != "(")
					{
						postfixList.push_back(topToken);
						topToken = opStack.top();
						opStack.pop();
					}
			}
			else
			{
				while (!opStack.empty() && prec[opStack.top()] >= prec[token])
				{
					postfixList.push_back(opStack.top());
					opStack.pop();
				}
				opStack.push(token);
			}
				
		
		while (!opStack.empty())
		{
			postfixList.push_back(opStack.top());
			opStack.pop();
		}

		string space = " ";

		return postfixList;
	}

};
