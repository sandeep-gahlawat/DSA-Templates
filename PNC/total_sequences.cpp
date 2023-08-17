#include <bits/stdc++.h>
using namespace std;

//leetcode link:https://leetcode.com/problems/letter-tile-possibilities/
class Solution
{
public:
    int fact[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
    unordered_set<string> st;
    // number of permentations possible of a given string
    //     If we have a string of size n with i unique characters, and each character repeats m[i] times, the number of unique permutations is:
    // n! / (m[1]! * m[2]! * .. * m[i]!)
    int uniquePerms(string &s)
    {
        int cnt[26] = {};
        for (auto ch : s)
            ++cnt[ch - 'A'];
        auto res = fact[s.size()];
        for (auto n : cnt)
            res /= fact[n];
        return res;
    }

    //generate all the possible sequences 
    int dfs(string &s, string seq = "", int pos = 0)
    {
        if (pos >= s.size())
        {
            //let's understand st.insert().second =>when we insert val in set it return pair<iterator,bool> in this bool specify whether inserted or not if inserted then bool is true else bool if false.so it is shortcut to check either it is inserted or not
            return st.insert(seq).second ? uniquePerms(seq) : 0;
        }
        return dfs(s, seq, pos + 1) + dfs(s, seq + s[pos], pos + 1);
    }
    int numTilePossibilities(string tiles)
    {
        sort(begin(tiles), end(tiles));
        return dfs(tiles) - 1;
    }
};