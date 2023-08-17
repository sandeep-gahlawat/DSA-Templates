#include <bits/stdc++.h>

using namespace std;
//leetcode link :https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
int numberOfArithmeticSlices(vector<int> &nums)
{
    // every index contain an map (stores diff->(no_of_subsequence at that index))
    vector<unordered_map<long, long>> dp(nums.size());
    int res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            long diff = (long)nums[i] - (long)nums[j];

            dp[i][diff]++;

            if (dp[j].find(diff) != dp[j].end())
            {
                dp[i][diff] += dp[j][diff];
                // no of subsequence till j'th 
                res += dp[j][diff];
            }
        }
    }

    return res;
}