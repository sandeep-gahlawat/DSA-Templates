#include <bits/stdc++.h>
using namespace std;
//leetcode link:https://leetcode.com/problems/russian-doll-envelopes/
//applied same lis approach here
// sort according to width(the one shorter width comes first)if width are equal
// the one with greater height comes first
// and then find lis on height
static bool cmp(const vector<int> &a, const vector<int> &b)
{
    //if the width are equal the one with greater comes first
    //[[5,4],[6,4],[6,7],[2,3]]
    // because if not apply this condition then=>
    // [2,3][5,4][6,4][6,7]=>lis in this array is 2
    // but if apply this condition
    //   [2,3][5,4][6,7][6,4]=>lis in this array is 3=>which is correct
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &es)
    {
        sort(es.begin(), es.end(), cmp);
        //same binary search approach like lis on height
        vector<int> dp;
        for (auto e : es)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), e[1]);
            if (iter == dp.end())
                dp.push_back(e[1]);
            else if (e[1] < *iter)
                *iter = e[1];
        }
        return dp.size();
    }
};