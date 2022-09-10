#include<bits/stdc++.h>
using namespace std;

// A parentheses string is a non-empty string consisting only of '(' and ')'. 
// It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), 
// where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given a parentheses string s and a string locked, both of length n.
//  locked is a binary string consisting only of '0's and '1's.
//   For each index i of locked,

// If locked[i] is '1', you cannot change s[i].
// But if locked[i] is '0', you can change s[i] to either '(' or ')'.
// Return true if you can make s a valid parentheses string.
//  Otherwise, return false.


// approach => 
 bool canBeValid(string s, string locked) {
        if (s.size() & 1) return false; 
        for (int i = 0, bal = 0; i < s.size(); ++i) {
            if (locked[i] == '0' || s[i] == '(') bal += 1; 
            else bal -= 1; 
            if (bal < 0) return false; 
        }
        // it will be required for cases like "()((",[0,0,1,1]
        for (int i = s.size()-1, bal = 0; 0 <= i; --i) {
            if (locked[i] == '0' || s[i] == ')') bal += 1; 
            else bal -= 1; 
            if (bal < 0) return false; 
        }
        return true; 
    }