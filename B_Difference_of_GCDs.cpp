#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
#define ll long long
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
    ll n,l,r;
    cin>>n>>l>>r;
    vector<int>arr;
    for(int i = 0;i<n;i++)
    {
        if(i==0)
        {
            arr.push_back(l);
        }
        else if(l+((i+1)-(l%(i+1)))<=r)
        {
            arr.push_back(l+((i+1)-(l%(i+1))));
        }
        else if(r-(r%(i+1))>=l)
        {
            arr.push_back(r-(r%(i+1)));
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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