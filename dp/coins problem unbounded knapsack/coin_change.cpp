#include <bits/stdc++.h>
using namespace std;
//leetcode link: https://leetcode.com/problems/coin-change/
// recusive code
class Solution
{
public:
    int count(int n, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 0;
        if (n == 0 || amount < 0)
        {
            return 99999;
        }
        if (dp[n][amount] != -1)
            return dp[n][amount];
        // we have both choices we can include or exclude
        if (coins[n - 1] <= amount)
        {
            dp[n][amount] = min(count(n - 1, coins, amount, dp), 1 + count(n, coins, amount - coins[n - 1], dp));
        }
        else // we can't include it
            dp[n][amount] = count(n - 1, coins, amount, dp);
        return dp[n][amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = count(n, coins, amount, dp);
        if (ans >= 99999)
            return -1;
        return ans;
    }
};
// using tabulation

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(amount+1, vector<int>(n + 1));
    for (int i = 0; i <= amount; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // base case 1;
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 99999;
            }
            else
            {
                // we have both choices we can include or exclude
                if (coins[j - 1] <= i)
                {
                    dp[i][j] = min(dp[i][j - 1], 1 + dp[i - coins[j - 1]][j]);
                }
                else // we can't include it
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    if (dp[amount][n] >= 99999)
        return -1;
    return dp[amount][n];
}

//more efficient in terms of space
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    if (dp[amount] == INT_MAX - 1)
        return -1;
    return dp[amount];
}