#include <bits/stdc++.h>
using namespace std;

// simple recusrcive code approach pick or not pick
// this question is similar to subset sum
int no_of_subsets(int n, int sum, vector<int> &arr)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    int not_pike = 0;
    not_pike = no_of_subsets(n - 1, sum, arr);
    int pike = 0;
    if (arr[n - 1] <= sum)
    {
        pike = no_of_subsets(n - 1, sum - arr[n - 1], arr);
    }
    return pike + not_pike;
}

// using memoization

int no_of_subsets(int n, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];

    int not_pike = 0;
    not_pike = no_of_subsets(n - 1, sum, arr, dp);
    int pike = 0;
    if (arr[n - 1] <= sum)
    {
        pike = no_of_subsets(n - 1, sum - arr[n - 1], arr, dp);
    }
    dp[n][sum] = pike + not_pike;
    return pike + not_pike;
}

// using tabulation

int no_of_subsets(int sum, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
            {
                int not_pick = dp[i - 1][j];

                int pick = 0;
                if (arr[i - 1] <= j)
                    pick = dp[i - 1][j - arr[i - 1]];

                dp[i][j] = pick + not_pick;
            }
        }
    }
    return dp[n][sum];
}
