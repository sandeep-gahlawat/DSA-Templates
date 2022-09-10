#include <bits/stdc++.h>
using namespace std;

// this algorithm also valid for negative edges
//   tc = O(v*E)=> if graph is a complete graph E = V*(v-1)/2=>
//     tc = >O(v*(v*(v-1)))=>O(v3)
vector<int> BellmanFord(vector<vector<int>> &edges, int src, int V)
{
    int E = edges.size();
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
    for (int i = 1; i <= V - 1; i++)
    {
        for (auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            int weight = x[2];
            //relexation operation
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: check for negative-weight cycles.  The above
    // step guarantees shortest distances if edges doesn't
    // contain negative weight cycle.  If we get a shorter
    // path, then there is a cycle.
    for (auto &x : edges)
    {
        int u = x[0];
        int v = x[1];
        int weight = x[2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "there is negative cycle in this graph" << endl;
            return {};
        }
    }

    return dist;
}

