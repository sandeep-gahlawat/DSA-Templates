#include <bits/stdc++.h>
using namespace std;

//solution written by me
//solved using kadene algorithm
// Function to find maximum product subarray
long long maxProduct(vector<int> arr, int n)
{
    long long res = INT_MIN;
    if (n == 1)
        return arr[0];
    long long pos = 1, neg = 0;

    //kadane from starting
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            neg = 0;
            pos = 0;
            res = max(res, 0ll);
        }
        else if (arr[i] > 0)
        {

            if(neg>0)neg++;
            pos++;
            res = max(res, pos);
        }
        else
        {
            if (neg == 0)
            {
                neg = pos+1;
                pos = 0;
            }

            else
            {
                pos = neg +1;
                neg = neg+1;
            }

            res = max(res, neg);
            if (neg > 0)
                neg = 0;
        }
    }
    //kadene from ending
    pos = 0, neg = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            neg = 0;
            pos = 0;
            res = max(res, 0ll);
        }
        else if (arr[i] > 0)
        {

            if(neg>0)neg++;
            pos ++;
            res = max(res, pos);
        }
        else
        {
            if (neg == 0)
            {
                neg = pos +1;
                pos = 0;
            }

            else
            {
                pos = neg +1;
                neg = neg +1;
            }

            res = max(res, neg);
            if (neg > 0)
                neg = 0;
        }
    }
    return res;
}





//standard solution


// Function to find maximum product subarray
long long maxProduct(vector<int> arr, int n)
{
    // Variables to store maximum and minimum
    // product till ith index.
    long long minVal = arr[0];
    long long maxVal = arr[0];

    long long maxProduct = arr[0];

    for (int i = 1; i < n; i++)
    {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0)
            swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max((long long)arr[i], maxVal * arr[i]);
        minVal = min((long long)arr[i], minVal * arr[i]);

        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}