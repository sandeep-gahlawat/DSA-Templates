#include <bits/stdc++.h>
using namespace std;
class trieNode
{
    public:
    bool isleaf;
    trieNode *child[26];
    trieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
class trie
{
public:
    trieNode *root;
    trie()
    {
        root = new trieNode();
    }
    void insert(string &key)
    {
        trieNode *curr = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = new trieNode();
            curr = curr->child[index];
        }
        curr->isleaf = true;
    }

    void addWord(string word)
    {
        insert(word);
    }
    // trie search with dfs
    bool dfs(int i,trieNode*curr,string&key)
    {
        if(i==key.length())
        {
            if(curr->isleaf)return true;
            return false;
        }
        for(int j = 0;j<26;j++)
        {
            if(curr->child[j]!=NULL && (j == key[i]-'a' || key[i]=='.'))
            {
                if(dfs(i+1,curr->child[j],key))return true;
            }
        }
        return false;
    }
    // simple trie search

    bool search(string& key)
    {
       trieNode*curr = root;
       for(int i = 0;i<key.length();i++)
       {
           int index = key[i]-'a';
           if(curr->child[index]==NULL)return false;
           curr = curr->child[index];
       }
       return curr->isleaf;
    }


    // Returns true if root has no child, else false
bool isEmpty(trieNode* root)
{
    for (int i = 0; i < 26; i++)
        if (root->child[i])
            return false;
    return true;
}
 
// Recursive function to delete a key from given Trie
trieNode* remove(trieNode* root, string key, int depth = 0)
{
    // If tree is empty
    if (!root)
        return NULL;
 
    // If last character of key is being processed
    if (depth == key.size()) {
 
        // This node is no more end of word after
        // removal of given key
        if (root->isleaf)
            root->isleaf = false;
 
        // If given is not prefix of any other word
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
 
    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    root->child[index] =
          remove(root->child[index], key, depth + 1);
 
    // If root does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->isleaf == false) {
        delete (root);
        root = NULL;
    }
 
    return root;
}
};