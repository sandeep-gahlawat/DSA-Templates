#include <bits/stdc++.h>
using namespace std;

// 1-> count total palingromic substrings in a string


int countSubstrings(string s)
{
    int n = s.length();
    int count = 0;
    bool dp[n + 1][n + 1];
    // diagonal traversal dp;
    for (int gap = 0; gap < n; gap++)
    {
        // every diangnol start from first row and end at last column
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                // substring of length is always palindrome
                dp[i][j] = true;
                count++;
            }
            else if (gap == 1)
            {
                // substring of length 2 =>if there extreme characters are equal
                //   then it is palindrome
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                    count++;
                }
                else
                    dp[i][j] = false;
            }
            else
            {
                // substring length is greater than 2=>
                // extreme character are equal and inner part is palindrome =>
                // then the substring is palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                    count++;
                }
                else
                    dp[i][j] = false;
            }
        }
    }
    return count;
}

// 2->longest palindromic substring
string longestPalindrome(string s)
{

    int n = s.length();
    bool dp[n + 1][n + 1];
    int start_index = 0,end_index = 0;
    // diagonal traversal dp;
    for (int gap = 0; gap < n; gap++)
    {
        // every diangnol start from first row and end at last column
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                // substring of length is always palindrome
                dp[i][j] = true;
                
            }
            else if (gap == 1)
            {
                // substring of length 2 =>if there extreme characters are equal
                //   then it is palindrome
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                    start_index = i;
                    end_index = j;
                }
                else
                    dp[i][j] = false;
            }
            else
            {
                // substring length is greater than 2=>
                // extreme character are equal and inner part is palindrome =>
                // then the substring is palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                    start_index = i;
                    end_index = j;
                }
                else
                    dp[i][j] = false;
            }
        }
    }
    return s.substr(start_index,end_index-start_index+1);
}