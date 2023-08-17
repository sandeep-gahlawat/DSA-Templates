#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> preorderTraversal(Node *root)
{
    Node *curr = root;
    stack<Node *> st;
    vector<int> res;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            // cout<<curr->data<<" ";
            res.push_back(curr->data);
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
    return res;
}