#include <bits/stdc++.h>
using namespace std;

// if array is simple
// =>first count the numbers of one in the array(count_ones)
// => so we have to make a subarray of ones of size(count_ones)
// => use sliding window and traverse over all the windows of size(count_ones)




// but if array is circular
// => so append nums array after nums and apply same approach

int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    int count_ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            count_ones++;
    }
    int ones = 0;
    int res = INT_MAX;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(nums[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr.push_back(nums[i]);
    }

    for (int i = 0; i < count_ones; i++)
    {
        if (arr[i] == 1)
            ones++;
    }
    res = min(res, count_ones - ones);
    for (int i = count_ones; i < 2 * n; i++)
    {
        if (arr[i - count_ones] == 1)
            ones--;
        if (arr[i] == 1)
            ones++;
        res = min(res, count_ones - ones);
    }
    return res;
}