#include<bits/stdc++.h>
using namespace std;
class TimeMap {
public:
   unordered_map<string,map<int,string>>map1;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map1[key][timestamp] = value;

    }
    
    string get(string key, int timestamp) {
        
        auto it = map1[key].upper_bound(timestamp);
        if(it == map1[key].begin() || map1[key].size()==0)
        return "";
        auto timestamp = prev(it)->second;
        


        return map1[key][timestamp];
    }
};
