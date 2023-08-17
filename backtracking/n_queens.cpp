#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool isPossible(vector<string> &board, int n, int row, int col)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     if (board[row][i] == 'Q')
        //     {
        //         return false;
        //     }
        // }
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        int i = row;
        int j = col;
        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }
       
       
        i = row;
        j = col;
        while (i >= 0 && j < n)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void solve(vector<string> &board, int n, int row, vector<vector<string>> &ans)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isPossible(board, n, row, i))
            {
                board[row][i] = 'Q';
                solve(board, n, row + 1, ans);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(board, n, 0, ans);
        return ans;
    }
   
};