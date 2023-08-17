#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int countAndMerge(long long arr[], int l, int m, int r)
    {
        int n1 = m - l + 1, n2 = r - m;
        long long left[n1], right[n2];
        for (int i = 0; i < n1; i++)
            left[i] = arr[i + l];
        for (int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];
        long long int res = 0, i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k++] = left[i++];
            }
            else
            {
                arr[k++] = right[j++];
                res = res + (n1 - i);
            }
        }
        while (i < n1)
            arr[k++] = left[i++];
        while (j < n2)
            arr[k++] = right[j++];
        return res;
    }

    long long int countInv(long long arr[], int l, int r)
    {
        long long int res = 0;
        if (l < r)
        {

            int m = (r + l) / 2;

            res += countInv(arr, l, m);
            res += countInv(arr, m + 1, r);
            res += countAndMerge(arr, l, m, r);
        }
        return res;
    }
    long long int inversionCount(long long arr[], long long N)

    {
        return (long long int)countInv(arr, 0, N - 1);
    }
};

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends