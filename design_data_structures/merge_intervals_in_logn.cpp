#include <bits/stdc++.h>
using namespace std;
//this problem is similar to merge an interval in array of intervals =>this problem is sovled using simple linear approach by traversing
//optimization of this problem is done using map =>interval can be inserted in  it in logn time
class CountIntervals
{
public:
    map<int, int> interval;
    int cnt = 0;
    CountIntervals()
    {
    }
   //function add an interval [left,right] into the intervals
    void add(int left, int right)
    {
        if (interval.size() == 0)
        {
            interval[left] = right;
            cnt += right - left + 1;
            return;
        }
        auto lt = interval.upper_bound(left);
        auto rt = interval.upper_bound(right);
        if (lt == interval.begin() && rt == interval.begin())
        {
            interval[left] = right;
            cnt += right - left + 1;
            return;
        }

        if (lt != interval.begin())
        {
            if (prev(lt)->second >= left)
                lt--;
        }

        rt--;
        if(lt!=interval.end())
        left = min(lt->first, left);
        right = max(rt->second, right);
        rt++;
        vector<int>arr;
        for (auto  x = lt; x != rt; x++)
        {
            cnt -= (x->second - x->first) + 1;
            arr.push_back(x->first);
            
        }
        for(auto x:arr)
            interval.erase(x);
            
        cnt += right - left + 1;
        interval[left] = right;
    }

    int count()
    {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */