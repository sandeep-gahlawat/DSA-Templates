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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string str = "";
    for (int i = 0; i < m; i++)
    {
        str.push_back('B');
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i]-1 < m && str[arr[i]-1] == 'A')
        {
            if (m - arr[i]+1 + 1 >= 0)
            {
                str[m - arr[i]+1 + 1] = 'A';
            }
        }
        else if (arr[m - arr[i]+1 + 1] == 'A')
        {
            str[arr[i]] = 'A';
        }
        else
        {
            if (arr[i]-1 <= m - arr[i]+1 + 1)
            {
                str[arr[i]-1] = 'A';
            }
            else
            {
                str[m - arr[i]+1 + 1] = 'A';
            }
        }
    }
    cout << str << endl;
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