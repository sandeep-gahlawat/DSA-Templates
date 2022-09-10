#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007

#define bin(n) std::bitset<32>(n).to_string()

void inout();
void SieveOfEratosthenes(vector<bool> &prime)
{

    int n = prime.size();
    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
vector<int> getMinimums(std::vector<int> nums, int k)
{
    // vector to be returned
    vector<int> ans;
    // size of nums - n
    int n = nums.size();
    // edge case
    if (k == 0 or k > n)
        return ans;
    // maintain a deque of size k
    std::deque<int> dq(k);
    // push first k elements to the deque
    for (int i = 0; i < k; i++)
    {
        // remove previous elements
        // greater than currently being added
        while (!dq.empty() && nums[i] <= nums[dq.back()])
            dq.pop_back();
        // push current element
        dq.push_back(i);
    }
    // push min element of first window to return list
    ans.push_back(nums[dq.front()]);
    // now slide the window by 1 until whole array is finished
    for (int i = k; i < n; i++)
    {
        // remove elements out of current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // remove previous elements
        // greater than currently being added
        while (!dq.empty() && nums[i] <= nums[dq.back()])
            dq.pop_back();
        // push current element
        dq.push_back(i);
        // push min of current window to return list
        ans.push_back(nums[dq.front()]);
    }
    // return list
    return ans;
}
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> Qi(k);
    vector<int> res;

    int i;
    for (i = 0; i < k; ++i)
    {

        while ((!Qi.empty()) && nums[i] >=
                                    nums[Qi.back()])

            Qi.pop_back();

        Qi.push_back(i);
    }

    for (i = k; i < nums.size(); ++i)
    {

        res.push_back(nums[Qi.front()]);

        while ((!Qi.empty()) && Qi.front() <=
                                    i - k)

            Qi.pop_front();

        while ((!Qi.empty()) && nums[i] >=
                                    nums[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }

    res.push_back(nums[Qi.front()]);
    return res;
}
void solution()
{
    int n;
    cin >> n;
    vector<int>min_arr(n);
    vector<int>max_arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>min_arr[i];
        cin>>max_arr[i];
    }
    int low = 0 ,high = n;
    int ans = 0;
    while(low<=high)
    {
        int mid  = (low+high)/2;
        bool flag = false;
        vector<int>mini = maxSlidingWindow(min_arr,mid);
        vector<int>maxi = getMinimums(max_arr,mid);
        for(int i = 0;i<maxi.size();i++)
        {
            if(maxi[i]-mini[i]+1 >=mid)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
           ans = mid;
           low = mid+1;
        }
        else
        high = mid-1;
        
    }
    cout<<ans<<endl;
}

int main()
{
    inout();
    // int TC = 1;
    // cin >> TC;
    // while (TC--)
    // {
    solution();
    // }

    return 0;
}

void inout()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}