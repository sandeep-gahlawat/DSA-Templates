#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//simple solution using levelorder traversal
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();

            if (t == NULL)
            {
                while (!q.empty())
                {
                    if (q.front() != NULL)
                        return false;
                    q.pop();
                }
                return true;
            }
            else
            {
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};