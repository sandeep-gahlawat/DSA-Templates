// #include <bits/stdc++.h>
// using namespace std;

// point no 1
// void poits(vector<int> &arr)
// {
//     int m ;
//     //first thing we can write comparator function like this also
//     auto cmp = [&](int a, int b)
//     {
//         return abs(a - m) == abs(b - m) ? a < b : abs(a - m) < abs(b - m);
//     };
//     // important point is that we can push whole array in priority_queue in O(n) time
//     priority_queue<int, vector<int>, decltype(cmp)> pq(arr.begin(),arr.end(), cmp);
// }


#include <iostream>
#include <queue>

struct CustomComparator {
    bool operator()(const int& a, const int& b) const {
        // Change the comparison logic here
        // For example, to sort in ascending order:
        // return a > b;
        return a < b; // Sort in descending order (default)
    }
};

int main() {
    std::priority_queue<int, std::vector<int>, CustomComparator> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(7);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
