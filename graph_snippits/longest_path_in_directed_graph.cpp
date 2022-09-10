#include<bits/stdc++.h>
using namespace std;

int dfs(int src, vector<vector<int>> &adj, vector<bool> &visited,vector<int>&dist)
{
	visited[src] = true;
	// int cnt = 0;
	int maxi = 0;
	for (auto &x : adj[src])
	{
		if (visited[x] == false)
		{
			maxi = max(maxi, 1 + dfs(x, adj, visited,dist));
		}
		else
		maxi = max(maxi,dist[x]+1);
	}
	
	dist[src] = maxi;
// 	cout<<src<<" "<<dist[src]<<endl;
	return maxi;
}

int minColour(int N, int M, vector<int> mat[])
{
	vector<vector<int>> adj(N + 1);
	for (int i = 0; i < M; i++)
	{
		adj[mat[i][1]].push_back(mat[i][0]);
	}
	vector<bool> visited(N + 1, false);
    //stores distance 
	vector<int> dist(N+1,0);

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, 1+dfs(i, adj, visited,dist));
	return ans;
}