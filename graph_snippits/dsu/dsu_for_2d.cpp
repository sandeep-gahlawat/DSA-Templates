#include<bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<vector<pair<int, int>>> parent;
    vector<vector<int>> rank;
    DSU(int n, int m)
    {
        parent = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));
        rank = vector<vector<int>>(n, vector<int>(m, 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                parent[i][j] = {i, j};
            }
        }
    }

    pair<int, int> find(int x, int y)
    {
        pair<int, int> a = {x, y};
        if (a == parent[x][y])
            return a;

        // concept of path compression used here
        parent[x][y] = find(parent[x][y].first, parent[x][y].second);

        return parent[x][y];
    }
    // Function to merge two nodes a and b.
    void union_(pair<int, int> a, pair<int, int> b)
    {
        pair<int, int> rep_x = find(a.first, a.second);
        pair<int, int> rep_y = find(b.first, b.second);
        if (rep_x == rep_y)
            return;
        else if (rank[rep_x.first][rep_x.second] < rank[rep_y.first][rep_y.second])
            parent[rep_x.first][rep_x.second] = rep_y;
        else if (rank[rep_y.first][rep_y.second] < rank[rep_x.first][rep_x.second])
            parent[rep_y.first][rep_y.second] = rep_x;
        else
        {
            parent[rep_x.first][rep_x.second] = rep_y;
            rank[rep_y.first][rep_y.second]++;
        }
    }
};



//problem 
//You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size k.

//Input: n = 4
// m = 5
// k = 4
// A = {{1,1},{0,1},{3,3},{3,4}}

// Output: 1 1 2 2
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  00000
//     01000
//     00000
//     00000
// 2.  01000
//     01000
//     00000
//     00000
// 3.  01000
//     01000
//     00000
//     00010
// 4.  01000
//     01000
//     00000
//     00011


class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        DSU mat(n,m);
        vector<vector<int>>arr(n,vector<int>(m,0));
        vector<int>ans;
        int cnt = 0;
        for(auto &x:operators)
        {
            int i = x[0];
            int j = x[1];
            if(arr[i][j]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            cnt++;
            set<pair<int,int>>st;
            if(i-1>=0  && arr[i-1][j]==1)
            {
                st.insert(mat.find(i-1,j));
                mat.union_({i,j},{i-1,j});
            }
            if(j-1>=0 && arr[i][j-1]==1)
            {
                 st.insert(mat.find(i,j-1));
                mat.union_({i,j},{i,j-1});
            }
            if(i+1<n && arr[i+1][j]==1)
            {
                st.insert(mat.find(i+1,j));
                mat.union_({i,j},{i+1,j});
            }
            if(j+1<m && arr[i][j+1]==1)
            {
                st.insert(mat.find(i,j+1));
                mat.union_({i,j},{i,j+1});
            }
            arr[i][j] = 1;
            cnt-=st.size();
            ans.push_back(cnt);
            
            
        }
        return ans;
    }
};