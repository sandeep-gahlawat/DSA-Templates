#include<bits/stdc++.h>
using namespace std;
// It doesn’t fix the pivot element in the correct position.
int hoarse(vector<int>&arr,int l,int h)
{
    int pivot = arr[l];
    int i = l-1,j = h+1;
    while(1)
    {
        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j)return j;
        swap(arr[j],arr[i]);
    }
    return 0;
}