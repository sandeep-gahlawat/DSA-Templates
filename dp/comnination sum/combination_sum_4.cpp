#include<bits/stdc++.h>
using namespace std;


//leetcode link: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
//memoization
    int total_ways(int target,vector<int>&nums,int n,vector<int>&dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(target<0)
        {
            return 0;
        }
        if(dp[target]!=-1)
            return dp[target];
        int res = 0;
        for(int i = 0;i<n;i++){
            
            res+=total_ways(target-nums[i],nums,n,dp);
        }
        dp[target] = res;
        return res;
    }
    //using tabulation
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        dp[0] = 1;
        for(int i = 1;i<=target;i++)
        {
            long long res = 0;
            for(int j = 0;j<nums.size();j++)
            {
                if(i-nums[j]>=0)
                res+=dp[i-nums[j]];
            }
            dp[i] = res;
        }
        return dp[target];
    }
};