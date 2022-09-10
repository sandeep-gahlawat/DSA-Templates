#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    int *parent;
    int *rank;
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];
        for (int i = 0; i < v; i++)
        {
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
            return x;

        // concept of path compression used here
        parent[x] = find(parent[x]);

        return parent[x];
    }
    // Function to merge two nodes a and b.
    void union_(int a, int b)
    {
        int rep_x = find(a);
        int rep_y = find(b);
        if (rep_x == rep_y)
            return;
        else if (rank[rep_x] < rank[rep_y])
            parent[rep_x] = rep_y;
        else if (rank[rep_y] < rank[rep_x])
            parent[rep_y] = rep_x;
        else
        {
            parent[rep_y] = rep_x;
            rank[rep_x]++;
        }
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y)
    {
        if (find(x) == find(y))
            return true;
        return false;
    }
    // Function to determine number of connected components.(like number of islands)
    int findNumberOfConnectedComponents(int n)
    {
        unordered_set<int> set;
        for (int i = 0; i < n; i++)
        {
            set.insert(find(i));
        }
        return set.size();
    }
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> node(n, 0);

        for (int i = 0; i < n; i++)
        {

            if (leftChild[i] != -1)
            {
                node[leftChild[i]]++;
                if (node[leftChild[i]] > 1)
                    return false; // keep count of node if come more then 1 time
            }                     // like in any order traversal one node should come only one time

            if (rightChild[i] != -1)
            {
                node[rightChild[i]]++;
                if (node[rightChild[i]] > 1)
                    return false; // similarly with this
            }
        }
        DSU *dsu = new DSU(n);
        for (int i = 0; i < n; i++)
        {
            // it  will run for condition like 0<->1(both of them are parent of each other this can't be true for binary tree)
            if (dsu->parent[i] == leftChild[i])
            {

                return false;
            }
            if (leftChild[i] != -1)
            {

                dsu->union_(i, leftChild[i]);
            }
            if (dsu->parent[i] == rightChild[i])
            {

                return false;
            }
            if (rightChild[i] != -1)
            {

                dsu->union_(i, rightChild[i]);
            }
        }

        int x = dsu->findNumberOfConnectedComponents(n);
        return x <= 1;
    }
};
