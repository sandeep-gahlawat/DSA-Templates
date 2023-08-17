
// tc = elogv

// Spanning tree has v-1 edges, where v is the number of nodes (vertices).

// From a complete graph, by removing maximum e - v + 1 edges,
//  we can construct a spanning tree.

// A complete graph can have maximum v^(v-2)=>pow(v,v-2) number of spanning trees.

// Thus, we can conclude that spanning trees are a subset of connected Graph G
//  and disconnected graphs do not have spanning tree.
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
};

class graph
{
public:
    vector<vector<int>> Edge;
    vector<vector<int>> output;
    int V;

    graph(int v)
    {
        V = v;
    }

    void addedge(int x, int y, int w)
    {
        Edge.push_back({w, x, y});
    }

    int minimum_spanning_tree()
    {
        int res = 0;
        DSU dsu(V);
        sort(Edge.begin(), Edge.end());
        int E = Edge.size();
        int j = 0;
        for (int i = 0; i < E && j < V - 1; i++)
        {
            int u = Edge[i][1];
            int v = Edge[i][2];
            int w = Edge[i][0];
            if (dsu.find(u) != dsu.find(v))
            {
                dsu.union_(u, v);
                res += w;

                output.push_back({u, v, w});
                j++;
            }
        }
        return res;
    }
};
int main()
{
    int V = 7;
    graph edges(V);
    edges.addedge(0, 1, 14);
    edges.addedge(0, 5, 7);
    edges.addedge(0, 3, 5);
    edges.addedge(0, 2, 21);
    edges.addedge(3, 5, 13);
    edges.addedge(3, 4, 22);
    edges.addedge(2, 4, 4);
    edges.addedge(2, 6, 3);
    edges.addedge(2, 1, 15);
    edges.addedge(1, 6, 19);
    edges.addedge(5, 6, 18);
    edges.addedge(5, 4, 15);
    edges.addedge(1, 5, 2);
    edges.addedge(6, 4, 2);

    int sum = edges.minimum_spanning_tree();
    vector<vector<int>> mst = edges.output;
    cout<<"edges of mst are :"<<endl;
    for(auto &x:mst)
    {
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }
    cout<<"sum of weight of edges : "<<sum<<endl;
    return 0;
}
