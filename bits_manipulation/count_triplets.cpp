#include <bits/stdc++.h>
using namespace std;

//for better unserstanding read this : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/623747/JavaC%2B%2BPython-One-Pass-O(N4)-to-O(N)
// leetcode link:https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/submissions/

// Solution 2: Brute Force with prefix
// Calculate all prefix of bitwise-xor operation.
// prefix[0] = 0
// prefix[i] = A[0]^A[1]^...^A[i - 1]
// So that for each (i, j),
// we can get A[i]^A[i+1]^...^A[j] by prefix[j+1]^prefix[i]
// in O(1) time

// Time O(N^3)
// Space O(N)
// Space O(1) if changing the input


int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int>prefix(n);
        prefix[0] = arr[0];
        for(int i = 1;i<n;i++)
        {
          prefix[i] = arr[i]^prefix[i-1];
        }
        int res = 0;
        for(int i = 0;i<n-1;i++)
        {
          for(int j = i+1;j<n;j++)
          {
            for(int k = j;k<n;k++)
            {
              int val1;
              if(i-1>=0)
              val1 = prefix[j-1]^prefix[i-1];
              else
               val1 = prefix[j-1];
              int val2 = prefix[k]^prefix[j-1];
              if(val1==val2)
              {
                res++;
              }
            }
          }
        }
        return res;
    }



// Solution 3: Prefix XOR
// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

// Assume a == b, thus
// a ^ a = b ^ a, thus
// 0 = b ^ a, thus
// arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
// prefix[k+1] = prefix[i]

// We only need to find out how many pair (i, k) of prefix value are equal.
// So we can calculate the prefix array first,
// then brute force count the pair.

// Because we once we determine the pair (i,k),
// j can be any number that i < j <= k,
// so we need to plus k - i - 1 to the result res.

// Time O(N^2)
// Space O(N)
// Space O(1) if changing the input


 int countTriplets(vector<int>& A) {
        A.insert(A.begin(), 0);
        int n = A.size(), res = 0;
        for (int i = 1; i < n; ++i)
            A[i] ^= A[i - 1];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (A[i] == A[j])
                    res += j - i - 1;
        return res;
    }