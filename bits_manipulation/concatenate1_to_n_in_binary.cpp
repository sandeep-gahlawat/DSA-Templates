#include<bits/stdc++.h>
using namespace std;

// 1680. Concatenation of Consecutive Binary Numbers
// Given an integer n, return the decimal value of the binary string formed
//  by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

#define mod 1000000007
class Solution {
public:
    int concatenatedBinary(int n) {
        long long val = 0;
        for(int i = 1;i<=n;i++)
        {
            //count number of bits in i
            int no_of_bits = (1+ log2(i));
            //left shift the value by no_of_bits and add i to it
            val = (((val<<((no_of_bits)%mod))%mod) + i)%mod;
        }
        return val;
    }
};