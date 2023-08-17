#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//approach is simple 
// create an temp array and store {element ,index} in an array
// create one more array temp1 equal to temp;
// sort temp1 
// now convert it back to temp the swaps required for that is our ans
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
        //creating temp array
	   vector<pair<int,int>>v;
	   for(int i = 0;i<nums.size();i++)
	   {
	       v.push_back({nums[i],i});
	   }
       //creating one more array
	   vector<pair<int,int>>A = v;
	   sort(A.begin(),A.end());
	   int count = 0;
       //convert it back
	   for(int i = 0;i<A.size();i++)
	   {
	       if(i!=A[i].second)
	       {
	           swap(A[i],A[A[i].second]);
	           count++;
	           i--;
	       }
	   }
	   return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends