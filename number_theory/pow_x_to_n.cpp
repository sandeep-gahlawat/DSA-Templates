#include<bits/stdc++.h>
using namespace std;

/* Function to calculate x raised to the power y in
 * O(logn)*/
int power(int x, unsigned int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)//if y is odd
        return temp * temp;
    else
        return x * temp * temp;
}
 

 //inbuild
//  We can use inbuilt power function pow(x, n) to calculate xn

long long M;
long long int pow(long long int x, long long int n){

	long long int res = 1;
	while(n>0){

		if(n&1) res = (res*x)%M;
		n = n>>1;
		x=(x*x)%M;

	}
	return res;

}