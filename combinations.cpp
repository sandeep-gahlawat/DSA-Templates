#include <bits/stdc++.h>
using namespace std;
void generate_combinations(int index, vector<int> &candidates, int target, int &sum, set<vector<int>> &set, vector<int> &curr)
{
    if (sum > target)
        return;
    if (sum == target)
    {

        set.insert(curr);
    }
    for (int i = index; i < candidates.size(); i++)
    {
        
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        sum += candidates[i];
        curr.push_back(candidates[i]);
        generate_combinations(i + 1, candidates, target, sum, set, curr);
        sum -= candidates[i];
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    set<vector<int>> set;
    int sum = 0;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    generate_combinations(0, candidates, target, sum, set, curr);
    vector<vector<int>> res;
    for (auto x : set)
    {
        res.push_back(x);
    }
    return res;
}
int main()
{
    return 0;
}