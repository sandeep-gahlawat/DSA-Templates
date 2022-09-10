#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left, *right;
};

class Solution {
public:
    int maxProfit(int m, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        int ans  = 0;
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0;j<=m;j++)
            {
                if(i==0 || j==0 || i==1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    int maxi = 0;
                    for(int k = i-1;k>=1;k--)
                    {
                        maxi = max(maxi,(prices[i-1]-prices[k-1])+dp[k-1][j-1]);
                    }
                    dp[i][j] = maxi;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
