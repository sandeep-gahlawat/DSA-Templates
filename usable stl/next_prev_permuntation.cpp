
#include <algorithm>
#include <iostream>
using namespace std;


// Syntax: 

// template 
// bool next_permutation (BidirectionalIterator first,
//                        BidirectionalIterator last);
// Parameters: 
// first, last : Bidirectional iterators to the initial
// and final positions of the sequence. The range 
// used is [first, last), which contains all the elements 
// between first and last, including the element pointed 
// by first but not the element pointed by last.

// return value: 
// true : if the function could rearrange 
// the object as a lexicographically greater permutation.
// Otherwise, the function returns false to indicate that 
// the arrangement is not greater than the previous, 
// but the lowest possible (sorted in ascending order).

// Time Complexity: O(N*N!) The next_permutation() function takes O(N) time to find the next permutation and there are N! number of permutations for an array of size N.
// Auxiliary Space: O(1) No auxiliary space is used.

//this will generate all the permunation
int main()
{
	int arr[] = { 1, 2, 3 };

	sort(arr, arr + 3);

	cout << "The 3! possible permutations with 3 elements:\n";
	do {
		cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
	} while (next_permutation(arr, arr + 3));

	cout << "After loop: " << arr[0] << ' '
		<< arr[1] << ' ' << arr[2] << '\n';

	return 0;
}


//same for prev permunation to exactly pervious to it