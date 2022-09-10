#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        // storing a set to make searching faster
        unordered_set<string> words;
        for (auto &word : wordList)
            words.insert(word);

        vector<vector<string>> res;

        // this set is created to check this is already visited or not
        unordered_set<string> visited;

        // stores all paths
        queue<vector<string>> q;
        q.push(vector<string>{beginWord});
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                vector<string> cur = q.front();
                q.pop();

                visited.insert(cur.back());

                // if last node in vector is target node then this path is completed
                if (cur.back() == endWord)
                {
                    res.push_back(cur);
                    continue;
                }

                // else we have to move forward
                string nex = cur.back();
                // changing every charcter with the characters between (a to z)
                for (auto &c : nex)
                {
                    char pre = c;
                    for (char i = 'a'; i <= 'z'; i++)
                    {
                        c = i;
                        // after changing checking this node is present in the set and also either
                        // it should be target node or should not be visited =>then this will be present in the path
                        if (words.find(nex) != words.end() && (nex == endWord || visited.find(nex) == visited.end()))
                        {
                            cur.push_back(nex);
                            q.push(cur);
                            cur.pop_back();
                        }
                        c = pre;
                    }
                }
            }
            if (!res.empty())
                return res;
        }
        return res;
    
    }
};