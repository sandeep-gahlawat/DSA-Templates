#include <bits/stdc++.h>
using namespace std;

int overlap(vector<vector<string>> v)
{

    int ans = 0;
    int count = 0;
    vector<pair<string, char>> time;

    for (int i = 0; i < v.size(); i++)
    {

        time.push_back({v[i][0], 'x'});
        time.push_back({v[i][1], 'y'});
    }

    sort(time.begin(), time.end());

    for (int i = 0; i < time.size(); i++)
    {


        if (time[i].second == 'x')
            count++;


        if (time[i].second == 'y')
            count--;

        ans = max(ans, count);
    }

   
    return ans;
}

int solve(int N, vector<vector<string>> R)
{
    return overlap(R);
}

int main()
{
   vector<vector<string>>R = {{"04:02:31","06:03:32"},{"05:48:11","06:12:13"},{"06:45:36","11:51:58"},{"09:12:00","12:34:29"},{"04:15:55","07:11:48"}};
   cout<<solve(4,R)<<endl;
}