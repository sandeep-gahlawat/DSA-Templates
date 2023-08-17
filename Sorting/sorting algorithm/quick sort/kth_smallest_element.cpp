#include<bits/stdc++.h>
using namespace std;

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
//assuming no repeation of element
// tc = O(n2)in worst case O(n) in average 
// we can solve this in nlogn time using sorting
int kthsmallest(vector<int>&arr,int n,int k)
{
    int l = 0,r = n-1;
    while(l<=r)
    {
        int p = lomuto(arr,l,r);
        if(p == k-1)return p;
        else if(p>k-1)
        r = p-1;
        else
        l = p+1;
    }
    return -1;
}