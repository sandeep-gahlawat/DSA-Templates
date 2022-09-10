#include<bits/stdc++.h>
using namespace std;

struct trieNode{
    trieNode*child[2];
    trieNode()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};
bool insert(trieNode*root,int row,vector<vector<int>>matrix)
{
    bool flag = false;
    trieNode*curr = root;
    for(int i = 0;i<matrix[0].size();i++)
    {
         int ind = matrix[row][i];
         if(curr->child[ind]==NULL)
         {
             flag = true;
             curr->child[ind] = new trieNode();
         }
         curr = curr->child[ind];
    }
    return flag;
}
int count_distinct_rows(vector<vector<int>>&matrix)
{
    int n = matrix.size();
    int res = 0;
    trieNode*root = new trieNode();
    for(int i = 0;i<n;i++)
    {
        if(insert(root,i,matrix))
        res++;
    }
    return res;
}