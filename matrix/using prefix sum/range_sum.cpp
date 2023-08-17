#include <bits/stdc++.h>
using namespace std;
//leetcode link : https://leetcode.com/problems/range-sum-query-2d-immutable/
class NumMatrix
{
public:
    vector<vector<int>> mat;
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        mat = matrix;
        prefix = mat;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (j == 0 && i > 0)
                {
                    prefix[i][j] = prefix[i][j] + prefix[i - 1][j];
                }
                else if (i == 0 && j > 0)
                {
                    prefix[i][j] = prefix[i][j] + prefix[i][j - 1];
                }
                else if (i != 0 && j != 0)
                {
                    prefix[i][j] = prefix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        long long sum = 0;
        sum += (prefix[row2][col2] - prefix[row1][col1]) + mat[row1][col1];
        if (col1 - 1 >= 0)
            sum -= prefix[row2][col1 - 1] - prefix[row1][col1 - 1];
        if (row1 - 1 >= 0)
            sum -= prefix[row1 - 1][col2] - prefix[row1 - 1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */