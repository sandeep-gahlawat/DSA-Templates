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
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i = 1;i<n;i++)
    {
        if(arr[i]<arr[i-1] )
        {
            cout<<"NO"<<endl;
            return;
        }
        else if((arr[i]-arr[i-1])%arr[i-1]!=0 )
        {
            cout<<"NO"<<endl;
            return;
        }
        else
        {
            arr[i] = arr[i-1];
        }
        
    }
    cout<<"YES"<<endl;
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