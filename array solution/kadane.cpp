#include <bits/stdc++.h>
using namespace std;

// basic kadene algorithm=>this algorithm provide maximum subarray sum
// leetcode link;https://leetcode.com/problems/maximum-subarray/
int maxSubArray(vector<int> &nums)
{
    int sum = nums[0];
    int currentsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currentsum += nums[i];
        if (currentsum > sum)
            sum = currentsum;
        if (currentsum < 0)
            currentsum = 0;
    }
    return sum;
}

// modefied questions
// find maximum subarray sum (in subarray we can delete one element)
// leetcode link : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
//  in this question we can think like that we are deleting element at index i then what
// maximum subarray sum we will get =>approach take sum before i, after i;
//  so for doing that we can maintain two arrays one from starting and one from ending

// e.g arr = [-2,-3,4,-1,-2,1,5,-3]
//     fw  = [-2,-3,4,3,1,2,7,4]
//     bw =  [2,4,7,3,4,6,5,-3]

class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int n = arr.size(), curr, maxi = INT_MIN;
        vector<int> fw(n + 1, 0), bw(n + 1, 0);
        fw[0] = arr[0];
        maxi = max(maxi, fw[0]);

        // ith element denotes the maximum subarray sum with ith element as the last element
        for (int i = 1; i < n; ++i)
        {
            curr = max(arr[i], fw[i - 1] + arr[i]);
            maxi = max(maxi, curr);
            fw[i] = curr;
        }

        // similar to fw array, but in the backward direction
        bw[n - 1] = curr = arr[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            curr = max(arr[i], bw[i + 1] + arr[i]);
            maxi = max(maxi, curr);
            bw[i] = curr;
        }

        int res = INT_MIN;
        for (int i = 1; i < n - 1; ++i)
        {
            res = max(res, fw[i - 1] + bw[i + 1]);
        }
        return max(res, maxi);
    }
};

// another modified question maximum sum circular subarray
// leetcode link : https://leetcode.com/problems/maximum-sum-circular-subarray/
//approach is simple romove that subarray that have minimum negetive sum
class Solution_circular
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int sum = nums[0];
        int currentsum = 0;
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            currentsum += nums[i];
            if (currentsum > sum)
                sum = currentsum;
            if (currentsum < 0)
                currentsum = 0;
        }
        currentsum = 0;
        int min_sum = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            currentsum += nums[i];
            if (currentsum < min_sum)
                min_sum = currentsum;
            if (currentsum > 0)
                currentsum = 0;
        }
        return max(sum, total - min_sum);
    }
};