#include <bits/stdc++.h>
using namespace std;

// 2157. Groups of Strinstring_with_given_hash
// leetcode link:https://leetcode.com/problems/groups-of-strinstring_with_given_hash/

// method 1 using dfs and bitmasking
//   it is given in the question that every word have unique charaters
//       so we can generate bitmask of every string
//       a=>00000000000000000000000001
//      b=>00000000000000000000000010 like this way
//      and we can run simple dfs(applying all the three given steps that we can insert one character ,delete,replace)
//      so we got how many groups possible

unordered_map<int, int> mp;

int hash_value(string &word)
{
    int h = 0;
    for (char c : word)
        h |= 1 << c - 'a';
    return h;
}

int dfs(const int h)
{
    // if hash is not present
    if (mp.find(h) == mp.end())
        return 0;
    int string_with_given_hash = mp[h];
    // we have included it into group so it should be deleted (bacuse it can not be included again)
    mp.erase(h);

    // all possible delete and add edits
    for (int b = 0; b < 26; ++b)
    {
        int h1;
        if ((h >> b) & 1) // delete
            h1 = h ^ (1 << b);
        else // add
            h1 = h | (1 << b);
        auto it = mp.find(h1);
        if (it != mp.end())
            string_with_given_hash += dfs(h1);
    }
    // for possible 26*26 replacements
    for (int b1 = 0; b1 < 26; ++b1)
    {
        if (((h >> b1) & 1) == 0)
            continue;
        // make this bit 0
        int h1 = h ^ (1 << b1);
        for (int b2 = 0; b2 < 26; ++b2)
        {
            if (b2 != b1 && !((h >> b2) & 1))
            {
                int h2 = h1 | (1 << b2);
                auto it = mp.find(h2);
                if (it != mp.end())
                    string_with_given_hash += dfs(h2);
            }
        }
    }
    return string_with_given_hash;
}

vector<int> groupStrinstring_with_given_hash(vector<string> &words)
{
    // bit masking
    int n = words.size(), no_of_groups = 0, maxg = 0;
    // all the hashes are stored in the map
    for (int i = 0; i < n; ++i)
        ++mp[hash_value(words[i])];
    // run dfs on them and form groups
    for (int i = 0; i < n; ++i)
    {
        const int h = hash_value(words[i]);
        int string_with_given_hash = dfs(h);
        if (string_with_given_hash > 0)
            no_of_groups += 1;
        maxg = max(maxg, string_with_given_hash);
    }
    return {no_of_groups, maxg};
}

// method 2 using dsu + bitmasking

class DSU
{
public:
    int *parent;
    int *rank;
    int no_of_groups;
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];
        no_of_groups = v;
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
        int x = find(a);
        int y = find(b);
        if (x == y)
            return;
        if (rank[x] >= rank[y])
        {
            parent[y] = x;
            rank[x] += rank[y];
        }
        else
        {
            parent[x] = y;
            rank[y] += rank[x];
        }
        no_of_groups--;
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
    int getSizeOfLargestGrp(int n)
    {
        int mx = 1;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, rank[i]);
        }
        return mx;
    }
};

class Solution
{
public:
    int hash_value(string &word)
    {
        int h = 0;
        for (char c : word)
            h |= (1 << (c - 'a'));
        return h;
    }
    vector<int> groupStrings(vector<string> &words)
    {
        int n = words.size();
        unordered_map<int, int> mp;
        DSU *dsu = new DSU(n);
        for (int i = 0; i < n; i++)
        {
            int hvalue = hash_value(words[i]);
            mp[hvalue] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int hvalue = hash_value(words[i]);
            for (int j = 0; j < 26; j++)
            {
                // if j'th bit is set
                if (((hvalue) & (1 << j)))
                {
                    int del = hvalue ^ (1 << j);
                    if (mp.find(del) != mp.end())
                    {
                        dsu->union_(i, mp[del]);
                    }
                    // replace some character with j character
                    for (int k = 0; k < 26; k++)
                    {
                        int replace = del | (1 << k);
                        if (replace != del && mp.count(replace))
                        {
                            dsu->union_(i, mp[replace]);
                        }
                    }
                }
                else // if j'th is not set then we can perform add operation here
                {
                    int add = hvalue | (1 << j);
                    if (mp.find(add) != mp.end())
                    {
                        dsu->union_(i, mp[add]);
                    }
                }
            }
            mp[hvalue] = i;
        }


        return {dsu->no_of_groups, dsu->getSizeOfLargestGrp(n)};
    }
};