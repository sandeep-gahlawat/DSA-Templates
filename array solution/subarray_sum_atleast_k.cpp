#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums and an integer k,
//  return the length of the shortest non-empty subarray of nums with a sum
//   of at least k. If there is no such subarray, return -1.

// A subarray is a contiguous part of an array.
// leetcode link:https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

// better solution
int shortestSubarray(vector<int> A, int K)
{
    int N = A.size();
    long long  res = N + 1;
    deque<long long> d;
    for (long long i = 0; i < N; i++)
    {
        if (i > 0)
            A[i] += A[i - 1];
        if (A[i] >= K)
            res = min(res, i + 1);
        while (d.size() > 0 && A[i] - A[d.front()] >= K)
        {

            res = min(res, i - d.front());
            d.pop_front();
        }
        // when we get negative element in the array
        // there is no need of elements are that are greater than A[i] because
        // we do not need to minimize the sum we have to reduce the subarray length
        
        while (d.size() > 0 && A[i] <= A[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    return res <= N ? res : -1;
}
// written by me in first time
int shortestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    long long res = INT_MAX;
    long long low = 0, sum = 0;
    priority_queue<pair<long long, long long>> pq;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        while (!pq.empty())
        {
            auto x = pq.top();
            x.first = -x.first;
            if (sum - x.first >= k && x.second >= low && x.second <= i)
            {
                res = min(res, i - x.second);
                pq.pop();
                low = x.second + 1;
            }
            else if (x.second < low)
            {
                pq.pop();
            }
            else
                break;
        }
        while (!pq.empty())
        {
            auto x = pq.top();
            if (x.second < low)
                pq.pop();
            else
                break;
        }

        pq.push({-sum, i});
        if (sum >= k)
        {
            res = min(res, i - low + 1);
        }
    }
    if (res == INT_MAX)
        return -1;
    return res;
}