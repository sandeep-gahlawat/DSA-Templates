// C++ program to show segment tree operations like construction, query
// and update
#include <bits/stdc++.h>
using namespace std;

//all leaf nodes in segment tree are the values of array
class NumArray
{
public:
    vector<int> arr;
    vector<int> tree;
    //function for construct segment tree
    int constructst(int start, int end, int index)
    {
        if (start == end)
        {
            tree[index] = arr[start];
            return arr[start];
        }
        int mid = (start + end) / 2;
        //value of tree[i] = sum of left child + sum of right child
        tree[index] = constructst(start, mid, 2 * index + 1) + constructst(mid + 1, end, 2 * index + 2);
        return tree[index];
    }
    NumArray(vector<int> &nums)
    {
        arr = nums;
        //size of segment tree array can be 4 times the size of aray
        tree.resize(4 * (arr.size()), 0);
        constructst(0, arr.size() - 1, 0);
    }
    void updateuntil(int start, int end, int i, int index, int diff)
    {
        //if i is out of bound then there is no need to update values in that range
        if (i < start || i > end)
        {
            return;
        }

        //update that node and check for it's left and right child
        tree[index] = tree[index] + diff;
        if (end > start)
        {

            int mid = (start + end) / 2;
            updateuntil(start, mid, i, 2 * index + 1, diff);
            updateuntil(mid + 1, end, i, 2 * index + 2, diff);
        }
    }
    void update(int index, int val)
    {
        int diff = val - arr[index];
        arr[index] = val;
        updateuntil(0, arr.size() - 1, index, 0, diff);
    }
    int getsum(int start, int end, int left, int right, int index)
    {

        if (end < left || start > right)
            return 0;
        if (left <= start && right >= end)
        {
            return tree[index];
        }
        int mid = (start + end) / 2;
        
        return getsum(start, mid, left, right, 2 * index + 1) + getsum(mid + 1, end, left, right, 2 * index + 2);
    }
    int sumRange(int left, int right)
    {
        return getsum(0, arr.size() - 1, left, right, 0);
    }
};