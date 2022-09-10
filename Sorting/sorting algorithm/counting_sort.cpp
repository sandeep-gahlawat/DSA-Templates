#include <bits/stdc++.h>
using namespace std;




// naive approach 
//this is valid for simple arrays like integer array,char array. but not valid for object arrays
void countsort(vector<int> &arr, int n, int k)
{
    vector<int> counts(k, 0);
    for (int i = 0; i < n; i++)
    {
        counts[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < counts[i]; j++)
        {
            arr[index] = i;
            index++;
        }
    }
}
// optimized approach
// Counting sort is a linear time sorting algorithm that sort in O(n+k) time 
// when elements are in the range from 1 to k.

// What if the elements are in the range from 1 to n2? 
// We can’t use counting sort because counting sort will take O(n2)
//  which is worse than comparison-based sorting algorithms. 
// Can we sort such an array in linear time? 
//  tc = O(n+k) SC = O(n+k)
//  it is a stable algorithm(order between equal element will be same )
//  it is not a comparison based algorithm
// used as a subroutine in radix sort
void countsort_optimized(vector<int> &arr, int n, int k)
{
    vector<int> counts(k, 0);
    for (int i = 0; i < n; i++)
    {
        counts[arr[i]]++;
    }
    // count[i] represents number of elements that are less than or equal to i;
    for (int i = 1; i < k; i++)
    {
        counts[i] = counts[i - 1] + counts[i];
    }
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--)
    {
        //count[i] denotes number of element that are less then equal to i;
        // let say count[i] is equal to 5 so arr[i] should be at position count[i]-1 at 4 .because array indexing start from 0.
        output[counts[arr[i]] - 1] = arr[i];
        //reduce the count by one
        counts[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
