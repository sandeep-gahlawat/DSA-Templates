
#include <bits/stdc++.h>
using namespace std;

void addedge(int u, int v, vector<vector<int>> &adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> bfs(int V, vector<vector<int>> &adj)
{
    vector<int> bfs_traversal;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            queue<int> q;
            vis[i] = true;
            q.push(i);
            while (!q.empty())
            {
                int g_node = q.front();
                q.pop();
                bfs_traversal.push_back(g_node);
                for (auto it : adj[g_node])
                {
                    if (!vis[it])
                    {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs_traversal;
}
// Driver program to test methods of graph class
int main()
{
    int v = 4;
    vector<vector<int>> adj(4);

    addedge(0, 1, adj);
    addedge(0, 2, adj);
    addedge(1, 2, adj);
    addedge(2, 3, adj);

    vector<int> bfs_traversal = bfs(v, adj);
    cout << "Following is Breadth First Traversal "<<endl;
         
    for (int i = 0; i < bfs_traversal.size(); i++)
    {
        cout << bfs_traversal[i] << " ";
    }
    cout << endl;

    return 0;
}
