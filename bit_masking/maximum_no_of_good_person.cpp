#include <bits/stdc++.h>
using namespace std;
// leetcode link : https://leetcode.com/problems/maximum-good-people-based-on-statements/
// time complexity is exponential O(2^n * n*n)
class Solution
{
public:
    int check_valid(string s, vector<vector<int>> &statements, int n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // if i'th bad consider him bad then there is no meaning for
            // to check it's statements
            if (s[i] == '0')
                continue;
            // but if him consider himself good then there should be no contradiction in all the statements
            cnt++;
            for (int j = 0; j < n; j++)
            {
                // if satement is saying it is good and assumption showing it is bad
                //  then it is a contradiction
                if (statements[i][j] == 1 && s[j] == '0')
                    return 0;
                // if statement is saying bad and assumption saying it is good
                if (statements[i][j] == 0 && s[j] == '1')
                    return 0;
            }
        }
        return cnt;
    }
    // simple recursion generating all the combination and simply checking them
    int generate(int index, string s, vector<vector<int>> &statements, int n)
    {
        if (index == n)
        {
            int x = check_valid(s, statements, n);
            return x;
        }
        // make all cases
        // consider i'th is bad
        int bad = generate(index + 1, s + '0', statements, n);
        // consider i'th person as good
        int good = generate(index + 1, s + '1', statements, n);
        // we need maximum no matter i'th person is good or bad
        return max(good, bad);
    }
    int maximumGood(vector<vector<int>> &statements)
    {
        // we can say we assume ecah person as good and bad and generate all
        // combinations and check which is valid one (not contradicting to the given statements)
        // e.g n = 3
        // 0 reperent that i'th person is bad and 1 ans good
        // 000
        // 001
        // 010
        // 100
        // 011
        // 101
        // 110
        /// 111
        // these combinations are possible for n = 3=> for these we will check which
        // one is valid combination and consider that have maximun one's(good people)
        return generate(0,"",statements,statements.size());
    }
};