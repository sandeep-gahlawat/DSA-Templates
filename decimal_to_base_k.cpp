#include<bits/stdc++.h>
using namespace std;
string to_base_k(int n,int k)
{
    string str= "";
    while(n>0)
    {
        int r = n%k;
        // if k lies between 1 to 10
        str.push_back('0'+r);
        // else we reperentation like hexadecimal
        // 10->a,11->b,12->c like that
        n/=k;
    }
    reverse(str.begin(),str.end());
    return str;
}