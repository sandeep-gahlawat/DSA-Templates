#include <bits/stdc++.h>
using namespace std;

// bitmasking in string
//  'a' =>1,'b'=>2, 'c' =>4, 'd' =>8 ....so on
// eg "abc" and "bac","cab","cba","bca"=>it means permuntation same hash_value

// finding hash_set value for any string
string s = "abcd";
int hashvalue(string s)
{
    int hash_value = 0;
    for (int i = 0; i < s.length(); i++)
    {
        hash_value += (1 << (s[i] - 'a'));
    }
    return hash_value;
}

// practice problem
// https://leetcode.com/contest/weekly-contest-275/problems/count-words-obtained-after-adding-a-letter/