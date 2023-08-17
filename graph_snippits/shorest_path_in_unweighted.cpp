#include<bits/stdc++.h>
using namespace std;
// using bfs we can also do it using dfs
// edge weight between every u->v is considered as 1;
vector<int> s_path_in_unweighted(int src,vector<vector<int>>&graph)
{
    int v = graph.size();
    vector<int>dist(v,INT_MAX);
    vector<int>visited(v,false);
    queue<int>q;
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for(auto&x:graph[u])
        {
            if(visited[x]==false)
            {
                dist[x] = dist[u]+1;
                visited[x] = true;
                q.push(v);
            }
        }
    }
    
    return dist;
}