#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/



//  Definition for a binary tree node.
 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int res = INT_MIN;
    int rec(TreeNode*root)
    {
        if(root==NULL)return 0;
        int ls = rec(root->left);
        int rs = rec(root->right);
        if(ls<0)//take positive sum from left subtree
        {
            ls = 0;
        }
        if(rs < 0)//take positive sum from right subtree
        {
            rs = 0;
        }
        int maxi = max(ls,rs);
        res = max(res,root->val+ls+rs);
        return root->val+maxi;
    }
    int maxPathSum(TreeNode* root) {
        rec(root);
        return res;
    }
};