#include <bits/stdc++.h>
using namespace std;
int points(int start,int end,vector<int>&stonevalue,vector<int>&prefix, vector<vector<int>>&dp)
{
    if(start>=end)return 0;
    int ans = 0;
    if(dp[start][end]!=-1)
    return dp[start][end];
    for(int i = start;i<end;i++)
    {
        int leftsum = 0;
        leftsum+= prefix[i];
        if(start>0)
        leftsum-=prefix[start-1];
        int rightsum = 0;
        rightsum+=prefix[end]-prefix[i];
        if(leftsum>rightsum)
        {
            ans = max(ans,rightsum + points(i+1,end,stonevalue,prefix,dp));
        }
        else if(rightsum>leftsum)
        {
            ans = max(ans,leftsum + points(start,i,stonevalue,prefix,dp));
        }
        else
        {
            ans = max(ans,max(rightsum + points(i+1,end,stonevalue,prefix,dp),leftsum + points(start,i,stonevalue,prefix,dp)));
        }
    }
    dp[start][end] = ans;
    return ans;
}
int stoneGameV(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    vector<int>prefix(n);
    prefix[0] = stoneValue[0];
    for(int i = 1;i<n;i++)
    prefix[i] = prefix[i-1]+stoneValue[i];
    return points(0,stoneValue.size()-1,stoneValue,prefix,dp);
}