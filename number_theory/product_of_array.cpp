//product of array is maximum when smallest element is maximum means we have to
//maximize smallest element of the array as much we can

#include<bits/stdc++.h>
using namespace std;

//leetcode link:https://leetcode.com/problems/maximum-product-after-k-increments/
int maximumProduct(vector<int> &nums, int k)
{
  int n = nums.size();
  long long product = 1;
  priority_queue<int,vector<int>,greater<int>>pq;
  for(int i = 0;i<n;i++)
  {
    pq.push(nums[i]);
  }
  while(k--)
  {
    int x = pq.top();
    pq.pop();
    pq.push(x+1);
  }
  while(!pq.empty())
  {
    product = (product*pq.top())%1000000007;
    pq.pop();
  }
  
  return product;
}