#include<bits/stdc++.h>
using namespace std;

//here we need to find( fact[10^2]/(fact[100]*fact[10000]))%p like this so we need to use the concept of mudulo inverse


//leetcode link:https://leetcode.com/contest/biweekly-contest-94/problems/count-anagrams/


long long mod = 1e9 + 7;
class Solution
{
public:
// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
//using fermit's litle thoerem
// If we know m is prime, then we can also use Fermat’s little theorem to find the inverse.

//         am-1 ≡ 1 (mod m) 
// If we multiply both sides with a-1, we get

//         a-1 ≡ a m-2 (mod m) 
// void modInverse(int a, int m)
// {
//     if (__gcd(a, m) != 1)
//         cout << "Inverse doesn't exist";
 
//     else {
 
//         // If a and m are relatively prime, then
//         // modulo inverse is a^(m-2) mode m
//         cout << "Modular multiplicative inverse is "
//              << power(a, m - 2, m);
//     }
// }
 
    int modInverse(int A, int M)
    {
        int m0 = M;
        int y = 0, x = 1;

        if (M == 1)
            return 0;

        while (A > 1)
        {
            // q is quotient
            int q = A / M;
            int t = M;

            // m is remainder now, process same as
            // Euclid's algo
            M = A % M, A = t;
            t = y;

            // Update y and x
            y = x - q * y;
            x = t;
        }

        // Make x positive
        if (x < 0)
            x += m0;

        return x;
    }
    int countAnagrams(string s)
    {
        int n = s.length();

        vector<long long> fact(n + 1);
        fact[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            fact[i] = fact[i - 1] * (long long)i;
            fact[i] %= mod;
        }

        //here we have derived the modulo inverse of factorials
        vector<long long>inv(n+1);
        inv[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            inv[i] =  (inv[i-1]*modInverse(i,mod))%mod;
        }
        long long ans = 1;
        map<char,int>mp;
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            if(s[i]==' ')
            {
                ans = (ans*fact[cnt])%mod;
                for(auto &x:mp)
                {
                    if(x.second>1)
                    ans = (ans*inv[x.second])%mod;
                }
                mp.clear();
                cnt = 0;
                
            }
            else
            {
                cnt++;
                mp[s[i]]++;
            }
        }
         ans = (ans*fact[cnt])%mod;
                for(auto &x:mp)
                {
                    if(x.second>1)
                    ans = (ans*inv[x.second])%mod;
                }
        return ans;
    }
};