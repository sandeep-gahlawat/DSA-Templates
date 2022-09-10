#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<int>adj[],vector<bool>&visited,int des,int&count)
{
    visited[src] = true;
    if(src==des)
    {
        count++;
    }
    for(auto x:adj[src])
    {
        if(visited[x]==false)
        {
            // dfs(x,adj,visited,des);
        }
    }
}
 int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<bool>visited(V,false);
        int count = 0;
        // dfs(source,adj,visited,destination);
        return count;
    }