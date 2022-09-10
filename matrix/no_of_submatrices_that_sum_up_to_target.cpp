#include<bits/stdc++.h>
using namespace std;
//leetcode link: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //prifix sum for every row
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<m;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }

        int cnt = 0;//stores no_of_submatrices with sum==target

        //fixing two columns and corressponding to them running for every row
        for(int c1 = 0;c1<m;c1++)
        {
            for(int c2 = c1;c2<m;c2++)
            {
                //mp stores frequency of specific sum
                unordered_map<int,int>mp;
                int sum  = 0;//sum denotes sum of c1 to c2 till row
                //using concept of numbers of subarray with sum k
                for(int row = 0;row<n;row++)
                {
                   sum+= matrix[row][c2];
                   if(c1>0)
                   {
                       sum-=matrix[row][c1-1];
                   }
                    if(sum==target)
                    {
                        cnt++;
                    }
                   if(mp.find(sum-target)!=mp.end())
                   {
                       cnt+=mp[sum-target];
                   }
                   mp[sum]++;
                }
            }
        }
        return cnt;
    }
};