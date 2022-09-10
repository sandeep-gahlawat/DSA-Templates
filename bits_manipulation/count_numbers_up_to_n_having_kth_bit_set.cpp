// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count
// of number of 1's at ith bit
// in a range [1, n - 1]
long long getcount(long long n, int k)
{
	// Store count till nearest
	// power of 2 less than N
	long long res = (n >> (k + 1)) << k;

	// If K-th bit is set in N
	if ((n >> k) & 1)

		// Add to result the nearest
		// power of 2 less than N
		res += n & ((1ll << k) - 1);

	// Return result
	return res;
}

// Driver Code
int main()
{

	long long int N = 14;
	int K = 2;

	// Function Call
    // bits index start from zero
	cout << getcount(N + 1, K) << endl;

	return 0;
}
