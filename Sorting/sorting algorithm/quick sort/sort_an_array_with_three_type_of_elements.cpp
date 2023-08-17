#include<bits/stdc++.h>
using namespace std;

//problems like
// 1-> sort an array of 0's 1's 2's
// 2=> three way partitioning
//  e.g input = [2,1,2,20,10,20,1] pivot = 2;
//     output = [1,1,2,2,20,10,20]
// 3=> parttion around a range
//   e.g input = [10,5,6,3,20,9,40] range = [5,10]
//       output = [3,5,6,9,10,20,40]

//dutch national flag algo

void sort(vector<int>&arr,int n)
{
    int low = 0,high = n-1,mid = 0;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;mid++;

        }
        else if(arr[mid]==1)
        mid++;
        else
        {
            swap(arr[mid],arr[high]);
            high--; 
        }
    }
}