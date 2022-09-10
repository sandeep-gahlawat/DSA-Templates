#include <bits/stdc++.h>
using namespace std;
//leetcode link :https://leetcode.com/problems/insert-delete-getrandom-o1/
// we have to do all the insert delete getrandom in O(1) time
//  for this we can use vector and map together
//  map{key,value}=> key = actual value, value=>index in the array at that key is present
class RandomizedSet
{
public:
    unordered_map<int, int> m;
    int size = 0;
    vector<int> v;
    bool insert(int val)
    {
        if (m.count(val) != 0)
            return false;

        m[val] = size;
        v.push_back(val);
        size++;

        return true;
    }

    bool remove(int val)
    {
        if (m.count(val) == 0)
            return false;

        int idx = m[val];
        v[idx] = v[size - 1];
        v.pop_back();
        m[v[idx]] = idx;
        m.erase(val);
        size--;

        return true;
    }

    int getRandom()
    {
        return v[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */