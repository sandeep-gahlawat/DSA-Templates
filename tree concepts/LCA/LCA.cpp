#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *lca(TreeNode *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->val == n1 || root->val == n2)
        return root;
    TreeNode *left = lca(root->left, n1, n2);
    TreeNode *right = lca(root->right, n1, n2);
    if (left && right)
        return root;
    else if (left != NULL)
        return left;
    else
        return right;
}