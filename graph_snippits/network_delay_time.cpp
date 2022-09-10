#include <bits/stdc++.h>
using namespace std;

// using simple dfs only
class Solution {
public:
  void dfs(int src, vector<vector<pair<int, int>>> &adj, vector<int> &time,vector<bool>&visited, int t)
{
    if(t>time[src])return;
    time[src] = min(time[src], t);

    visited[src] = true;
    for (auto &x : adj[src])
    {
        if(visited[x.first]==false)
        dfs(x.first, adj, time,visited, t + x.second);
    }
    visited[src] = false;
}
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &x : times)
    {
        adj[x[0]].push_back({x[1], x[2]});
    }
    vector<int> time(n + 1, INT_MAX);
    vector<bool>visited(n+1,false);
    dfs(k, adj, time,visited, 0);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (time[i] == INT_MAX)
            return -1;
        res = max(res, time[i]);
    }
    return res;
}
};


// using dikistra algorithm
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> g[n + 1];
        for (const auto& t : times) {
            g[t[0]].push_back({t[1], t[2]});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0, k});
        int u, v, w;
        while (!pq.empty()) {
            pair<int,int> p = pq.top(); pq.pop();
            u = p.second;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }