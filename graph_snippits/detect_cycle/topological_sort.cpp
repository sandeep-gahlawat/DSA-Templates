#include <bits/stdc++.h>
using namespace std;

// Topological Sorting for a graph is not possible if the graph is not a DAG(directed acyclic graph)
// There can be more than one topological sorting for a graph
// The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).

// using khan's bfs based algorithm
void topological_sort(vector<int> adj[], int v)
{
    vector<int> indegree(v, 0);
    for (int u = 0; u < v; u++)
    {
        for (auto x : adj[u])
        {
            indegree[x]++;
        }
    }

    queue<int> q;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto x : adj[u])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
}

// using dfs
void dfs(vector<int> adj[], vector<bool> &visited, int u, stack<int> &st)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (visited[x] == false)
            dfs(adj, visited, x, st);
    }
    st.push(u);
}
void topological_sorts(vector<int> adj[], int v)
{
    vector<bool> visited(v, false);
    stack<int> st; 
    for (int u = 0; u < v; u++)
    {
        if (visited[u] == false)
        {
            dfs(adj, visited, u, st);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}