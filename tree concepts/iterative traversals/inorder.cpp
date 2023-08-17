#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left,*right;
};

void iterativeinorder(Node*root)
{
    stack<Node*>st;
    Node*curr = root;
    while(curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}