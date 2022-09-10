#include <bits/stdc++.h>
using namespace std;
// tc = o(nlog(n));
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int>tail;
    tail.push_back(nums[0]);
    int len = 1;
    for(int i = 1;i<n;i++)
    {
        if(nums[i]>tail[len-1])
        {
            tail.push_back(nums[i]);
            len++;
        }
        else{
            int ceil_index = lower_bound(tail.begin(),tail.end(),nums[i])-tail.begin();
            tail[ceil_index] = nums[i];
        }
    }
    return len;
}
// if want to include also equal elements like
// [1,2,3,3,4,4,5] =>LIS=>[1,2,3,3,4,4,5]=>length = 5;
int lengthOfLIS_including_equal_elements(vector<int> &nums)
{
    int n = nums.size();
    vector<int>tail;
    tail.push_back(nums[0]);
    int len = 1;
    for(int i = 1;i<n;i++)
    {
        if(nums[i]>=tail[len-1])
        {
            tail.push_back(nums[i]);
            len++;
        }
        else{
            int ceil_index = lower_bound(tail.begin(),tail.end(),nums[i])-tail.begin();
            tail[ceil_index] = nums[i];
        }
    }
    return len;
}


// tc = O(N2);see from gfg also helpful in some cases

