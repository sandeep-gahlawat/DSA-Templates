#include<bits/stdc++.h>
using namespace std;

//this problem is little different from first one in this houses are connected in circular way so first house and last house are adjacent so make two cases either include first exclude last either exclude first include last
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
int rob2(vector<int>&nums)
{
    vector<int>nums1(nums.begin()+1,nums.end());//exclude first
    vector<int>nums2(nums.begin(),nums.end()-1);//exclude last
    return max(rob(nums1),rob(nums2));
}