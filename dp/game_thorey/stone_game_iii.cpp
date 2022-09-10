#include <bits/stdc++.h>
using namespace std;

// leetode link:https://leetcode.com/problems/stone-game-iii/

// it is easier version of stone game 2
// in it m is fixed an 3;
int difference_in_points(vector<int> &stonevalues, int index, int n, vector<int> &dp)
{
    if (index >= n)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int stones = 0;
    int ans = INT_MIN;
    for (int i = index; i < min(n, (index + 3)); i++)
    {
        stones += stonevalues[i];
        ans = max(ans, stones - difference_in_points(stonevalues, i + 1, n, dp));
    }
    dp[index] = ans;
    return ans;
}
string stoneGameIII(vector<int> &stoneValue)
{
    vector<int> dp(50001, -1);
    int diff = difference_in_points(stoneValue, 0, stoneValue.size(), dp);
    if (diff == 0)
        return "Tie";
    if (diff > 0)
        return "Alice";
    return "Bob";
}

// using tabulation method
string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    vector<int> dp(n+1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int stones = 0;
        int ans = INT_MIN;
        for (int j = i; j < min(n, (i + 3)); j++)
        {
            stones += stoneValue[j];
            ans = max(ans, stones - dp[j+1]);
        }
        dp[i] = ans;
    }
    int diff = dp[0];
    if (diff == 0)
        return "Tie";
    if (diff > 0)
        return "Alice";
    return "Bob";
}
