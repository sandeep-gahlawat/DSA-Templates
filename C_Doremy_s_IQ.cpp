#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
#define ll int
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
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
bool check(ll q,vector<ll>&arr,ll pos)
{
    ll n = arr.size();
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<=q)
        {
            continue;
        }
        else if(i>=pos && q>0)
        {
            q--;
        }
        else if(i>pos && q==0)
        {
           return false;
        }
    }
    return true;
}
void solution()
{
    ll n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

   ll low = 0,high = n;
   ll pos;
   while(low<=high)
   {
       ll mid = (low+high)/2;
       if(check(q,arr,mid))
       {
          pos = mid;
          high = mid-1;
       }
       else
       low = mid+1;
   }
   string res = "";
   for(int i = 0;i<n;i++)
   {
       if(arr[i]<=q)
       {
           res.push_back('1');
       }
       else if(i>=pos)
       {
           res.push_back('1');
       }
       else
       res.push_back('0');
   }
   cout<<res<<endl;

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