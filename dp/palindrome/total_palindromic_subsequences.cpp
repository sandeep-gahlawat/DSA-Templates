#include <bits/stdc++.h>
using namespace std;
//count total palindromic subsequences

// The above problem can be recursively defined. 

// Initial Values : i= 0, j= n-1;

// CountPS(i,j)
// // Every single character of a string is a palindrome 
// // subsequence 
// if i == j
//    return 1 // palindrome of length 1

// // If first and last characters are same, then we 
// // consider it as palindrome subsequence and check
// // for the rest subsequence (i+1, j), (i, j-1)
// Else if (str[i] == str[j])
//    return   countPS(i+1, j) + countPS(i, j-1) + 1;

// else
//    // check for rest sub-sequence and  remove common
//    // palindromic subsequences as they are counted
//    // twice when we do countPS(i+1, j) + countPS(i,j-1)
//    return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1)



//using memoization


int n, dp[1000][1000];


// Function return the total
// palindromic subsequence
int countPS(int i, int j,string &str,vector<vector<long long>>&dp)
{

	if (i > j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (i == j)
		return dp[i][j] = 1;

	else if (str[i] == str[j])
		return dp[i][j]
			= countPS(i + 1, j,str,dp) +
				countPS(i, j - 1,str,dp) + 1;

	else
		return dp[i][j] = countPS(i + 1, j,str,dp) +
						countPS(i, j - 1,str,dp) -
						countPS(i + 1, j - 1,str,dp);
}


