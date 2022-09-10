#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// leetcode question link ->https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
class Solution
{
public:
    
    pair<int,TreeNode*>depth_with_node(TreeNode*root,int depth)
    {
        if(root==NULL)return {depth-1,NULL};
        pair<int,TreeNode*>left = depth_with_node(root->left,depth+1);
        pair<int,TreeNode*>right = depth_with_node(root->right,depth+1);
        if(left.first==right.first)
        {
            return {left.first,root};
        }
        else if(left.first>right.first)
        {
            return left;
        }
        else
        return right;
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        pair<int,TreeNode*>res = depth_with_node(root,0);
        return res.second;
    }
};