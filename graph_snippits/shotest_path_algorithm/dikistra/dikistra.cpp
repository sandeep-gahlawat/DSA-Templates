#include<bits/stdc++.h>
using namespace std;

//this algorithm is used to find the shotest path of all vertexs from the given source vertex


// can't be used for negative edge lengths
//tc=>gernally if we don't use priority queue then it is O(v^2) but if we use priority queue
// then it is reduced to O(v +elog(v))
vector<int> dijkistra(vector<vector<pair<int,int>>> graph, int V, int src)
{
    vector<int> dist(V, INT_MAX);
    

    dist[src] = 0;
    // storing {distance,vertex};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    int u, v, w;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        u = p.second;
        //relexation operation on it's adjacents
        for (auto &to : graph[u])
        {
            v = to.first, w = to.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}