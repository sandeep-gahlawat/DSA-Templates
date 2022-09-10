#include <bits/stdc++.h>
using namespace std;
// leetcode link : https://leetcode.com/contest/weekly-contest-289/problems/longest-path-with-different-adjacent-characters/
class Solution
{
public:
    int dfs(int src, vector<vector<int>> &adj, string &s, int &res)
    {
        // we can consider only two paths from a given node
        int big1 = 0, big2 = 0;
        for (auto &x : adj[src])
        {
            int curr = dfs(x, adj, s, res);
            if (s[src] == s[x])
                continue;
            if (curr > big2)
                big2 = curr;
            if (big2 > big1)
                swap(big1, big2);
        }
        // considereing every node in the ans
        res = max(res, big1 + big2 + 1);
        // return the maximum path from that node
        return big1 + 1;
    }
    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++)
        {

            adj[parent[i]].push_back(i);
        }
        int res = 0;
        dfs(0, adj, s, res);
        return res;
    }
};