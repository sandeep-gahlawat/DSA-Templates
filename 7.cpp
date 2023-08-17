#include <bits/stdc++.h>
using namespace std;

bool check(int n,int x)
{
    n-=2*x;
    if(n/2>x)
    return true;
    return false;
    
}
int unequal(int n)
{
    if(n%2!=0)return 0;
    long long low = 0,high = n;
    int ans = 0;
    while(low<=high)
    {
        long long mid = (low+high)/2;
        if(check(n,mid))
        {
            ans = mid;
            low = mid+1;
        }
        else
        high  = mid-1;

    }
    return ans;
}
int main()
{
    cout<<unequal(6)<<endl;
}