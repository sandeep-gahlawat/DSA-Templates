#include <bits/stdc++.h>
// library to include pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution
{
public:
//function finds number of smaller elements on right side for each element of the array
    vector<int> constructLowerArray(int *arr, int n)
    {
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i++)
        {
            nums.push_back({arr[i], i});
        }

        sort(nums.begin(), nums.end());
        pbds st;
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            //approach is we are inserting elements into pbds in sorted order =>from that we find elements that are have greter index than current element
            res[nums[i].second] = (st.size() - st.order_of_key(nums[i].second));
            st.insert(nums[i].second);
        }
        return res;
    }
};

// from similar approach we can find number of smaller on right side ,left side,and number of greter elements on both side