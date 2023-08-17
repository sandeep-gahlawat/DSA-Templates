// C++ program to implement a stack that supports
// getMinimum() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

// A user defined stack that supports getMin() in
// addition to push() and pop()

// We define a variable minEle that stores the current minimum element in the stack. Now the interesting part is, how to handle the case when the minimum element is removed. To handle this, we push “2x – minEle” into the stack instead of x so that the previous minimum element can be retrieved using the current minEle and its value stored in the stack
struct MyStack {
	stack<int> s;
	int minEle;

	// Prints minimum element of MyStack
	void getMin()
	{
		if (s.empty())
			cout << "Stack is empty\n";

		// variable minEle stores the minimum element
		// in the stack.
		else
			cout << "Minimum Element in the stack is: "
				<< minEle << "\n";
	}

	// Prints top element of MyStack
	void peek()
	{
		if (s.empty()) {
			cout << "Stack is empty ";
			return;
		}

		int t = s.top(); // Top element.

		cout << "Top Most Element is: ";

		// If t < minEle means minEle stores
		// value of t.
		(t < minEle) ? cout << minEle : cout << t;
	}

	// Remove the top element from MyStack
	void pop()
	{
		if (s.empty()) {
			cout << "Stack is empty\n";
			return;
		}

		cout << "Top Most Element Removed: ";
		int t = s.top();
		s.pop();

		// Minimum will change as the minimum element
		// of the stack is being removed.
		if (t < minEle) {
			cout << minEle << "\n";
			minEle = 2 * minEle - t;
		}

		else
			cout << t << "\n";
	}

	// Removes top element from MyStack
	void push(int x)
	{
		// Insert new number into the stack
		if (s.empty()) {
			minEle = x;
			s.push(x);
			cout << "Number Inserted: " << x << "\n";
			return;
		}

		// If new number is less than minEle
		else if (x < minEle) {
			s.push(2 * x - minEle);
			minEle = x;
		}

		else
			s.push(x);

		cout << "Number Inserted: " << x << "\n";
	}
};

// Driver Code
int main()
{
	MyStack s;
	
	// Function calls
	s.push(3);
	s.push(5);
	s.getMin();
	s.push(2);
	s.push(1);
	s.getMin();
	s.pop();
	s.getMin();
	s.pop();
	s.peek();

	return 0;
}
