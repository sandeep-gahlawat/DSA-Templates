#include<bits/stdc++.h>

using namespace std;

// Trying every color from 1 to m with the help of a for a loop.

// Is safe function returns true if it is possible to color it with that color i.e none of the adjacent nodes have the same color.

// In case this is an algorithm and follows a certain intuition, please mention it. 

// Color it with color i then call the recursive function for the next node if it returns true we will return true.

// And If it is false then take off the color.

// Now if we have tried out every color from 1 to m and it was not possible to color it with any of the m colors then return false.


// Time Complexity: O( N^M) (n raised to m)

// Space Complexity: O(N)




bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {
    0
  };
  if (solve(0, color, m, N, graph)) return true;
  return false;
}

int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101] = {
    (0, 1),
    (1, 2),
    (2, 3),
    (3, 0),
    (0, 2)
  };
  cout << graphColoring(graph, m, N);

}
