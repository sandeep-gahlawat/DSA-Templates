// Syntax:
//simply add one more thing that is greater<int> in syntax of map
// map<key_datatype, value_datatype, greater<int> > mapName;

//e.g code
// C++ program makes a map to store
// elements in descending order
#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
	
	map<int, string, greater<int> > mymap;

	// Inserting the elements one by one
	mymap.insert(make_pair(10, "queen"));
	mymap.insert(make_pair(20, "rose"));
	mymap.insert(make_pair(5, " lion"));

	// begin() returns to the first value of map
	map<int, string>::iterator it;
	for (it = mymap.begin(); it != mymap.end(); it++)
		cout << "(" << (*it).first << ", " << (*it).second
			<< ")" << endl;

	return 0;
}
