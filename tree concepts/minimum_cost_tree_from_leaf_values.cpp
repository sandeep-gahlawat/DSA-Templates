#include <bits/stdc++.h>
using namespace std;
int max_of_given_range(vector<int>&arr,int l ,int r)
{
    int maxi =  INT_MIN;
    for(int i = l;i<=r;i++)
    {
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
//using memoization
int minimum_cost_tree(vector<int>&arr,int l,int r,vector<vector<int>>&dp)
{
    if(l==r)return 0;
    if(l+1==r)return arr[l]*arr[r];
    if(dp[l][r]!=-1)return dp[l][r];
    int res = INT_MAX;
    for(int i = l;i<r;i++)
    {
        res = min(res ,minimum_cost_tree(arr,l,i,dp)+minimum_cost_tree(arr,i+1,r,dp) + max_of_given_range(arr,l,i)*max_of_given_range(arr,i+1,r));
    }
    dp[l][r] = res;
    return res;
}
// using tabulation
int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
    for(int gap = 0;gap<n;gap++)
    {
        for(int i = 0,j = gap;j<n;i++,j++)
        {
            if(i==j)dp[i][j] = 0;
            if(i+1 == j)
            dp[i][j] = arr[i]*arr[j];
            
            for(int k = i;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+max_of_given_range(arr,i,k)*max_of_given_range(arr,k+1,j));
            }
        }
    }
    
    return dp[0][n-1];
}