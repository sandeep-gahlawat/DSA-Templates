#include<bits/stdc++.h>
using namespace std;

//question => we have to find the sum closest to the target sum

//approach=>by any how if we are able to find sum x is possible or not =>this is already solved using subset sum possible or not


//dp[i][j] =>stores sum j is possible or not using i elements
void issubsetsum(vector<int> &arr, int n, int sum, vector<vector<bool>> &dp)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {

                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
}

//now we know which sum is possible and which is not
//so we can simply interate over all the sums and take that one that is closest to the target

//tc = O(n*(sum of array element));
int closest_sum(vector<int>&arr,int target)
{
    int n = arr.size();
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum+=arr[i];
    }
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    issubsetsum(arr,n,target,dp);
    int clos_sum ;
    int diff = INT_MAX;
    for(int i = 0;i<=sum;i++)
    {
       if(dp[n][i]==true)
       {
           //means i sum is possible
           if(abs(target-i)<diff)
           {
               diff = abs(target-i);
               clos_sum = i;
           }
           
       }
    }
    return clos_sum ;
}
