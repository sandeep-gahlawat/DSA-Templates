#include <bits/stdc++.h>
using namespace std;

//leetcode link:https://leetcode.com/problems/distinct-subsequences/

// recursive approach
//approach is very simple either we take a chracter or either we will not take that character
int subseq_rec(int i, int j, string s, string t, int n, int m)
{
    if (j == m && i <= n)
    {
        return 1;
    }
    if (i >= n)
    {
        return 0;
    }

    int take = 0;
    if (s[i] == t[j])
    {
        take = subseq_rec(i + 1, j + 1, s, t, n, m);
    }

    int nottake = subseq_rec(i + 1, j, s, t, n, m);

    return take + nottake;
}
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    return subseq_rec(0, 0, s, t, n, m);
}

// memoization approach
int subseq(int i, int j, string s, string t, int n, int m, vector<vector<int>> &dp)
{
    if (j == m && i <= n)
    {
        return 1;
    }
    if (i >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int take = 0;
    if (s[i] == t[j])
    {
        take = subseq(i + 1, j + 1, s, t, n, m, dp);
    }

    int nottake = subseq(i + 1, j, s, t, n, m, dp);
    dp[i][j] = take + nottake;
    return take + nottake;
}
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return subseq(0, 0, s, t, n, m, dp);
}

// tabulation approach
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1));
    //base case 1
    for (int i = 0; i <= n; i++)
    {
        dp[i][m] = 1;
    }
    //base case 2
    for (int j = 0; j < m; j++)
    {
        dp[n][j] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            unsigned int take = 0;
            if (s[i] == t[j])
            {
                take = dp[i + 1][j + 1];
            }

            unsigned int nottake = dp[i + 1][j];
            dp[i][j] = take + nottake;
        }
    }
    return dp[0][0];
}