#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
};

class Solution
{
public:
    long long rec(int ind, long long fuel, vector<vector<int>> &stations,map<pair<long long,long long>,long long>&mp)
    {
        if (ind == stations.size()-1)
        {
            return 0;
        }
        if(mp.find({ind,fuel})!=mp.end())
        {
            return mp[{ind,fuel}];
        }
        if (stations[ind + 1][0] - stations[ind][0] <= fuel)
        {
            mp[{ind,fuel}] =  min(1 + rec(ind + 1, fuel - (stations[ind + 1][0] - stations[ind][0]) + stations[ind + 1][1], stations,mp), rec(ind + 1, fuel - (stations[ind + 1][0] - stations[ind][0]), stations,mp));
        }
        else
            return mp[{ind,fuel}] =  INT_MAX;
    }
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        if(startFuel>=target)
            return 0;
        vector<vector<int>> arr;
        arr.push_back({0, startFuel});
        for (auto &x : stations)
            arr.push_back(x);
        arr.push_back({target, 0});
        map<pair<long long,long long>,long long>mp;
        long long ans = rec(0, startFuel, arr,mp);
        if (ans >= INT_MAX)
            return -1;
        return ans;
    }
};