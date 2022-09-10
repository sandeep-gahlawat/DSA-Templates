#include <bits/stdc++.h>
using namespace std;
//find that  for every element it is minimum in how many contigous elements
vector<int> number_of_subarrays(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            left[i] = i;
        }
        else
            left[i] = i - st.top() - 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n-1; i>=0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            right[i] = n-i-1;
        }
        else
            right[i] = st.top()-i-1;
        st.push(i);
    }
    vector<int>res(n);
    for(int i = 0;i<n;i++)
    {
         res[i] = 1+left[i]+right[i];
    }
    return res;
}

//if we know every element is minimum in how many contigous elements then we can easily find number of subarrays in which it is minimum

//applications of this concept
// 907. Sum of Subarray Minimums https://leetcode.com/problems/sum-of-subarray-minimums/
//2334. Subarray With Elements Greater Than Varying Threshold https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/

//1856. Maximum Subarray Min-Product https://leetcode.com/problems/maximum-subarray-min-product/