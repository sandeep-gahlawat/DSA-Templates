#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
#define ll long long
#define bin(n) std::bitset<32>(n).to_string()
void solution()
{
       int a,b;
        cin>>a>>b;
        int array[a];
        set<pair<int,int>,greater<pair<int,int>>> p,q;
        vector<int> y(a+1,a);
        for(int i=0;i<b;i++)
        {
            int c,d;
            cin>>c>>d;
            if(y[c]>d)
            {
                y[c]=d;
            }
        }
        for(int i=1;i<=a;i++)
        {
            p.insert({y[i],i});
            int uji=-1;
        }
        for(int i=a-1;i>=0;i--)
        {
            
            while(!p.empty()&&p.begin()->first==i+1)
            {
                int v=p.begin()->second;
                p.erase(p.begin());
                q.insert({v,y[v]});
            }
            if(q.empty())
            {
                cout<<-1<<endl;
                return;
            }
            int v=q.begin()->first;
            q.erase(q.begin());
            array[i]=v;
        }
        for(int i=0;i<a;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
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

