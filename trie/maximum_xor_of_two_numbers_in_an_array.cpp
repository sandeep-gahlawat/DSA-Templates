#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *left;
    Node*right;
};

class Solution {
public:
    void insert(Node*root,int val)
    {
        Node*curr = root;
        for(int i = 31;i>=0;i--)
        {
            int bit = (val>>i)&1;
            if(bit==0)
            {
                if(curr->left==NULL)
                    curr->left = new Node();
                curr = curr->left;
            }
            else
            {
                if(curr->right==NULL)
                    curr->right = new Node();
                curr = curr->right;
            }
                
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        Node*root = new Node();
        //first insert all the numbers
        for(int i =  0;i<nums.size();i++)
        {
            insert(root,nums[i]);
        }

        int max_xor = 0;
        for(int i = 0;i<nums.size();i++)
        {
            Node*curr = root;
            int curr_xor = 0;
            //now we will move opposite side because xor of different bit is one
            for(int j = 31;j>=0;j--)
            {
                int bit = (nums[i]>>j)&1;
                if(bit==0)
                {
                   if(curr->right) 
                   {
                        curr = curr->right;
                       curr_xor+= pow(2,j);
                   }
                    else
                        curr = curr->left;
                      
                }
                else
                {
                     if(curr->left) 
                   {
                        curr = curr->left;
                       curr_xor+= pow(2,j);
                   }
                    else
                        curr = curr->right;
                }
            }
            max_xor = max(max_xor,curr_xor);
        }
        return max_xor;
    }
};