#include<bits/stdc++.h>
using namespace std;

// recursive approach
// tc (2^n)
int max_profit(int n,int w,vector<int>&wt,vector<int>&val)
{
    if(n==0 || w==0)return 0;
    //if item weight is greater then weight required then we exclude it
    if(wt[n-1]>w)
    return max_profit(n-1,w,wt,val);

    // else we can include it or exclude it we take maximum from both the cases
    else
    return max(max_profit(n-1,w,wt,val),val[n-1]+max_profit(n-1,w-val[n-1],wt,val));
}

//dp approach
// dp[i][j] reperents maximum profit till we have peocessed i items having weight 
// capacity j
int max_profit_dp(int w,vector<int>wt,vector<int>val)
{
    int n = wt.size();
    int dp[n+1][w+1];
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=w;j++)
        {
            //if no item is included then profit is zero and if capacity is zero
            // then also profit is zero
           if(i==0 || j==0)
           dp[i][j] = 0;

           // if weight of item is greater then capacity then we can not include that item
           else if(wt[j-1]>j)
           dp[i][j] = dp[i-1][j];
           else
           dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][w];
}