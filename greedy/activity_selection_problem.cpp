// C++ program for activity selection problem
// when input activities may not be sorted.
#include <bits/stdc++.h>
using namespace std;

// A job has a start time, finish time and profit.
struct Activitiy
{
	int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time
bool activityCompare(Activitiy s1, Activitiy s2)
{
	return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can
// be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr+n, activityCompare);

	cout << "Following activities are selected n";

	// The first activity always gets selected
	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

	// Consider rest of the activities
	for (int j = 1; j < n; j++)
	{
	// If this activity has start time greater than or
	// equal to the finish time of previously selected
	// activity, then select it
	if (arr[j].start >= arr[i].finish)
	{
		cout << "(" << arr[j].start << ", "
			<< arr[j].finish << "), ";
		i = j;
	}
	}
}

// Driver program
int main()
{
	Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
									{5, 7}, {8, 9}};
	int n = sizeof(arr)/sizeof(arr[0]);
	printMaxActivities(arr, n);
	return 0;
}



//variations problem
// You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. 

//  bool static comp(val fst,val sec){
//         return fst.second<sec.second;
//     }
    
//     int maxChainLen(struct val p[],int n){
//         sort(p,p+n,comp);
//         int ans=0;

//         int prev=-1e9;
//         for(int i=0;i<n;i++){
//             if(p[i].first>prev){
//                 prev=p[i].second;
//                 ans++;
//             }
//         }
//         return ans;
//     }