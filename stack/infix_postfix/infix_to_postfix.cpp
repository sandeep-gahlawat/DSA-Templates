// C++ code to convert infix expression to postfix

#include <bits/stdc++.h>
using namespace std;


// Why postfix representation of the expression? 
// The compiler scans the expression either from left to right or from right to left. 
// Consider the expression: a + b * c + d

// The compiler first scans the expression to evaluate the expression b * c, then again scans the expression to add a to it. 
// The result is then added to d after another scan. 
// The repeated scanning makes it very inefficient. Infix expressions are easily readable and solvable by humans whereas the computer cannot differentiate the operators and parenthesis easily so, it is better to convert the expression to postfix(or prefix) form before evaluation.




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
void infixToPostfix(string s)
{

	stack<char> st;
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
		// pop and add to output string from the stack
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
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

// Driver code
int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";

	// Function call
	infixToPostfix(exp);
	
	return 0;
}
