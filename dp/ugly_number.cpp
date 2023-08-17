#include <bits/stdc++.h>
using namespace std;

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.

int nthUglyNumber(int n)
{
    vector<int> dp(n + 1);
    dp[1] = 1;
    // we will take mutiples of 2,3,5 =>we will take those multiple only which does
    // not contain another prime fractor from 2,3,5 =>and this is we are storing in
    // in our dp array

    // dp = 1,2,3,4,5,6,8,9,10,12,15,16,18 ......
    // so i have created pointer for all the limited prime numbers(2,3,5)
    // which are intially pointing to the first ugly number
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(2 * dp[p2], min(3 * dp[p3], 5 * dp[p5]));
        // if the multiple of any of this number is the current value
        // then increment it's pointer to get next mutliple of it (that can be part of next ugly number)
        if (2 * dp[p2] == dp[i])
            p2++;
        if (3 * dp[p3] == dp[i])
            p3++;
        if (5 * dp[p5] == dp[i])
            p5++;
    }
    return dp[n];
}
//slighter harder version of this problem is it will give array of prime factors 
// like arr = {2,5,7,13} =>for these prime factors we have to find nth number
// same approah but in this we have to create array of pointers and follow same process



// An ugly number is a positive integer that is divisible by a, b, or c.
// Given four integers n, a, b, and c, return the nth ugly number.

// in this there is no constrant like limiting factors we can take any factor of these elements
// like a,2a,3a,4a,5a,....
//     b,2b,3b,4b,5b,....
//     c,2c,3c,4c,5c,....
// like this there are three AP'S we have to find n'th smallest number from these ap elements
// so we merge them(but time limit exiced for this)
// so we thing to optimze more =>binary search
// so we find nth element of min(a,min(b,c)) (that is the limiting value) ans can not be greater than this

long long lcm(long long a, long long b)
{
    return ((a * b) / __gcd(a, b));
}
int nthUglyNumber(int n, int a, int b, int c)
{
    long long int ans;
    long long int low = min(a, (b, c)), high = n * 1ll * min(a, min(b, c));
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        // finding elements less than or equal to mid in all there series
        // formula for elements less then equal to x in any ap is=>
        //      a+(n-1)d = x :: d=>a;
        //      na = x => n = x/a;
        // also remember that we have to substract common elements
        long long int count = mid / a + mid / b + mid / c - mid / lcm(a, b) - mid / lcm(b, c) - mid / lcm(a, c) + mid / lcm(a, lcm(b, c));
        if (count > n)
            high = mid - 1;
        else if (count == n)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}