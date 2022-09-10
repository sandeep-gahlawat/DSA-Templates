

// method 1 =>use simple level order traversal => tc = O(n),sc = O(w);

// method 2
//  we count left height and right height if it is equal it means all the level after this
//  level are completely filled and count of nodes = pow(2,left_height) -1;
//  otherwise we will count for left _subtree and right_subtree seperately and the
//  count is 1+ count_of_left_subtree + count_of_right_subtree
// tc = O(logn * logn)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int countNode(Node *root)
{
    int lh = 0, rh = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if (lh == rh)
    {
        return pow(2, lh) - 1;
    }
    else
    {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << countNode(root);
}