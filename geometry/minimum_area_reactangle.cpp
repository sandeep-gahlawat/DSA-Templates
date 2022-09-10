#include<bits/stdc++.h>
using namespace std;

// leetcode link : https://leetcode.com/problems/minimum-area-rectangle/submissions/
int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>>store;
        // all points inserted into the map
        for(auto&x:points)
        {
            store[x[0]].insert(x[1]);
        }
        int minimum_area = INT_MAX;
        for(int i = 0;i<points.size();i++)
        {
            for(int j = i+1;j<points.size();j++)
            {

                int x1 = points[i][0],y1 = points[i][1];
                int x2 = points[j][0],y2 = points[j][1];
                
                if(x1!=x2 && y1!=y2)
                {
                    // then this should diagnnal elements to form a rectangle
                    // if left two elements (x1,y2) and(x2,y1)are present in store
                    //   then our reactangle is complete
                    if(store[x1].find(y2)!=store[x1].end() && store[x2].find(y1)!=store[x2].end())
                    {
                       minimum_area = min(minimum_area,abs(x1-x2)*abs(y1-y2));
                    }
                }
            }
        }
        return minimum_area == INT_MAX?0:minimum_area;
    }