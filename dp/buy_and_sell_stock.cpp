#include <bits/stdc++.h>
using namespace std;

// for every stock either we buy or sell=>we can sell only when when we have a stock
// we can have only one stock at a time first we have to sell then we can buy again
// so there will be two state either we buy or we sell
// let's say initailly we have zero money
// think like a account
// so first we buy a stock (loan ho gaye ga -arr[0]) or dont'buy or don't sell
// from next move we have both the choices
// if we buy a stock from sold state(in with we don't have any stock)=>
//   so we check we are getting any profit or not
//     loan kam se kam rakhe ge
//          //buying from sold state
// if(oss-prices[i]>obs)
// {
//     obs = oss-prices[i];
// }
//   ya fhir => we sell the stock from the bought state(in which we have stock to sell)
//       so we check we are getting any profit or not
//        selling from bought state
//            if(obs+ prices[i]-fee > oss)
//              oss = obs+ prices[i]-fee;
// after whole process we return money that we have in sold state

// we are making both the cases at every level profit in bought state  profit in sold state
int maxProfit(vector<int> &prices, int fee)
{
    int obs = -prices[0], oss = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        // buying from sold state
        if (oss - prices[i] > obs)
        {
            obs = oss - prices[i];
        }

        // selling from bought state
        if (obs + prices[i] - fee > oss)
            oss = obs + prices[i] - fee;
    }
    return oss;
}

// if we have to wait 1 day after selling a stock
// so there will be three state (bought state) (sold state) (cool down state)
// we can buy from cool state only because we have to wait or cool for one
//              day after sold sate
//  we can sell from bought sate because in bought state we have a share to sell
// we come in cool state from sold state beacuse we wait after selling the stock

int maxProfit(vector<int> &prices)
{
    // obs = old bought state
    // oss = old sold state;
    // ocs = old cold state
    int obs = -prices[0], oss = 0, ocs = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        // going in buying state
        if (ocs - prices[i] > obs)
            obs = ocs - prices[i];

        // going into cool state(we are updating it first
        //  because we compare with previous old sold state)
        if (oss > ocs)
            ocs = oss;

        // going into sold state
        if (obs + prices[i] > oss)
            oss = obs + prices[i];
    }
    return oss;
}



// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously
//  (i.e., you must sell the stock before you buy again).


// => we can olny do two transactions
// so there is a day on which traction performed before it or that day only
//     and one transaction performed after that day
// so we find maximum profit till every i'th day by doing only one transactions from
// starting 
// ans also we find max_profit from back(condition => we buy on that day or after that day)
// so by doing this we got to know that max_profit of traction performed before i'yh day
// and max_profit of transaction performed after i'th day=>so max of maximium profit of
// every i'th day is our answer

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // sold stores max_profit before i'th day
        // buy stores max_profit after i'th day
        vector<int>sold(n),buy(n);
        sold[0] = 0;
        int mini = prices[0];
        int max_profit = 0;
        //finding max_profit befor i'th day
        for(int i = 1;i<n;i++)
        {
            mini = min(mini,prices[i]);
            max_profit = max(max_profit,prices[i]-mini);
           
            sold[i] = max_profit;
        }
        //finding max_profit after ith'day
        buy[n-1] = 0;
        int maxi = prices[n-1];
        max_profit = 0;
        for(int i = n-2;i>=0;i--)
        {
            maxi = max(maxi,prices[i]);
            max_profit = max(max_profit,maxi-prices[i]);
            
            buy[i] = max_profit;
        }
        max_profit = 0;
        // finding max_profit
        for(int i = 0;i<n;i++)
        {
            max_profit = max(max_profit,sold[i]+buy[i]);
        }
        return max_profit;
        
    }




//  You are given an integer array prices where prices[i] is the price of a given stock
//   on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most k transactions.
// Note: You may not engage in multiple transactions simultaneously
//  (i.e., you must sell the stock before you buy again).


// dp[i][j] stores max_profit till j'th day by performing i tractions
int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[k+1][n+1];
        for(int i = 0;i<=k;i++)
        {
            for(int j = 0;j<=n;j++)
            {
                // if we perforn 0 transactions then we get zero profit
                // also on 0'th day we can't get any profit
                if(i==0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    int maxi = 0;
                    for(int l = 0;l<j;l++)
                    {
                        maxi = max(maxi,dp[i-1][l] + prices[j-1]-prices[l]);
                    }
                    dp[i][j] = max(dp[i][j-1],maxi);
                }
            }
        }
        return dp[k][n];
    }