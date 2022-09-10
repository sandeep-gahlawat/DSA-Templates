#include <bits/stdc++.h>
using namespace std;

// leetcode link:https://leetcode.com/problems/continuous-subarray-sum/
//  easy solution
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum % k == 0 && i >= 1)
            {
                return true;
            }
            int x = k;
            while (sum - x >= 0)
            {
                if (mp.find(sum - x) != mp.end())
                {
                    if (i - mp[sum - x] >= 2)
                        return true;
                }
                x += k;
            }

            if (mp.find(sum) != mp.end())
            {
                if (i - mp[sum] >= 2)
                    return true;
            }
            mp.insert({sum, i});
        }
        return false;
    }
};

// better solution
//  There is a condition of subarray length of atleast 2,
//   thats why we store sum in the map mods after 1 iteration,
//   we store the sum in a variable pretemp.
//  We dont need to store the whole sum,
//  we just store sum mod k or sum % k ,
//   as (a + b + .... + z)%k is equivalent to ( a%k + b%k + .... + z%k).
//  As we cant divide any number by 0, we store the whole in the array.
//   And also fork = 0 , the function will return true if
//    there are two continous 0 ( i.e [1, 4, 5, 0, 0, 8] ) in the given array.

// approach is we have to find numbers with same remainder=>beacuse between them elements have sum
// multiple of k;
bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size(), pretemp = 0, sum = 0;
    unordered_map<int, int> mods;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + nums[i]) % k;
        if (mods[sum])
            return true;
        mods[pretemp]++;
        pretemp = sum;
    }
    return false;
}

// leetcode link :https://leetcode.com/problems/subarray-sums-divisible-by-k/
//  this problem is also solved with same concept
int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size(), sum = 0;
    unordered_map<int, int> mp;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        //+k is added beacuse in some cases (sum + nums[i]%k) this will became negative
        // in that cases either we can do this
        //  if(sum<0)
        //   sum = k-abs(sum); or we can add k;
        // beacuse in language -1%k = -1 but logically it is -1%k = k-1
        sum = (sum + nums[i] % k + k) % k;

        if (sum < 0)
            sum = k - abs(sum);
        if (sum == 0)
            res++;
        if (mp[sum])
            res += mp[sum];
        mp[sum]++;
    }
    return res;
}

// leetcode link:https://leetcode.com/problems/make-sum-divisible-by-p/
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> prefix(n), suffix(n);
        int res = INT_MAX;
        int sum = 0;

        unordered_map<int, vector<int>> suffix_map;
        for (int j = n - 1; j >= 0; j--)
        {
            sum = (sum + nums[j]) % p;
            suffix[j] = sum;
            suffix_map[sum].push_back(j);
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % p;
            if (sum == 0)
            {
                res = min(res, n - 1 - i);
            }
            if (i == n - 1)
            {
                if (mp.find(sum) != mp.end())
                {
                    res = min(res, mp[sum] + 1);
                }
            }
            mp[sum] = i;
            suffix_map[suffix[i]].pop_back();
            if (suffix_map[suffix[i]].size() == 0)
                suffix_map.erase(suffix[i]);
            if (suffix_map.find(p - sum) != suffix_map.end())
            {
                res = min(res, suffix_map[p - sum].back() - i - 1);
            }
        }
        if (res == INT_MAX)
            return -1;
        return res;
    }
};
// basically simpler approach is compute the need = sum(of whole_array)%p=>this is it we have to remove
// so the basically question is we have to find shortest subarray with remender need
// so this is similar to find a subarray with sum k;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        int res = n;
        int need = 0;
        for (int i = 0; i < n; i++)
        {
            need = (need + nums[i]) % p;
        }
        int sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % p;
            mp[sum] = i;

            if (sum == need)
            {
                res = min(res, i + 1);
            }
            int x = (sum - need + p) % p;
            if (mp.find(x) != mp.end())
            {
                res = min(res, i - mp[x]);
            }
        }
        return res < n ? res : -1;
    }
};
