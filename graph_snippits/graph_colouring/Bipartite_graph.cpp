#include<bits/stdc++.h>
using namespace std;


// A bipartite graph is possible if the graph coloring is possible using two colors
//  such that vertices in a set are colored with the same color.
//   Note that it is possible to color a cycle graph
//    with even cycle using two colors.
//  For example, see the following graph. 


// using BFS
bool isBipartite(int V, vector<vector<int>> &adj)
{
    // vector to store colour of vertex
    // assigning all to -1 i.e. uncoloured
    // colours are either 0 or 1
      // for understanding take 0 as red and 1 as blue
    vector<int> col(V+1, -1);
 
    // queue for BFS storing {vertex , colour}
    queue<pair<int, int> > q;
   
      //loop incase graph is not connected
    for (int i = 1; i <= V; i++) {
       
      //if not coloured
        if (col[i] == -1) {
           
          //colouring with 0 i.e. red
            q.push({ i, 0 });
            col[i] = 0;
           
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
               
                  //current vertex
                int v = p.first;
                  //colour of current vertex
                int c = p.second;
                 
                  //traversing vertexes connected to current vertex
                for (int j : adj[v]) {
                   
                      //if already coloured with parent vertex color
                      //then bipartite graph is not possible
                    if (col[j] == c)
                        return false;
                   
                      //if uncooloured
                    if (col[j] == -1) {
                      //colouring with opposite color to that of parent
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    //if all vertexes are coloured such that
      //no two connected vertex have same colours
    return true;
}

  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto &x:dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return isBipartite(n,adj);
    }




    // using dfs
     bool dfs(vector<vector<int>>& graph, int i, int col, vector<int>& color) {
        color[i] = col;
        for(auto x: graph[i]) {
            if(color[x] == color[i]) {
                return false;
            }
            if(color[x] == 0 && !dfs(graph, x, -col, color)) {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1);
        for(auto i: dislikes) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int> color(N+1, 0); // 0 -> not visited, 1 -> group 1, -1 -> group 2
        for(int i=1;i<=N;i++) {
            if(color[i] == 0 && !dfs(graph, i, 1, color)) {
                return false;
            }
        }
        return true;
    }