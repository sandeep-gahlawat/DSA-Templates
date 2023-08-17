#include <bits/stdc++.h>
using namespace std;

// Given a set of non-negative integers, and a value sum, determine
// if there is a subset of the given set with sum equal to given sum.

// this problem is quite similar to 0/1knapsack
// either we include the number either we exclude it;
bool isSubsetSum(int arr[], int n, int sum)
{

    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);

    /* else, check if sum can be obtained by any
of the following:
      (a) including the last element
      (b) excluding the last element   */
    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// dp aproach
bool issubsetsum(vector<int> &arr, int sum)
{
    int n = arr.size();
    bool dp[n + 1][sum + 1];
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
    return dp[n][sum];
}

// using this we can also divide array into sets of minimal difference
// by using the code of by checking set with sum k is possible or not
// we we will pass k as the sum of array
// and we got to know that which sum is possible and whioch is not
// this is it we required

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

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    issubsetsum(arr, n, sum, dp);
    int ans = INT_MAX;
    for (int i = 0; i <= sum; i++)
    {

        if (dp[n][i] == true)
        {
            ans = min(ans, abs(sum - 2 * i));
        }
    }
    return ans;
}
