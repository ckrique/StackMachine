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
		int x = fullPop(&javaStack);
		int y = fullPop(&javaStack);		
		javaStack.push(x * y);
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

	void printStackItens() {
		stack<int> printStack;
		string vectoItens = "{";
		int javaStackSize = javaStack.size();
				
		for (int i = 0; i < javaStackSize; i++)
		{
			int item = fullPop(&javaStack);
			printStack.push(item);
			vectoItens = vectoItens + " " + to_string(item);
		}

		for (int i = 0; i < javaStackSize; i++)
		{
			javaStack.push(printStack.top());
			printStack.pop();

		}

		vectoItens = vectoItens + " }";
		cout << vectoItens << endl;
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

	/*			   
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

		vector<string> tokenList = split(infixExpr, ' ');

		string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string numbers = "0123456789";

		for (string token : tokenList)
			if (letters.find(token) != string::npos || numbers.find(token) != string::npos)
				postfixList.push_back(token);
			else if (token == "(")
				opStack.push(token);
			else if (token == ")")
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
	}*/

















	// Function to return precedence of operators
	int prec(char c)
	{
		if (c == '^')
			return 3;
		else if (c == '/' || c == '*')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else
			return -1;
	}

	// The main function to convert infix expression
	// to postfix expression
	vector<string> infixToPostfix(string s)
	{

		stack<char> st; // For stack operations, we are using
						// C++ built in stack
		string result;

		for (int i = 0; i < s.length(); i++) {
			char c = s[i];

			// If the scanned character is
			// an operand, add it to output string.
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
				|| (c >= '0' && c <= '9'))
				result += c;

			// If the scanned character is an
			// ‘(‘, push it to the stack.
			else if (c == '(')
				st.push('(');

			// If the scanned character is an ‘)’,
			// pop and to output string from the stack
			// until an ‘(‘ is encountered.
			else if (c == ')') {
				while (st.top() != '(') {
					result += st.top();
					st.pop();
				}
				st.pop();
			}

			// If an operator is scanned
			else {
				while (!st.empty()
					&& prec(s[i]) <= prec(st.top())) {
					if (c == '^' && st.top() == '^')
						break;
					else {
						result += st.top();
						st.pop();
					}
				}
				st.push(c);
			}
		}

		// Pop all the remaining elements from the stack
		while (!st.empty()) {
			result += st.top();
			st.pop();
		}


		vector<string> postfixList;
		int N = result.length();
		string strAuxiliar;
		strAuxiliar = "";

		for (int i = 0; i < N; i++) 
		{
			if (result[i] == '+' || result[i] == '-' || result[i] == '*' || result[i] == '/')
			{
				postfixList.push_back(strAuxiliar);
				strAuxiliar = "";
				string signal;
				signal += result[i];
				postfixList.push_back(signal);
			}
			else
			{
				strAuxiliar += result[i];
			}
		}
		postfixList.push_back(strAuxiliar);
		return postfixList;
		
	}







};
