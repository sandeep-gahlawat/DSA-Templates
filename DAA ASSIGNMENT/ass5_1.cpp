#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3, 4,5};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n));
    //dp[i][j] = >minimum number of multiplication to multiply matrices from i to j
    //mutplication required to multiply with matrix itself is zero
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 1; i < n - gap + 1; i++)
        {
            int j = i + gap - 1;
            dp[i][j] = INT_MAX;
            //general formula = dp[i][j] = i<=k<j min{dp[i,k]+dp[k,j]+arr[i-1]*arr[k]*arr[j]}
            for (int k = i; k <= j - 1; k++)
            {
               dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }

    cout << "minimum number of multiplications is : " << dp[1][n - 1] << endl;

    return 0;
}
