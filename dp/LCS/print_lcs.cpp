#include <bits/stdc++.h>
using namespace std;

string lcs(string &A, string &B)
{
    int n = A.size(), m = B.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {

            if (A[i] == B[j])
                dp[i + 1][j + 1] = dp[i][j] + A[i];
            else
            
            {
                //take the big string 
                dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ? dp[i + 1][j] : dp[i][j + 1];
            }
        }
    }

    return dp[n][m];
}