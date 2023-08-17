
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

//problem link : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


class Solution 
{
    public:
    bool static cmp(Job a, Job b)
    {
        return (a.dead<b.dead);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int t =0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0;i<n;i++)
        {
            Job x = arr[i];
            if(x.dead>t)
            {
                pq.push(x.profit);
                t++;
            }
            else if(x.dead==t)//we have to pop one if we want to take it
            {
                if(!pq.empty() && pq.top()<x.profit)
                {
                    pq.pop();
                    pq.push(x.profit);
                }
            }
        }
        int ans = 0;
        int cnt = pq.size();
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return {cnt, ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends