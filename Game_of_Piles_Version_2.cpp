#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007

#define bin(n) std::bitset<32>(n).to_string()

void inout();
void SieveOfEratosthenes(vector<bool> &prime)
{

    int n = prime.size();
    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int primeFactors(int n)
{
    int ans = 0;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        ans++;
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        ans++;
    return ans;
}

bool rec(int i, int empty, vector<int> &arr, bool turn)
{
    if (turn == false && empty == 2)
    {
        return true;
    }
    else if (turn == true && empty == 2)
        return false;
    if (turn == true)
    {
        bool flag = false;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] != 0)
            {
                arr[j]--;
                if (arr[j] == 0)
                    return flag | rec(i, empty + 1, arr, false);
                else
                    return flag | rec(i, empty, arr, false);

                arr[j]++;
                cout << "hello" << endl;
            }
        }
    }
    else
    {
        bool flag1 = true;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] != 0)
            {
                arr[j]--;
                if (arr[j] == 0)
                    return flag1 & rec(i, empty + 1, arr, true);
                else
                    return flag1 & rec(i, empty, arr, true);
                arr[j]++;
            }
        }
    }
    return true;
}

void solution()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int even = 0, odd = 0, ones = 0, sum = 0, count_2 = 0,count=0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            ones++;
        }
        else
        {
            if (arr[i] == 2)
            {
                count_2++;
            }
            sum += arr[i];
            count++;
            if (arr[i] % 2 == 0)
                even++;
            else
                odd++;
        }
    }
   if(ones==1)
   {
       if(odd%2==0)
       {
           cout<<"CHEF"<<endl;
           return;
       }
       if(count_2==0)
       {
           cout<<"CHEFINA"<<endl;
           return;
       }
       sum-=2;
       count--;
       if((sum-count)%2!=0)
       {
           cout<<"CHEFINA"<<endl;
           return;
       }
       cout<<"CHEF"<<endl;
       return;
   }
   if(ones>1)
   {
       if((sum-count)%2!=0)
       {
           cout<<"CHEF"<<endl;
           return;
       }
       cout<<"CHEFINA"<<endl;
       return;
   }
   if(odd%2!=0)
   {
       cout<<"CHEF"<<endl;
       return;
   }
   cout<<"CHEFINA"<<endl;
}

int main()
{
    inout();
    int TC = 1;
    cin >> TC;
    while (TC--)
    {
        solution();
    }

    return 0;
}

void inout()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}