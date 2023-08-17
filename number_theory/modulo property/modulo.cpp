// You are given a 0-indexed string word of length n consisting of digits,
//  and a positive integer m.

// The divisibility array div of word is an integer array of length n such that:

// div[i] = 1 if the numeric value of word[0,...,i] is divisible by m, or
// div[i] = 0 otherwise.
// Return the divisibility array of word.
//leetcode link : https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int  n = word.size();
        vector<int>res(n,0);
        long long mod = 0;
        for(int i = 0;i<n;i++)
        {
            //take the modulo till previous index * 10 + (element at index i) = modulo till index i
            mod = mod*10+(word[i]-'0');
            mod = mod%m;
            if(mod==0)
            res[i] = 1;
        }
        return res;
    }
};