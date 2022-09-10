#include <bits/stdc++.h>
using namespace std;
// using memoization
// leetcode link :https://leetcode.com/problems/stone-game-iv/
bool winner(int n, vector<vector<int>> &dp, int player)
{
    if (n == 0)
    {
        // if turn of player 1(player 1 is alice)
        if (player == 1)
            return false;
        else
            return true;
    }
    if (dp[n][player] != -1)
    {
        return dp[n][player];
    }
    bool val;
    if (player == 1)
    {
        val = false;
        for (int i = 1; i * i <= n; i++)
        {
            val |= winner(n - (i * i), dp, 0);
        }
    }
    else
    {
        val = true;
        for (int i = 1; i * i <= n; i++)
        {
            val &= winner(n - (i * i), dp, 1);
        }
    }
    dp[n][player] = val;
    // below if else can be removed from this line  dp[n][!player] = !val;
    if (player == 1)
    {
        if (val == true)
            dp[n][0] = false;
        else
            dp[n][0] = true;
    }
    else
    {
        if (val == true)
            dp[n][1] = false;
        else
            dp[n][1] = true;
    }
    // cout<<n<<" "<<player<<" "<<dp[n][player]<<endl;
    return val;
}
bool winnerSquareGame(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return winner(n, dp, 1);
}

// using tabulation method
bool winnerSquareGame(int n)
{
    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k * k <= i; ++k)
        {
            if (!dp[i - k * k])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}