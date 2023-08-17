
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<vector<long long>>& g, ll n, ll& k, vector<long long>& ans, ll& c) {
    if(g[n].size()==0) {
        if(k) {
            ans[n]=1;
            c++;
            k--;
        } else ans[n]=0;
        return;
    }
    ll x=0;
    for (auto &&i : g[n])
    {
        solve(g,i,k,ans,x);
    }

    if(x&1) {
        if(k) {
            ans[n]=0;
            k--;
        } else {
            ans[n]=1;
            x++;
        }
    } else {
        if(k) {
            ans[n]=1;
            k--;
            x++;
        } else {
            ans[n]=0;
        }
    }
    c+=x;
}

void inout()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

