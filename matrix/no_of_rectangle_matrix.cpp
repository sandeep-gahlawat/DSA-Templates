#include <bits/stdc++.h>
using namespace std;
// leetcode link :https://leetcode.com/problems/count-submatrices-with-all-ones/
int numSubmat(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    // precompute the sum from right side for all the rows of matrix
    // e.g [1,1,0,1,1,1,1,0,1,1] =>precomput=>[2,1,0,4,3,2,1,0,2,1]

    vector<vector<int>> suffix_sum(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = m - 1; j >= 0; j--)
        {

            if (mat[i][j] == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            suffix_sum[i][j] = cnt;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // fix this point and calculate the number of rectangle including
            // this point
            int x = INT_MAX;
            for (int k = i; k < n; k++)
            {
                x = min(x, suffix_sum[k][j]);
                res += x;
            }
        }
    }
    return res;
}