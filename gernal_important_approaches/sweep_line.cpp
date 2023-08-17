#include <bits/stdc++.h>
using namespace std;

// it is a very important approach it reduces our time complexity
// eg. let's say we have to find frequency of each index in the array we have given
//     some intervals like [1,3],[0,4],[2,4] like that
//     brute force
// vector<int>freq(n,0);
// for (auto &x : intervals)
// {
//    for(int i = x[0];i<=x[1];i++)
//    freq[i]++;
// }
// above approach is brute force we can optimize it using the concept of sweep line
// like
// vector<int>freq(n,0);
// for (auto &x : intervals)
// {
//    freq[x[0]]++;
//    if(x[1]+1<n)
//     freq[x[1]+1]--;
// }
// for(int i = 1;i<n;i++)
// {
//     freq[i]+=freq[i-1];
// }
// this sweep line approach is line we add it's contribution by adding 1 and we it's
// range is over we decrement it's contribution like we put a line till that line we add
// it's contribution after that we decrement it's contribution

// some practice problems
// 1589. Maximum Sum Obtained of Any Permutation
//     We have an array of integers, nums, and an array of requests
//  where requests[i] = [starti, endi].
//   The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi].
//    Both starti and endi are 0-indexed.
// Return the maximum total sum of all requests among all permutations of nums.
// Since the answer may be too large, return it modulo 109 + 7.

int maxSumRangeQuery(vector<int> &A, vector<vector<int>> &req)
{
    long res = 0, mod = 1e9 + 7, n = A.size();
    // here this approach is used
    vector<int> count(n);
    for (auto &r : req)
    {
        count[r[0]] += 1;
        if (r[1] + 1 < n)
            count[r[1] + 1] -= 1;
    }
    for (int i = 1; i < n; ++i)
        count[i] += count[i - 1];

    sort(begin(count), end(count));
    sort(begin(A), end(A));
    for (int i = 0; i < n; ++i)
        res += (long)A[i] * count[i];
    return res % mod;
}

// 1094. Car Pooling
//     There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
// You are given the integer capacity and an array trips
//  where trips[i] = [numPassengersi, fromi, toi]
//  indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively.
//   The locations are given as the number of kilometers due east from the car's initial location.
// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

// this problem is also solved using this concept only
// add the passenger at th given point and leave them when there distance is over
bool carPooling(vector<vector<int>> &trips, int capacity)
{
    map<int, int> m;
    for (auto &t : trips)
        m[t[1]] += t[0], m[t[2]] -= t[0];
    for (auto &x : m)
        if ((capacity -= x.second) < 0)
            return false;
    return true;
}

// 1109. Corporate Flight Bookings
// There are n flights that are labeled from 1 to n.
// You are given an array of flight bookings bookings,
//  where bookings[i] = [firsti, lasti, seatsi]
//  represents a booking for flights firsti through lasti (inclusive)
//   with seatsi seats reserved for each flight in the range.
// Return an array answer of length n,
//  where answer[i] is the total number of seats reserved for flight i

vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> ans(n, 0);
    for (auto &x : bookings)
    {
        ans[x[0] - 1] += x[2];
        if (x[1] < n)
            ans[x[1]] -= x[2];
    }
    for (int i = 1; i < n; i++)
    {
        ans[i] += ans[i - 1];
    }
    return ans;
}
