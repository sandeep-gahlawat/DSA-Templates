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
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long cnt = 0;
    int i = 0;
    while(i<n-1)
    {
        if(i==n-2)
        {
            cnt+=arr[i];
            i++;
        }
        else
        {
            
            if(arr[i]!=0)
            {
                
                long long temp = arr[i];
                i++;
                long long cnt_0 = 0;
                while(i<n-1 && arr[i]==0)
                {
                    cnt_0++;
                    i++;
                }
                cnt+=temp+cnt_0;
            }
            else
            i++;
        }
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