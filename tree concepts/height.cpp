#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node*left,*right;
};

int height(Node*root)
{
  if(root==NULL)return 0;
  return max(height(root->left),height(root->right))+1;
}