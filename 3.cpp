// Given a BST (Binary Search Tree), find the shortest range [x, y],
// such that, at least one node of every level of the BST lies in the range.
// If there are multiple ranges with the same gap (i.e. (y-x))
// return the range with the smallest x.

// hint
//  Use two pointer technique in inorder traversal of the tree.
//   Set left pointer at first index and right pointer at root's index
//    in inorder traversal of the bst.
//     Then check if the current range contains all levels
//     if yes the shift left pointer 1 index right,
//      otherwise increase the right pointer by 1.
//       Continue this process till left pointer reaches the root's index
//       or right pointer reaches last index.

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<vector<int>> levelorder(Node *root, int &mini, int &maxi)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v;
        while (size--)
        {
            Node *curr = q.front();
            q.pop();
            v.push_back(curr->data);
            maxi = max(maxi, curr->data);
            mini = min(mini, curr->data);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        res.push_back(v);
    }
    return res;
}
bool present(vector<vector<int>> &ans, int low, int high)
{

    for (auto &x : ans)
    {
        int index = lower_bound(x.begin(), x.end(), low) - x.begin();
        if (index >= x.size())
            return false;
        if (x[index] > high)
            return false;
    }
    return true;
}

void inorder(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
int total_nodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + total_nodes(root->left) + total_nodes(root->right);
}
pair<int, int> shortestRange(Node *root)
{
    int mini = INT_MAX, maxi = 0;
    vector<vector<int>> ans = levelorder(root, mini, maxi);
    vector<int> res;
    inorder(root, res);
    // index of root
    int root_index = total_nodes(root->left);
    int i = 0, j = root_index;
    int x = res[0], y = res.back();
    while (i <= root_index && j < res.size())
    {
        if (present(ans, res[i], res[j]))
        {
            if ((res[j] - res[i]) < (x - y))
            {
                x = res[i];
                y = res[j];
            }
            i++;
        }
        else
        {
            j++;
        }
    }
    return {x, y};
}
