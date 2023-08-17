#include <bits/stdc++.h>
using namespace std;

//gfg article link : https://www.geeksforgeeks.org/vertex-cover-problem-dynamic-programming-solution-for-tree/

// Given N nodes of a tree and a list of edges. Find the minimum number of nodes to be selected to light up all the edges of the tree.
// An edge lights up when at least one node at the end of the edge is selected.

class Solution
{
public:
    int dfs(int src, vector<vector<int>> &adj, bool flag, vector<bool> &visited, vector<vector<int>> &dp)
    {
        if (dp[src][flag] != -1)
        {

            return dp[src][flag];
        }
        visited[src] = true;
        if (flag == false)
        {
            // necessary to include because their root is not included
            int include = 1;
            visited[src] = true;
            for (auto &x : adj[src])
            {
                if (visited[x] == false)
                    include += dfs(x, adj, true, visited, dp);
            }
            visited[src] = false;

            return dp[src][flag] = include;
        }
        else
        {
            // include
            int include = 1;
            visited[src] = true;
            for (auto &x : adj[src])
            {
                if (visited[x] == false)
                {
                    visited[x] = true;
                    include += dfs(x, adj, true, visited, dp);
                    visited[x] = false;
                }
            }
            visited[src] = false;
            int not_include = 0;
            visited[src] = true;
            for (auto &x : adj[src])
            {
                if (visited[x] == false)
                {
                    visited[x] = true;
                    not_include += dfs(x, adj, false, visited, dp);
                    visited[x] = false;
                }
            }
            visited[src] = false;

            return dp[src][flag] = min(include, not_include);
        }
    }
    int countVertex(int N, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(N + 1);
        vector<bool> visited(N + 1, false);
        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<vector<int>> dp(N + 2, vector<int>(2, -1));
        return dfs(1, adj, true, visited, dp);
    }
};