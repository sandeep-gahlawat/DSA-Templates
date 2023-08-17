#include<bits/stdc++.h>
using namespace std;

//leetcode link:https://leetcode.com/problems/satisfiability-of-equality-equations/

class DSU
{
public:
    int *parent;
    int *rank;
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];
        for (int i = 0; i < v; i++)
        {
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
            return x;

        // concept of path compression used here
        parent[x] = find(parent[x]);

        return parent[x];
    }
    // Function to merge two nodes a and b.
    void union_(int a, int b)
    {
        int rep_x = find(a);
        int rep_y = find(b);
        if (rep_x == rep_y)
            return;
        else if (rank[rep_x] < rank[rep_y])
            parent[rep_x] = rep_y;
        else if (rank[rep_y] < rank[rep_x])
            parent[rep_y] = rep_x;
        else
        {
            parent[rep_x] = rep_y;
            rank[rep_y]++;
        }
    }

   
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU* dsu = new DSU(26);
        for(auto &x:equations)
        {
            if(x[1]=='=')
            {
                dsu->union_(x[0]-'a',x[3]-'a');
            }
        }
        for(auto &x:equations)
        {
            if(x[1]=='!')
            {
                if(dsu->find(x[0]-'a')==dsu->find(x[3]-'a'))return false;
            }
        }
        return true;
    }
};