#include<bits/stdc++.h>
using namespace std;
//leetcode link:https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long cnt = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++)
        {
            auto left = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            auto right = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            cnt += right-left;
        }
        return cnt;
    }
};