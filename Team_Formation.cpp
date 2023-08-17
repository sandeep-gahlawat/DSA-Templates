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
    string s,t;
    cin>>s>>t;
    int count_of_both = 0,none = 0,programming = 0,english = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i]=='1' && t[i]=='1')
        {
            count_of_both++;
        }
        else if(s[i]=='0' && t[i]=='0')
        {
            none++;
        }
        else if(s[i]=='1')
        programming++;
        else
        english++;
    }
    int teams = 0;
    if(none<=count_of_both)
    {
        teams+=none;
        count_of_both-=none;
    }
    else{
        teams+=count_of_both;
        count_of_both = 0;
    }
    if(programming<=english)
    {
        teams+=programming;
        english-=programming;
        teams+= min(count_of_both,english);
        if(count_of_both>english)
        {
            teams+= (count_of_both-english)/2;
        }
    }
    else
    {
        teams+=english;
        programming-=english;
        teams+=min(count_of_both,programming);
        if(count_of_both>programming)
        {
            teams+= (count_of_both-programming)/2;
        }
    }
    cout<<teams<<endl;
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