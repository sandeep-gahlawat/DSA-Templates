
#include <bits/stdc++.h>
using namespace std;

//tc O(ELOGV)
void addEdge(vector<vector<pair<int, int>>> &adj, int u,
             int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void primMST(vector<vector<pair<int, int>>> &adj, int V,int src)
{
    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //initialize all the distances infinite initially
    vector<int> dist(V, INT_MAX);
   //parent array stores mst
    vector<int> parent(V, -1);
   
    // To keep track of vertices included in MST
    vector<bool> MST(V, false);

    pq.push({0,src});
    dist[src] = 0;
    

    while (!pq.empty())
    {
       
        int u = pq.top().second;
        pq.pop();

        if (MST[u] == true)
        {
            continue;
        }
      //include vertex u in the mst
        MST[u] = true;

        // Traverse all adjacent of u
        for (auto x : adj[u])
        {

            int v = x.first;
            int weight = x.second;

            // If v is not in MST and weight of (u,v) is smaller
            // than current dist of v
            if (MST[v] == false && dist[v] > weight)
            {
                
                dist[v] = weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    int sum = 0;
	cout<<"edges of mst are:"<<endl;
    for (int i = 0; i < V; ++i)
    {
      if(parent[i]!=-1)
      {
       sum+=dist[i];
       cout<<parent[i]<<" "<<i<<endl;
      }
    }
    cout<<"sum of weight of edges of mst: "<<sum<<endl;
       
}


int main()
{
    int V = 7;
    vector<vector<pair<int, int>>> adj(V);

    
    addEdge(adj, 0, 1, 14);
    addEdge(adj, 0, 5, 7);
    addEdge(adj, 0, 3, 5);
    addEdge(adj, 0, 2, 21);
    addEdge(adj, 3, 5, 13);
    addEdge(adj, 3, 4, 22);
    addEdge(adj, 2, 4, 4);
    addEdge(adj, 2, 6, 3);
    addEdge(adj, 2, 1, 15);
    addEdge(adj, 1, 6, 19);
    addEdge(adj, 5, 6, 18);
    addEdge(adj, 5, 4, 15);
    addEdge(adj, 1, 5, 2);
    addEdge(adj, 6, 4, 2);
    

    primMST(adj, V,0);

    return 0;
}
