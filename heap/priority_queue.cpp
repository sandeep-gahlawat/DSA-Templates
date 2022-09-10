#include <bits/stdc++.h>
using namespace std;

// point no 1
void poits(vector<int> &arr)
{
    int m ;
    //first thing we can write comparator function like this also
    auto cmp = [&](int a, int b)
    {
        return abs(a - m) == abs(b - m) ? a < b : abs(a - m) < abs(b - m);
    };
    // important point is that we can push whole array in priority_queue in O(n) time
    priority_queue<int, vector<int>, decltype(cmp)> pq(arr.begin(),arr.end(), cmp);
}