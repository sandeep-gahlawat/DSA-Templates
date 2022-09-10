#include <bits/stdc++.h>
using namespace std;
// count pairs that are less than equal to k in the array
int count_pairs_diff_less_than_k(vector<int> &nums, int k)
{
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int j = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && nums[j] - nums[i] <= k)
            j++;
        j--;
        res += (j - i);
    }
    return res;
}