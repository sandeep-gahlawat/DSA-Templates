#include <bits/stdc++.h>
using namespace std;

int lomuto(vector<int> &arr, int l, int h)
{
    int pivot = arr[h]; // always last element of the array
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

int hoarse(vector<int> &arr, int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;
        swap(arr[j], arr[i]);
    }
    return 0;
}

void qsort_lomuto_partion(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int p = lomuto(arr, l, h);
        qsort_lomuto_partion(arr, l, p - 1);
        qsort_lomuto_partion(arr, p + 1, h);
    }
}
void qsort_hoarse(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int p = hoarse(arr,l,h);
        qsort_hoarse(arr,l,p);
        qsort_hoarse(arr,p+1,h);

    }
}