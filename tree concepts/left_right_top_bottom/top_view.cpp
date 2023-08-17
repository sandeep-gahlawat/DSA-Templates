#include <bits/stdc++.h>
using namespace std;

// Method 1: Using Map
// here, we store the vertical hight index of the node and check if the index already exists in the map that means we have seen a node above this node in the tree so we dont need this node in the Top view.
// else if the vh of the node is not in the map means this vertical level did not had any node so this node is the first node in this vetical level or coloumn so add it to map.
// all the nodes in the map are the nodes which are encountered first in the vertical traversal.

struct Node
{
    Node *left;
    Node *right;
    int data;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> v;

        vector<int> a;
        if (!root)
            return a;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (q.size())
        {
            Node *t = q.front().first;
            int vh = q.front().second;
            q.pop();

            // if this column index already has a
            // node we dont need to change it
            if (v[vh] == 0)
                v[vh] = t->data;

            if (t->left)
                q.push({t->left, vh - 1});
            if (t->right)
                q.push({t->right, vh + 1});
        }

        // all the nodes in the map are the nodes which are
        // encountered first in the verical traversal so  gives us the top view of the tree

        for (auto x : v)
            a.push_back(x.second);
        return a;
    }
};

// using recursion
void fillMap(Node *root, int d, int l,
             map<int, pair<int, int>> &m)
{
    if (root == NULL)
        return;

    if (m.count(d) == 0)
    {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l)
    {
        m[d] = make_pair(root->data, l);
    }

    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d +1,l+1,m);
}