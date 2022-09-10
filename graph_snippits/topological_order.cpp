#include<bits/stdc++.h>
using namespace std;
vector<int> toplogicalsort_bfs(vector<vector<int>>&adj,int v)
{
    vector<int>indegree(v,0),res;
    for(int u = 0;u<v;u++)
    {
        for(auto x:adj[u])
        indegree[x]++;
    }
    queue<int>q;
    for(int i = 0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(auto x:adj[u])
        {
            if(--indegree[x]==0)
            q.push(x);
        }
    }
    return res;
}



// using dfs
void DFS(vector<int> adj[], int u,stack<int> &st, bool visited[]) 
{ 	
    visited[u]=true;
    
    for(int v:adj[u]){
        if(visited[v]==false)
            DFS(adj,v,st,visited);
    }
    st.push(u);
}


void topologicalSort_dfs(vector<int> adj[], int V) 
{ 
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
	stack<int> st;
    
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(adj,u,st,visited);
        }
    }
    
    while(st.empty()==false){
        int u=st.top();
        st.pop();
        cout<<u<<" ";
    }
   
}
