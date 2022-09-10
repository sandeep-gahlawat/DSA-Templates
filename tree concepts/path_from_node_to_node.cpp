#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool path_from_node_to_node(TreeNode *root, int n, string &str)
{
    if (root == NULL)
        return false;
    if (root->val == n)
    {
        return true;
    }
    str.push_back('L');
    if (path_from_node_to_node(root->left, n, str))
        return true;

    str.pop_back();
    str.push_back('R');
    if (path_from_node_to_node(root->right, n, str))
        return true;

    str.pop_back();
    return false;
}