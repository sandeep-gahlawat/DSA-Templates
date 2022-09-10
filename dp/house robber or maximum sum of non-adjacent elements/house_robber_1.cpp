#include <bits/stdc++.h>
using namespace std;

// leetcode link : https://leetcode.com/problems/house-robber/
// problem is theif can not rob two adjacent houses

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    vector<int> dp(nums.size());//dp[i] denotes maximum money robbed by theif till i either including it or excluding it
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[nums.size() - 1];
}
//tc = O(n)
//sc = O(n)