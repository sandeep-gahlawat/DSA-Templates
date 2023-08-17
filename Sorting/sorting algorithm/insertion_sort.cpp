#include <bits/stdc++.h>
using namespace std;

// Insertion sort is a simple sorting algorithm that works
//  similar to the way you sort playing cards in your hands.
//  The array is virtually split into a sorted and an unsorted part.
//  Values from the unsorted part are picked and placed at
//   the correct position in the sorted part.
// Algorithm
// To sort an array of size n in ascending order:
// 1: Iterate from arr[1] to arr[n] over the array.
// 2: Compare the current element (key) to its predecessor.
// 3: If the key element is smaller than its predecessor,
//  compare it to the elements before. Move the greater elements
//  one position up to make space for the swapped element.

// time complexity = O(n^2) in worst case and O(n)in best case
//  space complexity = O(1)

// gernally used for small arrays

// Boundary Cases: Insertion sort takes maximum time to sort
// if elements are sorted in reverse order.
//  And it takes minimum time (Order of n) when elements are already sorted.

void insertionSort(vector<int> &arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}