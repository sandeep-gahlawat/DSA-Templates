#include <bits/stdc++.h>
using namespace std;
struct person
{

    int first;
    int second;
    int t;
};
bool cmp(person &a, person &b)
{
    return a.t <= b.t;
}
vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
{
    int m = meetings.size();
    person arr[m];
    for (int i = 0; i < m; i++)
    {

        arr[i].first = meetings[i][0];
        arr[i].second = meetings[i][1];
        arr[i].t = meetings[i][2];
    }
    sort(arr, arr + n, cmp);
    unordered_set<int> present, res;
    present.insert(0);
    present.insert(firstPerson);
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (1)
        {
            if (j < n)
            {
                if (arr[i].t == arr[j].t)
                    j++;
                else
                    break;
            }
        }
        bool flag;
        for (int k = i; k < j; k++)
        {
            if (present.find(arr[k].first) != present.end())
            {
                flag = true;
                break;
            }
            else if (present.find(arr[k].second) != present.end())
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            for (int k = i; k < j; k++)
            {
                res.insert(arr[k].first);
                 res.insert(arr[k].second);
            }
        }
        i = j;
       
    }
    vector<int>ans;
    for(auto x: res)
    {
        ans.push_back(x);

    }
    return ans;
}