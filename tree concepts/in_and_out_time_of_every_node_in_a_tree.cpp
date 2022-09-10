// C++ program to check if given pairs lie on same
// path or not.
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;


// Time Complexity – O(n) for preprocessing and O(1) per query.
// Check if two nodes are on same path in a tree

// To store start and end time of all vertices
// during DFS.
int intime[MAX];
int outtime[MAX];

// initially timer is zero
int timer = 0;

// Does DFS of given graph and fills arrays
// intime[] and outtime[]. These arrays are used
// to answer given queries.
void dfs(vector<int> graph[], int src, vector<bool> &visit)
{
    visit[src] = true;

    // Increment the timer as you enter
    // the recursion for v
    ++timer;

    // Upgrade the in time for the vertex
    intime[src] = timer;

    for (auto &it : graph[src])
    {
        if (visit[it] == false)
            dfs(graph, it, visit);
        it++;
    }

    // increment the timer as you exit the
    // recursion for v
    ++timer;

    // upgrade the outtime for that node
    outtime[src] = timer;
}

// Returns true if 'u' and 'v' lie on same root to leaf path
// else false.
bool query(int u, int v)
{
    return ((intime[u] < intime[v] && outtime[u] > outtime[v]) ||
            (intime[v] < intime[u] && outtime[v] > outtime[u]));
}

  
