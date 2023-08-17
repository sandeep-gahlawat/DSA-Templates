#include<bits/stdc++.h>
using namespace std;

//time compxity = O(n) space complexity = O(1)

// It fixes the pivot element in the correct position.
// this is slightly slower than horse partition

int lomuto(vector<int>&arr,int l,int h)
{
    int pivot = arr[h];//always last element of the array
    int i = l-1;
    for(int j = l;j<=h-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

//how to handle the cases when pivot is not the last element
//  =>then we take the element to last position
//   swap(arr[p],arr[h]) =>now we can use it