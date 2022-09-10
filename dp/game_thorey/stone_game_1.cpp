#include<bits/stdc++.h>
using namespace std;
  
// leetcode link:https://leetcode.com/problems/stone-game/
 bool stoneGame(vector<int>& piles) {

       int n = piles.size();
       int sum = 0;
       for(int i = 0;i<n;i++)sum+=piles[i];
       vector<vector<int>>dp(n,vector<int>(n));
       for(int gap = 0;gap<n;gap++)
       {
           for(int i = 0,j  = gap;j<n;j++,i++)
           {
               // if there is only single item then we will choose that item
               if(gap==0)
               {
                   dp[i][j] = piles[j];
               }
               // if there is only two item then  we will choose maximum from it
               else if(gap==1){
                   dp[i][j]  = max(piles[i],piles[j]);
               }
               else
               {
                   // when we select from (i,j) =>i=> then opponent can choose
                   // from (i+1,j)=> if opponent choose i+1 then we get =>(i+2,j)
                   // but if he choose j then we get (i+1,j-1);
                   // he also choose optimaly
                   // so we get minimum from it
                   int val1 = piles[i] + min(dp[i+2][j],dp[i+1][j-1]);

                   // but if i choose j from (i,j)
                   // then we make cases like above
                   int val2 = piles[j] + min(dp[i][j-2],dp[i+1][j-1]);

                   // after that we will take maximum piles that we can take
                   dp[i][j] = max(val1,val2);
               }
           }
       } 
       return dp[0][n-1]>(sum/2);
    }