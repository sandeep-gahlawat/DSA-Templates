#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  // finding factors of number in sqrt(N);
  //   x*y = N => so maximum value of x =>x*x = N=>x = sqrt(N);
    int kThSmallestFactor(int N , int k) {
        vector<int>factors;
        for(int i = 1;i*i<=N ;i++)
        {
            if(N%i==0)
            {
              
                if(i*i==N)
                {
                    factors.push_back(i);
                }
                else
                {
                    factors.push_back(i);
                    factors.push_back(N/i);
                }
                
            }
        }
        sort(factors.begin(),factors.end());
         if(factors.size()>=k)
         return factors[k-1];
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;

        Solution ob;
        cout << ob.kThSmallestFactor(N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends