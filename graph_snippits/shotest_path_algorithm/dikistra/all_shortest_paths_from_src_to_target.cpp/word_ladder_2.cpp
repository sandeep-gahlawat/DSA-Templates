#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // { 
        //this code is used for finding all the shortest path from given source vetext to destination vertext in O(v+e) time complexity
    // bfs
    vector<int> bfs(int src, vector<vector<int>> &adj, vector<vector<int>> &parent, int n)
    {
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;
        parent[src] = {-1};
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {

                int u = q.front();
                q.pop();
                for (auto &x : adj[u])
                {
                    if (dist[x] > dist[u] + 1)
                    {
                        dist[x] = dist[u] + 1;
                        q.push(x);
                        parent[x].clear();
                        parent[x].push_back(u);
                    }
                    else if (dist[x] == dist[u] + 1)
                    {
                        parent[x].push_back(u);
                    }
                }
            }
        }
        return dist;
    }
    //this function helps to store all paths from destination to src
    void path(int target, vector<vector<int>> &parent, vector<int> &curr, vector<vector<int>> &paths)
    {
        if (target == -1)
        {
            paths.push_back(curr);
            return;
        }
        for (auto &x : parent[target])
        {
            curr.push_back(target);
            path(x, parent, curr, paths);
            curr.pop_back();
        }
    }
    // }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // code for creating adjancy list
        unordered_map<string, int> first;

        unordered_map<int, string> second;
        vector<vector<int>> adj;
        int x = 0;
        for (auto it : wordList)
        {
            first[it] = ++x;
            second[x] = it;
        }
        if (first.find(beginWord) == first.end())
        {
            wordList.push_back(beginWord);
            first[beginWord] = ++x;
            second[x] = beginWord;
        }
        if (first.find(endWord) == first.end())
        {
            wordList.push_back(beginWord);
            first[endWord] = ++x;
            second[x] = endWord;
        }

        int n = wordList.size();
        adj = vector<vector<int>>(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string a = wordList[i];
                string b = wordList[j];
                int k = a.length();
                int count = 0;
                for (int m = 0; m < k; m++)
                {
                    if (a[m] != b[m])
                        count++;
                }
                if (count == 1)
                {

                    adj[first[a]].push_back(first[b]);
                    adj[first[b]].push_back(first[a]);
                }
            }
        }
        vector<vector<int>> parent(n + 1);//stores all the parent of all nodes
        vector<int> dist = bfs(first[beginWord], adj, parent, n);
        if (dist[first[endWord]] == INT_MAX)
        {
            return {};
        }
        vector<vector<int>> paths;
        vector<int> curr;
        path(first[endWord], parent, curr, paths);

        vector<vector<string>> res;
        for (auto it : paths)
        {
            reverse(it.begin(), it.end());
            vector<string> ans;
            for (auto kt : it)
            {

                ans.push_back(second[kt]);
            }
            res.push_back(ans);
        }
        return res;
    }
};