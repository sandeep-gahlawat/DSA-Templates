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

void solution()
{
    int n;
    cin>>n;
    vector<long long>arr(n);
    unordered_map<long long,long long>mp;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    long long cnt = 0;
    for(auto &x:mp)
    {
        if(x.second==1)
        {
            cnt++;
        }
    }
    if(cnt==1)
    {
        long long mini = INT_MAX;
        long long maxi = 0;
        long long val ;
        
        for(auto &x:mp)
        {
            maxi = max(maxi,x.first);
            if(x.second!=1)
            {
                 mini = min(mini,x.second);
            }
            if(x.second==1)
            {
                val = x.first;
            }
        }
        if(val == maxi)
        cout<<2<<endl;
        else
        cout<<1<<endl;
        return;
    }
    cout<<cnt/2 + cnt%2<<endl;
    
    
    
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