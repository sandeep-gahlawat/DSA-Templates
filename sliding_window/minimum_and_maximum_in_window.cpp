#include <bits/stdc++.h>
using namespace std;

// for finding minimum and maximum in every window we can use deque
// one deque for finding minimum and one for maximum
vector<int> minimum_and_maximum(vector<int> &arr, int k)
{
    int n = arr.size();
    deque<int> min_deque;
    deque<int> max_deque;
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        while (!min_deque.empty() && arr[min_deque.back()] > arr[i])
            min_deque.pop_back();
        while (!max_deque.empty() && arr[max_deque.back()] < arr[i])
            max_deque.pop_back();
        min_deque.push_back(i);
        max_deque.push_back(i);
    }
    res.push_back(arr[min_deque.front()]);
    res.push_back(arr[max_deque.front()]);

    for (int i = k; i < n; i++)
    {
        while (!min_deque.empty() && arr[min_deque.back()] > arr[i])
            min_deque.pop_back();
        while (!max_deque.empty() && arr[max_deque.back()] < arr[i])
            max_deque.pop_back();
        min_deque.push_back(i);
        max_deque.push_back(i);
        //pop the element that can't pe part of window of size k
        if (max_deque.front() == (i - k))
            max_deque.pop_front();
        if (min_deque.front() == (i - k))
            min_deque.pop_front();

        res.push_back(arr[min_deque.front()]);
        res.push_back(arr[max_deque.front()]);
    }
    return res;
}