#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
#define ll long long
#define bin(n) std::bitset<32>(n).to_string()

void inout();
void SieveOfEratosthenes(vector<bool> &prime)
{

    int n = prime.size();
    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
string lcs(string &X, string &Y)
{
    int m = X.length();
    int n = Y.length();
 
    int L[m+1][n+1];
 
    /* Following steps build L[m+1][n+1] in bottom
       up fashion. Note that L[i][j] contains
       length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
 
    // Following code is used to print LCS
    int index = L[m][n];
 
    // Create a string length index+1 and
    // fill it with \0
    string lcs(index+1, '\0');
 
    // Start from the right-most-bottom-most
    // corner and one by one store characters
    // in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y
        // are same, then current character
        // is part of LCS
        if (X[i-1] == Y[j-1])
        {
            // Put current character in result
            lcs[index-1] = X[i-1];
            i--;
            j--;
 
            // reduce values of i, j and index
            index--;
        }
 
        // If not same, then find the larger of
        // two and go in the direction of larger
        // value
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
 
    return lcs;
}
 
// Returns longest palindromic subsequence
// of str
string longestPalSubseq(string &str)
{
    // Find reverse of str
    string rev = str;
    reverse(rev.begin(), rev.end());
 
    // Return LCS of str and its reverse
    return lcs(str, rev);
}
void solution()
{
    int n;
    cin>>n;
    vector<int>arr(n);

    vector<int>cnt(100005,0);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    int max_val = *max_element(arr.begin(),arr.end());
    int maxi = 0;
    for(int i = 1;i<=max_val;i++)
    {
        cnt[i]+=cnt[i-1];
        if(cnt[i]%i==0)
        maxi = max(maxi,cnt[i]/i);
        else
        maxi = max(maxi,(cnt[i]/i)+1);
        

    }
    cout<<maxi<<endl;
    
    

}

int main()
{
    inout();
    int TC = 1;
    cin >> TC;
    while (TC--)
    {
        solution();
    }

    return 0;
}

void inout()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}