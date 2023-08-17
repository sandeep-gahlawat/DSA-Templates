#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int expo(int a, int b, int mod){
    int ans = 1;
    while(b){
        if(b&1)
            ans = (ans * 1LL * a)%mod;
        a = (a * 1LL * a)%mod;
        b >>= 1;
    }
    return ans;
}
const int N=500005;
int f[N], inv[N];
void preprocess()
{
    f[0] = 1;
    for(int i = 1; i < N; i++)
        f[i] = (i* 1LL *f[i-1])%M;
    inv[N-1] = expo(f[N-1],M-2,M);
    for(int i = N-2; i >= 0; i--)
        inv[i] = ((i+1) * 1LL * inv[i+1])%M;
}
int C(int n,int r){
	if(r>n)
		return 0;
    return (((f[n] * 1LL * inv[r])%M) * 1LL * inv[n-r])%M;
}
int solve(vector<int> &A) {
    preprocess();
    map<int,int>m;
    for(auto i:A)
        m[i]++;
    vector<int>v;
    for(auto i:m)
        v.push_back(i.second);
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=1;i<=v.back();i++){
        int res = 1;
        for(auto it=lower_bound(v.begin(),v.end(),i); it != v.end(); it++)
            res=(res * 1LL * (1+C(*it,i)))%M;
        ans=(ans+res-1)%M;
    }
    return ans;
}
