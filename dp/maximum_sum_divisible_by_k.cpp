#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   //concept is simple if want to include element arr[i]=>let's arr[i]%k = x
   //  so we need maximun sum from (0 to i-1) which have remender k-x;
   // e.g problem
   // leetcode link : https://leetcode.com/problems/greatest-sum-divisible-by-three/
    int maxSumDivThree(vector<int> &nums,int k)
    {
        vector<int> dp(k,0);
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> temp;
            temp = dp;
            for (auto x : dp)
            {
                int cur = x + nums[i];
                temp[cur % k] = max(temp[cur % k], cur);
            }
            dp = temp;
        }
        return dp[0];
    }
};