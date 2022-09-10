#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    int *parent;
    int *rank;
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];
        for (int i = 0; i < v; i++)
        {
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
            return x;

        // concept of path compression used here
        parent[x] = find(parent[x]);

        return parent[x];
    }
    // Function to merge two nodes a and b.
    void union_(int a, int b)
    {
        int rep_x = find(a);
        int rep_y = find(b);
        if (rep_x == rep_y)
            return;
        else if (rank[rep_x] < rank[rep_y])
            parent[rep_x] = rep_y;
        else if (rank[rep_y] < rank[rep_x])
            parent[rep_y] = rep_x;
        else
        {
            parent[rep_x] = rep_y;
            rank[rep_y]++;
        }
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y)
    {
        if (find(x) == find(y))
            return true;
        return false;
    }
    // Function to determine number of connected components.(like number of islands)
    int findNumberOfConnectedComponents(int n)
    {
        unordered_set<int> set;
        for (int i = 1; i <= n; i++)
        {
            set.insert(find(i));
        }
        return set.size();
    }
};



// Function to detect cycle using DSU in an undirected graph.
int detectCycle(int V, vector<int> adj[])
{
    DSU dsu(V);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < V; i++)
    {
        int i_rep = dsu.find(i);
        for (auto x : adj[i])
        {
            if (mp.find({i, x}) != mp.end() or mp.find({x, i}) != mp.end())
                continue;
            mp[{i, x}] = 1;
            int x_rep = dsu.find(x);
            if (i_rep == x_rep)
                return 1;
            else
                dsu.union_(i, x);
        }
    }
    return 0;
}