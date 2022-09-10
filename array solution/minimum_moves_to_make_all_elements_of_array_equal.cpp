#include <bits/stdc++.h>
using namespace std;

// approach is simple all the elements equal to array
// to reduce it's time complexity O(nlogn) to O(n) using nth_element stl
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median;
        if (n % 2 == 0)
        {
            median = (nums[n / 2] + nums[n / 2 - 1]) / 2;
        }
        else
            median = nums[n / 2];
        int moves = 0;
        for (int i = 0; i < n; i++)
            moves += abs(nums[i] - median);
        return moves;
    }
};

// one more similar question like it
// question ->we have make all the elements of the matrix equal
//  we can use same approach lets's say we can store all the elements of the
// matrix in the array
// and we can find median using nth_element stl
// and make all the elements equal to it

int minOperations(vector<vector<int>> &grid, int x)
{
    int res = 0;
    vector<int> arr;
    for (auto &row : grid)
        arr.insert(end(arr), begin(row), end(row));
    nth_element(begin(arr), begin(arr) + arr.size() / 2, end(arr));
    for (int i = 0; i < arr.size(); ++i)
    {
        if (abs(arr[arr.size() / 2] - arr[i]) % x)
            return -1;
        res += abs(arr[arr.size() / 2] - arr[i]) / x;
    }
    return res;
}
