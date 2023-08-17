#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> ans;
    bool ispalindrome(string &str)
    {
        int low = 0, high = str.length() - 1;
        while (low <= high)
        {
            if (str[low] != str[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    //  we will partion when we get palindrome str
    void generate(string str, string s, vector<string> res, int n, int index)
    {
        if (index == n)
        {
            ans.push_back(res);
            return;
        }
        for (int i = index; i < n; i++)
        {
            str.push_back(s[i]);
            if (ispalindrome(str))
            {
                res.push_back(str);
                generate("", s, res, n, i + 1);
                //backtracking step
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        generate("", s, {}, s.length(), 0);
        return ans;
    }
};