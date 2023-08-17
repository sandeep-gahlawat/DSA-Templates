#include <bits/stdc++.h>
using namespace std;

// leetcode link:https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution
{
public:
    int dp[101][101];

    int dfs(vector<vector<pair<int, int>>> &graph, int src, int dst, int k)
    {
        if (src == dst)
            return 0;
        if (k <= -1)
            return INT_MAX;

        if (dp[src][k] != -1)
            return dp[src][k];

        int ans = INT_MAX;
        for (auto x : graph[src])
        {
            int res = dfs(graph, x.first, dst, k - 1);
            if (res != INT_MAX)
                ans = min(ans, x.second + res);
        }

        return dp[src][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        memset(dp, -1, sizeof dp);
        vector<vector<pair<int, int>>> graph(n);
        for (auto &x : flights)
        {
            graph[x[0]].push_back({x[1], x[2]});
        }
        int ans = dfs(graph, src, dst, k);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
// we can also sove this using bellmon ford algorithm 
// write same but run it k+1 times instead of v-1 iterations