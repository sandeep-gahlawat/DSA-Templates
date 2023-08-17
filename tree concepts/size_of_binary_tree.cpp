#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node*left,*right;
};

int getsize(Node*root)
{
  if(root==NULL)return 0;
  return 1+getsize(root->left)+getsize(root->right);
}