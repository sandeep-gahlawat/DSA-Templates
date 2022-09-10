#include<bits/stdc++.h>
using namespace std;
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