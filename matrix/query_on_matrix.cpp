#include <bits/stdc++.h>
using namespace std;


//You are given a matrix of dimension n*n. All the cells are initially, zero. You are given Q queries, which contains 4 integers a b c d where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix. Now, all the cells of this submatrix have to be incremented by one. After all the Q queries have been performed. Your task is to find the final resulting Matrix.
// Note : Zero-Based Indexing is used for cells of the matrix. 
//problem link : https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1


class Solution
{
public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries)
    {
        vector<vector<int>> matrix(n , vector<int>(n , 0));
       
        for (auto i : Queries)
        {
            int a = i[0];
            int b = i[1];
            int c = i[2];
            int d = i[3];
            for(int j = a;j<=c;j++)
            {
                //increment 1 in all colums b from row a=>c
                matrix[j][b]++;
                //decrement 1 in all colums that are not a part of query in row from a=>c
                if(d+1<n)
                matrix[j][d+1]--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if(j!=0)
                {
                    matrix[i][j]+=matrix[i][j-1];
                }
            }
        }
        return matrix;
    }
};