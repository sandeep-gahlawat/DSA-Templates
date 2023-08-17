#include <bits/stdc++.h>
using namespace std;
// leetcode link:https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// maximal square can also be solved using this approach only
// leetcode link:https://leetcode.com/problems/maximal-square/
// approach
// finding count of submatrices that are ending at (i,j);
int countSquares(vector<vector<int>> &matrix)
{
    int n =matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            //can make square of only size 1
            if(i==0||j==0)
            {
                dp[i][j] = matrix[i][j];
            }
            else
            {
                // if it is one than only it can became part of it
                if(matrix[i][j]==1)
                {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
            count+=dp[i][j];
        }
    }
    return count;
}