#include<bits/stdc++.h>
using namespace std;
//leetcode link: https://leetcode.com/problems/allocate-mailboxes/


//approach is that we select k intervals from the array and in each interval we place mailbox at median interval index;




class Solution {
public:
    
    //Cost Function of installing one mailbox in given interval.
    
    int get_cost(vector<int>& houses , int& start , int& end){
        //this function finds median of interval [start,end]
        int length = end - start + 1;
        int median = 0;
        //if length is even
        if(length & 1 == 0){
            int index = start + (end - start)/2;
            median = (houses[index] + houses[index + 1])/2;
        } else {//if odd element are prent
            int index = start + (end - start)/2;
            median = houses[index];
        }
        //place the mailbox at median index and distances from that
        int costing = 0;
        for(int i = start ; i <= end ; ++i){
            costing += abs(houses[i] - median);
        }
        return costing;
    }
    
    //Generalised solution for k mailboxes in array intervals.
    
    long long memoize(vector<int>& houses , int start , int count , vector<vector<long long>>& dp){
        if(count == 0 && start == houses.size()){
            return 0;
        }
        if(count==0 && start<houses.size())
        {
            return INT_MAX;
        }
            
        
        if(dp[start][count] != -1){
            return dp[start][count];
        }
        
        long long answer = INT_MAX , temp = 0;
        
        for(int counter = start ; counter < houses.size() ; counter++){
                //selected an interval from {start index to counter index}
                temp = get_cost(houses , start , counter);
                answer = min(answer , temp + memoize(houses, counter + 1 , count - 1 , dp));
            
        }
        return dp[start][count] = answer;
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin() , houses.end());
        if(k == houses.size()){
            return 0;
        }
        
        int n = houses.size();
        
        vector<vector<long long>> dp(n + 1 , vector<long long>(k + 1 , -1));
        
        return memoize(houses , 0 , k , dp);
    }
};