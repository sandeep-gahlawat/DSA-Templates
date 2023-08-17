#include<bits/stdc++.h>
using namespace std;
//approach
// first find out triplets having sum<=R 
// then find out triplets having sum<=(L-1)
// then sum(R)- sum(L-1) is our final answer
int two_sum(int arr[],int low,int high,int target)
{
    int count = 0;
    while(low<high)
    {
        if(arr[low]+ arr[high]>target)
        {
            high--;
        }
        else
        {
            count+= (high-low);
            low++;
        }
    }
    return count;
}
int countTriplets(int arr[], int n, int L, int R) {
       sort(arr,arr+n);
       int count = 0;
       for(int i = 0;i<n;i++)
       {
          count += two_sum(arr,i+1,n-1,R-arr[i]) - two_sum(arr,i+1,n-1,L-1-arr[i]);
       } 
       return count;
    }