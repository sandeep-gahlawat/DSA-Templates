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

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
int i = 0;
TreeNode *Tree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &m, int start, int end)
{
    if (start > end)
        return NULL;
    TreeNode *root = new TreeNode(preorder[i++]);

    int index = m[root->val];
    root->left = Tree(preorder, inorder, m, start, index - 1);
    root->right = Tree(preorder, inorder, m, index + 1, end);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> m;
    // i = 0;
    for (int i = 0; i < inorder.size(); i++)
        m[inorder[i]] = i;
    return Tree(preorder, inorder, m, 0, preorder.size() - 1);
}
int main()
{
    vector<int> preorder = {8, 2, 9, 6, 4, 1, 3, 7, 5, 10};
    vector<int> inorder = {9, 2, 4, 6, 8, 7,3,1, 5, 10};
    
    postorder(buildTree(preorder, inorder));
}