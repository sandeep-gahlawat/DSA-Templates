#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    long long res = 0;
    int ps[n], ns[n];

    stack<int> s;
    s.push(0);
    for (int i = 0; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
            s.pop();
        int pse = s.empty() ? -1 : s.top();
        ps[i] = pse;
        s.push(i);
    }

    while (s.empty() == false)
    {
        s.pop();
    }

    s.push(n - 1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
            s.pop();
        int nse = s.empty() ? n : s.top();
        ns[i] = nse;
        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        long long curr = arr[i];
        curr += (i - ps[i] - 1) * arr[i];
        curr += (ns[i] - i - 1) * arr[i];
        res = max(res, curr);
    }
    return res;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = 0;
    vector<int>arr1(m);
    for(int i = 0;i<n;i++)
    {
        vector<int>arr(m);
        for(int j = 0;j<m;j++)
        {
            if(i==0)
            {
                arr[j] = (matrix[i][j]-'0');
            }
            else
            {
                if(matrix[i][j]=='0')
                arr[j] = 0;
                else
                arr[j] = (arr1[j]+(matrix[i][j]-'0'));
            }
        }
        
        maxi = max(maxi,largestRectangleArea(arr));
        arr1 = arr;
    }
    return maxi;
}