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
    vector<int>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x,y;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==1)
        {
            x = i;
            break;
        }
        // else if(arr[i]==n)
        // {
        //     y = i;
        // }
    }
   int cnt = 0;
    while(arr[0]!=1)
    {
        swap(arr[x-1],arr[x]);
        cnt++;
        x--;
    }
    for(int i = 0;i<n;i++)
    {
        
         if(arr[i]==n)
        {
            y = i;
            break;
        }
    }
    while(arr[n-1]!=n)
    {
        swap(arr[y],arr[y+1]);
        cnt++;
        y++;
    }
    cout<<cnt<<endl;
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