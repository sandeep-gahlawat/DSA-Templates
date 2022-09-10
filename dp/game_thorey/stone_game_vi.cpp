#include <bits/stdc++.h>
using namespace std;

// Intuition
// Sort stones by their sum value for Alice and Bob.
// If a stone is super valued for Alice, Alice wants to take it.
// If a stone is super valued for Bob, Alice also wants to take it.
// Because she doesn't want Bob to take it.

// Explanation
// Here is more convinced explanation.
// Assume a stone valued [a,b] for Alice and Bod.
// Alice takes it, worth a for Alice,
// Bob takes it, worth b for Bob,
// we can also consider that it worth -b for Alice.
// The difference will be a+b.
// That's the reason why we need to sort based on a+b.
// And Alice and Bob will take one most valued stone each turn.

int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
{
    vector<vector<int>> res;
    int n = aliceValues.size();
    priority_queue<vector<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({abs(aliceValues[i] + bobValues[i]), i});
    }
    bool alice = true;
    int cnt = 0;
    while (!pq.empty())
    {
        if (alice)
        {

            cnt += aliceValues[pq.top()[1]];
            pq.pop();

            alice = false;
        }
        else
        {
            cnt -= bobValues[pq.top()[1]];
            pq.pop();
            alice = true;
        }
    }
    if (cnt == 0)
        return 0;
    if (cnt > 0)
        return 1;
    return -1;
}