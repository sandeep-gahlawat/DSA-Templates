// C++ program to convert infix to prefix
#include <bits/stdc++.h>
using namespace std;

// To convert an infix expression to a prefix expression, we can use the stack data structure. The idea is as follows:

// Step 1: Reverse the infix expression. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
// Step 2: Convert the reversed infix expression to “nearly” postfix expression.
// While converting to postfix expression, instead of using pop operation to pop operators with greater than or equal precedence, here we will only pop the operators from stack that have greater precedence.
// Step 3: Reverse the postfix expression.
// The stack is used to convert infix expression to postfix form.

// Function to check if the character is an operator
bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

// Function to get the priority of operators
int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}

// Function to convert the infix expression to postfix
string infixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	int l = infix.size();
	stack<char> char_stack;
	string output;

	for (int i = 0; i < l; i++) {

		// If the scanned character is an
		// operand, add it to output.
		if (isalpha(infix[i]) || isdigit(infix[i]))
			output += infix[i];

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (infix[i] == '(')
			char_stack.push('(');

		// If the scanned character is an
		// ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (infix[i] == ')') {
			while (char_stack.top() != '(') {
				output += char_stack.top();
				char_stack.pop();
			}

			// Remove '(' from the stack
			char_stack.pop();
		}

		// Operator found
		else {
			if (isOperator(char_stack.top())) {
				if (infix[i] == '^') {
					while (
						getPriority(infix[i])
						<= getPriority(char_stack.top())) {
						output += char_stack.top();
						char_stack.pop();
					}
				}
				else {
					while (
						getPriority(infix[i])
						< getPriority(char_stack.top())) {
						output += char_stack.top();
						char_stack.pop();
					}
				}

				// Push current Operator on stack
				char_stack.push(infix[i]);
			}
		}
	}
	while (!char_stack.empty()) {
		output += char_stack.top();
		char_stack.pop();
	}
	return output;
}

// Function to convert infix to prefix notation
string infixToPrefix(string infix)
{
	// Reverse String and replace ( with ) and vice versa
	// Get Postfix
	// Reverse Postfix
	int l = infix.size();

	// Reverse infix
	reverse(infix.begin(), infix.end());

	// Replace ( with ) and vice versa
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
		}
	}

	string prefix = infixToPostfix(infix);

	// Reverse postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

// Driver code
int main()
{
	string s = ("x+y*z/w+u");

	// Function call
	cout << infixToPrefix(s) << std::endl;
	return 0;
}
