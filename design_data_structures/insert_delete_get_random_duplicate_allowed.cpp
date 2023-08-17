#include <bits/stdc++.h>
using namespace std;

// we use similiar as we dicuss in question with duplicate
// in this question duplicate values are allowed
// so how we tackle ths?
// we can use unordered_map<int,unordered_set<int>>
// key stores actual value and set stores indexes of it in the array

class RandomizedCollection
{
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mp;
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        bool flag = false;
        // val is not present
        if (mp[val].size() == 0)
            flag = true;
        int sz = arr.size();
        mp[val].insert(sz);
        arr.push_back(val);
        return flag;
    }

    bool remove(int val)
    {
        bool flag = false;
        // if val is present
        if (mp[val].size() > 0)
            flag = true;
        else // if val is not present
            return flag;
        int index = *mp[val].begin();
        mp[val].erase(index);
        arr[index] = arr.back();
        int sz = arr.size();
        mp[arr.back()].insert(index);
        mp[arr.back()].erase(sz - 1);
        arr.pop_back();
        return flag;
    }

    int getRandom()
    {
        return arr[rand() % (arr.size())];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */