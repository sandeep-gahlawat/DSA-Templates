#include <bits/stdc++.h>
using namespace std;

// std::nth_element in C++

// C++ program to demonstrate the use of std::nth_element
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int v[] = {3, 2, 10, 45, 33, 56, 23, 47}, i;

    // Using std::nth_element with n as 5
    std::nth_element(v, v + 4, v + 8); // it actually partion the array using n'th element
    // Since, n is 5 so 5th element should be sorted
    for (i = 0; i < 8; ++i)
    {
        cout << v[i] << " ";
    }
    return 0;
}

// we can also define our own comparater function

// C++ program to demonstrate the use of std::nth_element
#include <iostream>
#include <algorithm>
using namespace std;

// Defining the BinaryFunction
bool comp(int a, int b)
{
    return (a < b);
}
int main()
{
    int v[] = {3, 2, 10, 45, 33, 56, 23, 47}, i;

    // Using std::nth_element with n as 6
    std::nth_element(v, v + 5, v + 8, comp);

    // Since, n is 6 so 6th element should be the same
    // as the sixth element present if we sort this array
    // Sorted Array
    /* 2 3 10 23 33 45 47 56 */
    for (i = 0; i < 8; ++i)
    {
        cout << v[i] << " ";
    }
    return 0;
}

// example problem using this stl
// leetcode link : https://leetcode.com/problems/the-k-strongest-values-in-an-array/

class Solution
{
public:
    // very strong solution a good use of stls
    //  solved this question in O(n) time
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        //finding median
        nth_element(begin(arr), begin(arr) + (arr.size() - 1) / 2, end(arr));
        int m = arr[(arr.size() - 1) / 2];

        //geting first k elements according to comparator function
        nth_element(begin(arr), begin(arr) + k, end(arr), [&](int a, int b)
                    { return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m); });
        arr.resize(k);
        return arr;
    }
};