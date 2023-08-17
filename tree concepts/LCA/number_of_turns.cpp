#include<bits/stdc++.h>
using namespace std;
//gfg link:https://practice.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1
struct Node {
    struct Node* left, *right;
    int data;
};

class Solution
{
public:

//finds the lca of both the nodes
    Node *lca(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;
        if (root->data == n1 || root->data == n2)
            return root;
        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);
        if (left && right)
            return root;
        else if (left != NULL)
            return left;
        else
            return right;
    }
//path from given node to given node
    bool lca_to_point(Node *LCA, int n, string &str)
    {
        if (LCA == NULL)
            return false;
        if (LCA->data == n)
        {
            return true;
        }
        str.push_back('L');
        if (lca_to_point(LCA->left, n, str))
            return true;

        str.pop_back();
        str.push_back('R');
        if (lca_to_point(LCA->right, n, str))
            return true;

        str.pop_back();
        return false;
    }

    // function should return the number of turns required to go from first node to second node
    int NumberOFTurns(struct Node *root, int first, int second)
    {
        Node *LCA = lca(root, first, second);
        string start = "", end = "";
        lca_to_point(LCA, first, start);
        lca_to_point(LCA, second, end);
        reverse(start.begin(),start.end());
        string res = start+end;
        int cnt = 0;
        for(int i = 1;i<res.length();i++)
        {
            if(res[i]!=res[i-1])
            cnt++;
        }
        
        return cnt;
    }
};