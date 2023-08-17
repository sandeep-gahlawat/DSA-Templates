#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node* bt_to_dll(Node*root,Node*prev)
{
   if(root==NULL)return root;
   Node*head = bt_to_dll(root->left,prev);
   if(prev==NULL)
   {
       head = root;
   }
   else
   {
       root->left = prev;
       prev->right = root;
   }
   prev = root;
   bt_to_dll(root->right,prev);
   return head;
}
