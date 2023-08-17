#include <bits/stdc++.h>
using namespace std;



//leetcode link:https://leetcode.com/problems/word-search-ii/
struct TrieNode
{
    TrieNode *child[26];
    string isend;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isend = "";
    }
    void addNode(string &key)
    {
        TrieNode *curr = this;
        for (int i = 0; i < key.length(); i++)
        {
            int ind = key[i] - 'a';

            if (curr->child[ind] == NULL)
            {
                curr->child[ind] = new TrieNode();
            }
            curr = curr->child[ind];
        }

        curr->isend = key;
    }
};
class Solution
{
public:
    vector<string> ans;
    void dfs(int i, int j, int n, int m, vector<vector<char>> &board, TrieNode *curr)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '0')
        {
            return;
        }
        int ind = board[i][j] - 'a';
        if (curr->child[ind] == NULL)
        {
            return;
        }
        curr = curr->child[ind];
        
        if (curr->isend.length() > 0)
        {
            ans.push_back(curr->isend);
            //to romove duplicates in ans
            curr->isend = "";
        }
        char temp = board[i][j];
        board[i][j] = '0';
        dfs(i + 1, j, n, m, board, curr);
        dfs(i, j + 1, n, m, board, curr);
        dfs(i - 1, j, n, m, board, curr);
        dfs(i, j - 1, n, m, board, curr);
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int n = board.size();
        int m = board[0].size();
        TrieNode *root = new TrieNode();
        // add all the strings into trie
        for (auto &x : words)
        {
            root->addNode(x);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(i, j, n, m, board, root);
            }
        }
        return ans;
    }
};