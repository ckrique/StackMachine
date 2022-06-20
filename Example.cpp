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
		
		vector<string> tokensPostfix = infixToPostfix("( A + B ) * C - ( D - E ) * ( F + G )"/*"1 * 2 + 3 * 4"*/);


		push(1);
		push(2);
		add();
		push(3);
		push(5);
		push(4);
		div();
		sub();
		mul();
		
		
		/*push(0);
		push(a);

		while (true) {
			push(b);
			sub();
			swap();
			push(1);
			add();
			swap();
			dup();
			push(b);
			sub();
			if (jgz()) {
				continue;
			}
			drop();
			push(3);
			add();
			break;
		}*/

		print();
		//}


	}
};

int main()
{
	Example example;
	example.run();
}