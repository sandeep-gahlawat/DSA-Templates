#include<bits/stdc++.h>
using namespace std;


// tc  = o(n^3);


bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        for(auto x:wordDict)
            set.insert(x);
        int n = s.length();
        // dp[i] stores word from(0 to i) is present or not
        vector< int>dp(n,0);
        for(int i = 0;i<n;i++)
        {
            //generating all the suffix of a string till i
            for(int j = 0;j<=i;j++)
            {
                string w2check = s.substr(j,i-j+1);
                // if it is present in hashset
                if(set.find(w2check)!=set.end())
                {
                    if(j>0)
                    {
                        // if earlier part for this is also present then we say it is present
                        if(dp[j-1]>0)
                            dp[i] = 1;
                    }
                    //if full part is present from(o to i)
                    else
                        dp[i] = 1;
                }
                
            }
            cout<<endl;
        }
        // for(int i = 0;i<n;i++)
        //     cout<<dp[i]<<" ";
        return dp[n-1]>0;
    }



    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        for(auto x:wordDict)
            set.insert(x);
        int n = s.length();
        // dp[i] stores number of word possible till i;
        vector< int>dp(n,0);
        for(int i = 0;i<n;i++)
        {
            //generating all the suffix of a string till i
            for(int j = 0;j<=i;j++)
            {
                string w2check = s.substr(j,i-j+1);
              
                if(set.find(w2check)!=set.end())
                {
                     // if earlier part for this is also present then we say it is present
                     
                    if(j>0)
                    {
                        if(dp[j-1]>0)
                            dp[i] += dp[j-1];
                    }
                    else
                        dp[i] += 1;
                }
                
            }
            cout<<endl;
        }
        // for(int i = 0;i<n;i++)
        //     cout<<dp[i]<<" ";
        return dp[n-1]>0;
    }