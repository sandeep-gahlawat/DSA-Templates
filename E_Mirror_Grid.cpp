#include <bits/stdc++.h>
using namespace std;

void trans(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int N = A.size();
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            B[i][j] = A[j][i];
}
void rotate90Clockwise(vector<vector<int>>&a)
{
 int N = a.size();
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - i - 1; j++)
        {

            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
void solution()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    
    vector<vector<int>> tranpose = arr;
    // trans(arr, tranpose);
    rotate90Clockwise(tranpose);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != tranpose[i][j])
                cnt++;
        }
    }
     rotate90Clockwise(tranpose);

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != tranpose[i][j])
                cnt1++;
        }
    }
     rotate90Clockwise(tranpose);

    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != tranpose[i][j])
                cnt2++;
        }
    }
    cout<<max(cnt1/2,max(cnt/2,cnt2/2))<<endl;
    
}

int main()
{
    // inout();
    int TC = 1;
    cin >> TC;
    while (TC--)
    {
        solution();
    }

    return 0;
}
