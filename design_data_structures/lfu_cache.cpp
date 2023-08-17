#include<bits/stdc++.h>
using namespace std;

//leetcode link:https://leetcode.com/problems/lfu-cache/description/

class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> keyVal;//{key =>{val,freq}}
    unordered_map<int,list<int>> freqList;//{freq => {list of keys}}
    unordered_map<int,list<int>::iterator> pos;//{key => {pos of key in list}}
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyVal.find(key) == keyVal.end())
            return -1;
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();
        if(freqList[minFreq].empty())
            minFreq++;
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return;
        if(keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();
            if(freqList[minFreq].empty())
                minFreq++;
            return;
        }
        if(keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */