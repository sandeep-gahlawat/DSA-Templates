#include<bits/stdc++.h>
using namespace std;

//leetcode link:https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &nums, int k)
    {
        int n = nums.size();
        vector<int> ind(n, 0);
        //set is used to avoid the repetion of ind vector
        set<vector<int>> mp;
        priority_queue<pair<int, vector<int>>> pq;
        int sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += nums[i][0];
        }
        pq.push({-sum1, ind});
        k--;
        mp.insert(ind);
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            if (k == 0)
            {
                return it.first * -1;
            }
            int temp = it.first;
            temp *= -1;
            for (int i = 0; i < n; i++)
            {
                int sum = temp;
                if (it.second[i] + 1 < nums[i].size())
                {
                    sum -= nums[i][it.second[i]];
                    sum += nums[i][it.second[i] + 1];
                    it.second[i]++;
                    if (mp.find(it.second) == mp.end())
                    {
                        mp.insert(it.second);
                        pq.push({-sum, it.second});
                    }
                    it.second[i]--;
                }
            }
            k--;
        }
        return -1;
    }
};