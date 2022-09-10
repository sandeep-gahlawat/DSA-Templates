#include <bits/stdc++.h>
using namespace std;
// bool flag = false;
bool check(int i, int j, int rows, int cols, vector<vector<char>> &board, string &word, int index)
{
    if (i < 0 || j < 0 || i >= rows || j >= cols || word[index] != board[i][j])
        return false;
    if (index == word.length() - 1)
    {
        return true;
    }
    char temp = board[i][j];
    board[i][j] = '0';
    if (check(i + 1, j, rows, cols, board, word, index + 1))
        return true;
    if (check(i, j + 1, rows, cols, board, word, index + 1))
        return true;
    if (check(i - 1, j, rows, cols, board, word, index + 1))
        return true;
    if (check(i, j - 1, rows, cols, board, word, index + 1))
        return true;
    board[i][j] = temp;
    return false;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    vector<string>res;
    int n = board.size(), m = board[0].size();
    for (auto &x : words)
    {
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == x[0])
                {
                    // call checking function
                    if (check(i, j, n, m, board, x, 0))
                    {
                       res.push_back(x);
                       flag = true;
                       break;
                    }
                        
                }
            }
            if(flag)break;
        }
    }
    return res;
}