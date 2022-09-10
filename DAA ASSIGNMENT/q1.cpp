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
int diameter(int src,vector<vector<pair<int,int>>>&adj,vector<bool>&visited)
{
    int maxi = 0;
    visited[src] = true;
    for(auto &x:adj[src])
    {
        if(visited[x.first]==false)
        {
            maxi = max(maxi,x.second+diameter(x.first,adj,visited));
        }
    }
    visited[src]=false;
    return maxi;
}
int main()
{
    int V = 10;
    graph edges(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            int weight = rand() % 100 + 1;
            edges.addedge(i, j, weight);
        }
    }

    int sum1 = edges.minimum_spanning_tree();
    vector<vector<int>> mst1 = edges.output;
    
    set<vector<int>> st;
    for (auto &x : mst1)
    {
        st.insert(x);
    }

    // remove them from graph
    graph graph_after_mst(V);
    for (auto &x : edges.Edge)
    {
        vector<int> temp = {x[1], x[2], x[0]};
        if (st.find(temp) == st.end())
        {
            graph_after_mst.addedge(x[1], x[2], x[0]);
        }
    }
    int sum2 = graph_after_mst.minimum_spanning_tree();
    vector<vector<int>> mst2 = graph_after_mst.output;

    // merge both mst
    graph merge_graph(V);
    for (auto &x : mst2)
    {
        st.insert(x);
    }
    for (auto &x : st)
    {
        merge_graph.addedge(x[0], x[1], x[2]);
    }
    int sum3 = merge_graph.minimum_spanning_tree();
    vector<vector<int>> mst3 = merge_graph.output;

    cout << "graph edges initaially" << endl;
    for (auto &x : edges.Edge)
    {
        cout << x[1] << " " << x[2] << " " << x[0] << endl;
    }

    cout << "edges of first mst are" << endl;
    for (auto &x : mst1)
    {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
    cout << "sum of first mst : " << sum1 << endl;
    cout << "graph after removing mst" << endl;
    for (auto &x : graph_after_mst.Edge)
    {
        cout << x[1] << " " << x[2] << " " << x[0] << endl;
    }

    cout << "edges of second mst are " << endl;
    for (auto &x : mst2)
    {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
    cout << "sum of second mst : " << sum2 << endl;
    cout << " graph after merging both of them" << endl;
    for (auto &x : merge_graph.Edge)
    {
        cout << x[1] << " " << x[2] << " " << x[0] << endl;
    }

    cout << "edges of third mst are " << endl;
    for (auto &x : mst3)
    {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
    cout << "sum of third mst : " << sum3 << endl;


   vector<vector<pair<int,int>>>adj(V);
   for(auto &x:merge_graph.Edge)
   {
       int u = x[1];
       int v = x[2];
       int w = x[0];
       adj[u].push_back({v,w});
       adj[v].push_back({u,w});
   }
   vector<bool>visited(V,false);
   int res = 0;
   for(int i = 0;i<V;i++)
   {
      res = max(res,diameter(i,adj,visited));
   }
   cout<<"diameter of graph(merge of both the mst) : "<<res<<endl;
    return 0;
}
