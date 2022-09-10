#include <bits/stdc++.h>
using namespace std;

//leetcode link:https://leetcode.com/contest/weekly-contest-278/problems/find-substring-with-given-hash-value/

// The hash of a 0-indexed string s of length k, given integers p and m, is computed using the following function:

// hash(s, p, m) = (val(s[0]) * p0 + val(s[1]) * p1 + ... + val(s[k-1]) * pk-1) mod m.
// Where val(s[i]) represents the index of s[i] in the alphabet from val('a') = 1 to val('z') = 26.

// You are given a string s and the integers power, modulo, k, and hashValue.
//  Return sub, the first substring of s of length k such that hash(sub, power, modulo) == hashValue.

// The test cases will be generated such that an answer always exists.

// A substring is a contiguous non-empty sequence of characters within a string

// we can solve this question in brute force O(n*k)
//   but we have solve this question in O(n)
//   for this we have to slides of window k
//    if we take from starting then we have divide all the values with power
//     (if power is prime then we can do this using the concept of mudulo inverse)
//      but here power is not prime
//     so we solve it from backward (beacuse we can easily multiply with power under mudulo)
//       like this solve it from sliding window from backward
class Solution
{
public:
    string subStrHash(string s, int p, int m, int k, int hashValue)
    {
        long long cur = 0, res = 0, pk = 1, n = s.size();
        for (int i = n - 1; i >= 0; --i)
        {
            // adding element
            cur = (cur * p + (s[i] - 'a' + 1)) % m;
            if (i + k >= n)
                pk = pk * p % m;
            else // removing one element if size of window exceeds
                cur = (cur - (s[i + k] - 'a' + 1) * pk % m + m) % m;
            if (cur == hashValue)
                res = i;
        }
        return s.substr(res, k);
    }
};