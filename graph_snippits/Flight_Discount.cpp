#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
#define ll long long
#define bin(n) std::bitset<32>(n).to_string()


// Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.

// Input

// The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Metsälä.

// After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. Each flight is unidirectional.

// You can assume that it is always possible to get from Syrjälä to Metsälä.

// Output

// Print one integer: the price of the cheapest route from Syrjälä to Metsälä.

// When you use the discount coupon for a flight whose price is x, its price becomes ⌊x/2⌋ (it is rounded down to an integer).

// Constraints
// 2≤n≤105
// 1≤m≤2⋅105
// 1≤a,b≤n
// 1≤c≤109
// Example

// Input:
// 3 4
// 1 2 3
// 2 3 1
// 1 3 7
// 2 1 5

// Output:
// 2




void inout();
void SieveOfEratosthenes(vector<bool> &prime)
{

    long long n = prime.size();
    for (long long p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {

            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


//approach
//let's we move from 1->x ->y-> n =>d1(distance between 1 and x)+(distance between x and y)/2 + d2(distance between y to x)

vector<long long> dijkistra(vector<vector<pair<int,int>>>& graph, int V, int src)
{
    vector<long long> dist(V, LONG_MAX);
    
    

    dist[src] = 0;
    // storing {distance,vertex};
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, src});
    long long u, v, w;
    while (!pq.empty())
    {
        pair<long long, long long> p = pq.top();
        pq.pop();
        u = p.second;
        
        //relexation operation on it's adjacents
        for (auto &to : graph[u])
        {
            v = to.first, w = to.second;
            if (   dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void solution()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    vector<vector<pair<int,int>>>adj(n+1);
    //in one adjancy list store edges in reverse way to find distance from y to n
    vector<vector<pair<int,int>>>adj1(n+1);
    for(int i = 0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edges.push_back({x,y,z});
        adj[x].push_back({y,z});
        adj1[y].push_back({x,z});
    }
    vector<long long>dist1 = dijkistra(adj,n+1,1);
    vector<long long>distn = dijkistra(adj1,n+1,n);
    long long res = LONG_MAX;
    for(auto &x:edges)
    {
        if(dist1[x[0]]!=LONG_MAX && distn[x[1]]!=LONG_MAX)
        res = min(res,dist1[x[0]]+distn[x[1]] + x[2]/2);
    }
    cout<<res<<endl;


}

int main()
{
    inout();
    // long long TC = 1;
    // cin >> TC;
    // while (TC--)
    // {
        solution();
    // }

    return 0;
}

void inout()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}