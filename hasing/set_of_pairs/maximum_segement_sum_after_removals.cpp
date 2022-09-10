#include<bits/stdc++.h>
using namespace std;

//leetcode link : https://leetcode.com/problems/maximum-segment-sum-after-removals/
//approach=> is that first we find that interval in which the index lying => after that we divide that interval
//and this should be done in efficient time complexity that's why i have used set of pairs and mulst to store sums of intervals that are present in the set
//time complexity = >O(nlogn)
//space complexity = O(n)

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n  = nums.size();
        //set to store intervals
        set<pair<int,int>>st;
        //multiset to store sums
        multiset<long long>mulst;

        //prefix sum array
        vector<long long>prefix_sum(n,nums[0]);
        for(int i = 1;i<n;i++)
        prefix_sum[i] = prefix_sum[i-1]+nums[i];

        st.insert({0,n-1});
        mulst.insert(prefix_sum[n-1]);
        //if no element left then sum is zero
        mulst.insert(0);
         vector<long long>res;
        for(int i = 0;i<n;i++)
        {
             auto it = st.upper_bound({removeQueries[i],INT_MAX});
             it--;
             long long left_sum = (removeQueries[i]>0 ? prefix_sum[removeQueries[i]-1]:0)-(it->first>0?prefix_sum[it->first -1]:0);
             long long right_sum = prefix_sum[it->second]-prefix_sum[removeQueries[i]];

             //push left interval
             if(it->first<removeQueries[i])
             {
                 st.insert({it->first,removeQueries[i]-1});
                 //insert left interval sum also
                 mulst.insert(left_sum);
             }
             //push right interval
             if(it->second>removeQueries[i])
             {
                 st.insert({removeQueries[i]+1,it->second});
                 //insert right interval sum also
                 mulst.insert(right_sum);
             }
             //erase the sum of the interval that we have divided
             long long sum = prefix_sum[it->second]-(it->first>0?prefix_sum[it->first -1]:0);
             mulst.erase(mulst.find(sum));
             //also erase the interval aslo
             st.erase(it);
             res.push_back(*mulst.rbegin());
        }
        return res;

    }
};