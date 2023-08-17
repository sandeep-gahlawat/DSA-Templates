#include <iostream>
#include <cmath>
using namespace std;
//prints all subset possible
// Set  = [a,b,c]
// power_set_size = pow(2, 3) = 8
// Run for binary counter = 000 to 111

// Value of Counter            Subset
//    000                    -> Empty set
//    001                    -> a
//    010                    -> b
//    011                    -> ab
//    100                    -> c
//    101                    -> ac
//    110                    -> bc
//    111                    -> abc
void printPowerSet(string str)
{
	int n = str.length();

	int powSize = pow(2, n);

	for(int counter = 0; counter < powSize; counter++)
	{
		for(int j = 0; j < n; j++)
		{
			if((counter & (1 << j)) != 0)
                cout<<str[j];
		}
		
		cout<<endl;
	}
}
    

    
int main() {
	
	string s = "abc";

    printPowerSet(s);  
    
}