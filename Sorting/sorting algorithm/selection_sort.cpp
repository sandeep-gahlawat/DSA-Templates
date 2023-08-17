#include <bits/stdc++.h>
using namespace std;

// The selection sort algorithm sorts an array by repeatedly
// finding the minimum element (considering ascending order)
// from unsorted part and putting it at the beginning.
// The algorithm maintains two subarrays in a given array.
// 1) The subarray which is already sorted.
// 2) Remaining subarray which is unsorted.
// In every iteration of selection sort, the minimum element
//  (considering ascending order) from the unsorted subarray is picked and
//   moved to the sorted subarray.
// Following example explains the above steps:

//time complexity  = O(n^2) space complexity = O(1)

void selection_sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
}