#include <bits/stdc++.h>
using namespace std;
//leetcode link:https://leetcode.com/contest/weekly-contest-281/problems/count-array-pairs-divisible-by-k/
//question no 2183
//approach =>(n1*n2)%k==0(this is the question)=> we can replace it with (gcd(n1,k)*gcd(n2,k))%k==0

class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<long long, long long> mp;
        for (int i = 0; i < n; i++)
        {
            long long x = __gcd(nums[i], k);
            mp[x]++;
        }
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            long long x = __gcd(nums[i], k);
            mp[x]--;
            for (auto &y : mp)
            {
                if ((long long)(x * y.first) % k == 0)
                {
                    res += y.second;
                }
            }
        }

        return res;
    }
};