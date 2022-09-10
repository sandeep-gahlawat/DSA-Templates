#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left, *right;
    int val;
};
void dfs(int src,vector<vector<int>>&adj,vector<bool>&visited)
{
    visited[src] = true;
    for(auto x:adj[src])
    {
        if(visited[x]==false)
        {
            dfs(x,adj,visited);
        }
    }
}