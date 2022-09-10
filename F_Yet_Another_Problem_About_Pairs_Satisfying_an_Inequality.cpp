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
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
long long countSmaller(vector<pair<int , int>>& nums) {
    long long res = 0 ;
    pbds ms ;
    int n = nums.size();
    for(int i = 0 ; i < n ; i++){
        ms.insert(nums[i].second);
        long long x = ms.order_of_key(nums[i].first);
        res += x;
    }
    return res;
}
void solution()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a < i)
        {
            v.push_back({a, i});
        }
    }

    cout << countSmaller(v) << endl;
}

int main()
{
    inout();
    int TC = 1;
    cin >> TC;
    while (TC--)
    {
        solution();
    }

    return 0;
}

void inout()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}