#include <bits/stdc++.h>
using namespace std;

// 1425. Constrained Subsequence Sum
// Given an integer array nums and an integer k,
//  return the maximum sum of a non-empty subsequence of that array
//   such that for every two consecutive integers in the subsequence,
//  nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

int constrainedSubsetSum(vector<int> &A, int k)
{
    //max_deque
    deque<int> q;
    int res = A[0];
    for (int i = 0; i < A.size(); ++i)
    {
        // A[i]=>maximum sum including A[i]
        A[i] += q.size() ? q.front() : 0;
        res = max(res, A[i]);
        while (q.size() && A[i] > q.back())
            q.pop_back();
            //we add only positive elements beacuse there is no point of adding negative
            //numbers because they decrease the sum and we have to maximize the sum
        if (A[i] > 0)
            q.push_back(A[i]);
            // we can take max window of size k
        if (i >= k && q.size() && q.front() == A[i - k])
            q.pop_front();
    }
    return res;

}