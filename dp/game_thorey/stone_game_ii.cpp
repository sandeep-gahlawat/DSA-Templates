#include <bits/stdc++.h>
using namespace std;


// leetcode link:https://leetcode.com/problems/stone-game-ii/

// approach is that we find the difference of points between alice and bob
//  both play optimily
// alice => alice in his turn try to collect maximum points
// bob => bob also tries to collect maximum in his turn=>tries alice will get less coins

class Solution
{
public:
   // soved using memoization
    int difference_in_points(vector<int> &piles, int index, int n,int m, vector<vector<int>> &dp)
    {
        // after this no one will get any coin
        if (index >= n)
            return 0;
         // if it is already calculated(memoization step);
        if (dp[index][m] != -1)
            return dp[index][m];

        int stones = 0;
        int ans = INT_MIN;
        // can take piles from index to index + 2*m
        // make all cases such that if he take all the piles from index to i;
        for (int i = index; i < min(n, (index + 2*m)); i++)
        {
            
            stones += piles[i];
            // m will change it is mentioned in the question
            ans = max(ans, stones - difference_in_points(piles, i + 1, n,max(m,i-index+1), dp));
        }
        dp[index][m] = ans;
        return ans;
    }

    int stoneGameII(vector<int> &piles)
    {
        int sum = 0;
        for(int i = 0;i<piles.size();i++)
        {
           sum+= piles[i];
        }
        vector<vector<int>>dp(101,vector<int>(101,-1));
        int diff = difference_in_points(piles,0,piles.size(),1,dp);
        // alice_points + bob_points = sum
        // alice_points - bob_points = diff
        // alice_points = (sum+diff)/2;
        return (sum+diff)/2;
    }
};