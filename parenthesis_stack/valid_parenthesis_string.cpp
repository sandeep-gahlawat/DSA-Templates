#include <bits/stdc++.h>
using namespace std;

//leetcode link : https://leetcode.com/problems/valid-parenthesis-string/
// Given a string s containing only three types of characters: '(', ')' and '*',
//  return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or
//  a single left parenthesis '(' or an empty string "".


// so we have to check cases like
//   1-> *( =>an open bracket can not be matched by * that is before the open bracket
//   2>(*()=>an close bracket can be matched with open bracket and * that comes before closing bracket


bool checkValidString(string s) {
        int n = s.length();
        // open stack store indexes of opening bracket
        stack<int>open;
        // cache stack store indexes of *
        stack<int>cache;
        for(int i = 0;i<n;i++)
        {
           if(s[i]=='(')
           {
              open.push(i);
           }
           // ')'=>we have to pop one element 
           else if(s[i]==')')
           {
              if(!open.empty())
              open.pop();
              else if(!cache.empty())
              cache.pop();
              else
              return false;
           }
           else
           cache.push(i);
        }
        // in last if opening bracket left that are not balanced by closing
        // bracket we will try to balance with *
        // remenber * index should be greater than "(" index
        while(!open.empty())
        {
           int x = open.top();
           if(cache.empty())return false;
           else if(cache.top()<x)return false;
           cache.pop();
           open.pop();
        }
        return true;
    }