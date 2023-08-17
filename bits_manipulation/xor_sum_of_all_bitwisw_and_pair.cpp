#include <bits/stdc++.h>
using namespace std;
// Think about (a&b) ^ (a&c). Can you simplify this expression?
//   It is equal to a&(b^c). Then, (arr1[i]&arr2[0])^(arr1[i]&arr2[1]).. = arr1[i]&(arr2[0]^arr2[1]^arr[2]...).
//Let arr2XorSum = (arr2[0]^arr2[1]^arr2[2]...), arr1XorSum = (arr1[0]^arr1[1]^arr1[2]...) so the final answer is (arr2XorSum&arr1[0]) ^ (arr2XorSum&arr1[1]) ^ (arr2XorSum&arr1[2]) ^ ... = arr2XorSum & arr1XorSum.
int getXORSum(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int res = 0;
    int xor_sum = 0;
    for(int i = 0;i<m;i++)
    {
        xor_sum^=arr2[i];
    }
    for(int i = 0;i<n;i++)
    {
        res^= (arr1[i]&xor_sum);
    }
    return res;
}