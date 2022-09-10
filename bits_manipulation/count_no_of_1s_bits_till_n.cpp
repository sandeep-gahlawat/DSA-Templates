#include <bits/stdc++.h>
using namespace std;

//leetcode link:https://leetcode.com/problems/counting-bits/



class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num);
        res.push_back(0); // for num=0
        if (num == 0)
            return res;

        for (int i = 1; i <= num; i++)
        {
            //if number is even then it have one's bits equal to half of that number
            if (i % 2 == 0)
            {
                res[i] = res[i / 2];
            }
            //if number is odd
            else
            {
                res[i] = res[i - 1] + 1;
            }
        }
        return res;
    }
};