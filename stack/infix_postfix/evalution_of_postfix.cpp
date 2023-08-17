// C++ program to evaluate value of a postfix expression
#include <bits/stdc++.h>
using namespace std;

// Follow the steps mentioned below to evaluate postfix expression using stack:

// Create a stack to store operands (or values).
// Scan the given expression from left to right and do the following for every scanned element.
// If the element is a number, push it into the stack.
// If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack.
// When the expression is ended, the number in the stack is the final answer.

// The main function that returns value
// of a given postfix expression
int evaluatePostfix(string exp)
{
	// Create a stack of capacity equal to expression size
	stack<int> st;

	// Scan all characters one by one
	for (int i = 0; i < exp.size(); ++i) {
		
		// If the scanned character is an operand
		// (number here), push it to the stack.
		if (isdigit(exp[i]))
			st.push(exp[i] - '0');

		// If the scanned character is an operator,
		// pop two elements from stack apply the operator
		else {
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			switch (exp[i]) {
			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val2 - val1);
				break;
			case '*':
				st.push(val2 * val1);
				break;
			case '/':
				st.push(val2 / val1);
				break;
			}
		}
	}
	return st.top();
}

// Driver code
int main()
{
	string exp = "231*+9-";

	// Function call
	cout << "postfix evaluation: " << evaluatePostfix(exp);
	return 0;
}
