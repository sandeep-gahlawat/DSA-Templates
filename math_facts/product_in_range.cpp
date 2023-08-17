#include <bits/stdc++.h>
using namespace std;

// fact = if we need only first n digit of any product=>
//       ans will be same if we multiply only n digits to that number
//    e.g = >  1234523273*3 = >3703569819 = >first five digit=>37035
//          => 12345*3=> 37035=> as we can see it is same
// same is valid from last also

// leetcode link:https://leetcode.com/contest/biweekly-contest-68/problems/abbreviating-the-product-of-a-range/
string abbreviateProduct(int left, int right)
{
    long long suff = 1, c = 0, max_suff = 100000000000;
    double pref = 1.0, max_pref = 10000;
    bool over = false;
    for (int i = left; i <= right; ++i)
    {
        pref *= i;
        suff *= i;
        while (pref >= 100000)
            pref /= 10;
        while (suff % 10 == 0)
        {
            suff /= 10;
            ++c;
        }
        if(suff>=max_suff)
        over = true;
        suff %= max_suff;
    }
    auto s = to_string(suff);
    return (!over ? s : to_string((int)pref) + "..." + s.substr(s.size() - 5)) + "e" + to_string(c);
}