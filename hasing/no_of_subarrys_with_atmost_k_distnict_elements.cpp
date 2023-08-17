#include<bits/stdc++.h>
using namespace std;

int no_of_subarrays_with_atmost_k_distinict_elements(vector<int>&arr,int k)
{
    int n= arr.size();
    int res = 0;
    unordered_map<int,int>mp;
    int low = 0;
    for(int i = 0;i<n;i++)
    {
        mp[arr[i]]++;
        if(mp.size()<=k)
        {
            res += i-low+1;
            
        }
        else
        {
            while(true)
            {
                mp[arr[low]]--;
                if(mp[arr[low]]==0)
                {
                    mp.erase(arr[low]);
                    low++;
                    res += i-low+1;
                    break;
                }
            }
        }
    }
    return res;
}