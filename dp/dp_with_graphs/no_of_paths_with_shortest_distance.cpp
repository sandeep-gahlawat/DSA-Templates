#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod= 1e9+7;

//leetcode link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll dp[n][n][2]; 
        // dp[i][j][0] stores minimum distance and dp[i][j][1] stores number of ways to reach     with the minimum distance dp[i][j][0]
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(i!=j){
                    dp[i][j][0] = 1e13;
                    dp[i][j][1]=0;
                }
                else
                {
                    dp[i][j][0]=0;
                    dp[i][j][1]=1;
                }
            }
        }
        for(ll i=0; i<roads.size(); i++){
            dp[roads[i][0]][roads[i][1]][0]=roads[i][2];
            
            dp[roads[i][1]][roads[i][0]][0]=roads[i][2];
            dp[roads[i][0]][roads[i][1]][1]=1;
            
            dp[roads[i][1]][roads[i][0]][1]=1;
        }
        for(ll mid=0; mid<n; mid++){
            for(ll i=0; i<n; i++){
                for(ll j=0; j<n; j++){
                    if(i!=mid && j!=mid){
                        if(dp[i][mid][0]+dp[mid][j][0]<dp[i][j][0]){
                            dp[i][j][0]=dp[i][mid][0]+dp[mid][j][0];
                            dp[i][j][1] = (dp[i][mid][1]*dp[mid][j][1])%mod;
                        }
                        else if(dp[i][j][0]==dp[i][mid][0]+dp[mid][j][0]){
                            dp[i][j][1] = (dp[i][j][1]+dp[i][mid][1]*dp[mid][j][1])%mod;
                        }
                    }
                }
            }
        }
        return dp[n-1][0][1];
    }
};


//using dikistra algorithm
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& grid) {
        vector <vector <pair <long long, long long>>> graph(n+1);
        for(auto x: grid) { //creating adjacency list
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        long long INF = 1e15;
        long long MOD = 1e9 + 7;
        vector <long long> dp(n+1, 0);
        vector <long long> dist(n+1, INF);
        priority_queue <pair <long long, long long>> q; // maxHeap in c++
		// although we can use use minHeap in c++ by adding parameter to the maxHeap template
		// but I have inserted -1*val into the maxHeap so it worked fine as minHeap
		
        dist[0] = 0;
        dp[0] = 1; // initilize it to 1 since to reach 0 we have 1 way
        q.push({0, 0});
		
        while(q.size()) {
            long long node = q.top().second;
            long long nodeWt = -q.top().first;
            q.pop();

			/*
			what if we inserted min weight after some greater weight and we always pop min weight so it can be
			possible that some nodeWt (> dist[node]) is there in the queue that we haven't popped yet...
			hence we are continuing so that we don't traverse adjacency list of node again
			
			I have taken a graph as an example below the code.
			*/
            if(dist[node] < nodeWt) continue; // explained above
            for(auto key: graph[node]) {
                long long child = key.first;
                long long childWt = key.second;
                if(nodeWt + childWt == dist[child]) {
					// we are adding parent's dp value to child's dp 
                    dp[child] = (dp[child] + dp[node])%MOD;
                }
                if(nodeWt + childWt < dist[child]) {
                    dp[child] = dp[node]%MOD; // we are getting value of parent's dp
                    dist[child] = nodeWt + childWt;
                    q.push({-dist[child], child});
                }
            }
        }
        return dp[n-1];
    }
};