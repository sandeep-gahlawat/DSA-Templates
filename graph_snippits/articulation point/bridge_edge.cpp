#include <bits/stdc++.h>
using namespace std;

// Given a Graph of V vertices and E edges and another edge(c - d),
//  the task is to find if the given edge is a Bridge.
//  i.e., removing the edge disconnects the graph.

void dfs(int src, vector<int> adj[], vector<bool> &visited)
{
    visited[src] = true;
    for (auto x : adj[src])
    {
        if (visited[x] == false)
        {
            dfs(x, adj, visited);
        }
    }
}
int isBridge(int V, vector<int> adj[], int c, int d)
{
    // already disconnected
    vector<bool> visited(V, false);
    dfs(0, adj, visited);

    if (visited[d] == false)
        return 0;

    for (int i = 0; i < V; i++)
        visited[i] = false;
    // remove that edge from graph
    for (int i = 0; i < adj[c].size(); i++)
    {
        if (adj[c][i] == d)
        {
            adj[c].erase(adj[c].begin() + i);
            break;
        }
    }
    for (int i = 0; i < adj[d].size(); i++)
    {
        if (adj[d][i] == c)
        {
            adj[d].erase(adj[d].begin() + i);
            break;
        }
    }
    // now check it is dissconnected or not
    dfs(0, adj, visited);

    if (visited[d] == false)
        return 1;

    return 0;
}