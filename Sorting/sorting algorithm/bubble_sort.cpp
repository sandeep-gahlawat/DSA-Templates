#include <bits/stdc++.h>
using namespace std;

// Bubble Sort is the simplest sorting algorithm that works by repeatedly
//  swapping the adjacent elements if they are in wrong order.


//time complexity = O(n^2) space complexity = O(1)
//->it puts every max element at the end in each step
//->opposite of selection sort



void bubblesort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// optimized bubble sort
void bubblesort_optimized(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int  swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
