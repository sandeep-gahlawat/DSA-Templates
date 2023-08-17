#include <iostream>
#include <vector>
// Algorithmic steps for implementation –
// the algorithmic steps to in-place rotate a square matrix by 90 degrees:
// Transpose the matrix: For each element matrix[i][j] where i < j, swap it with the element matrix[j][i].
// Reverse each row of the matrix: For each row i of the matrix, reverse the order of the elements by swapping matrix[i][j] with matrix[i][n – j – 1] where n is the number of columns in the matrix.
// The matrix is now rotated by 90 degrees in place.
// Note: The first step transforms the matrix into its transposed form, and the second step reverses the elements in each row, resulting in a rotation of the matrix by 90 degrees.
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix) {
int n = matrix.size();

// transpose the matrix
for (int i = 0; i < n; i++) {
	for (int j = i; j < n; j++) {
	swap(matrix[i][j], matrix[j][i]);
	}
}

// reverse each column
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n / 2; j++) {
	swap(matrix[j][i], matrix[n - j - 1][i]);
	}
}
}

int main() {
vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
rotateMatrix(matrix);

for (int i = 0; i < matrix.size(); i++) {
	for (int j = 0; j < matrix[0].size(); j++) {
	cout << matrix[i][j] << " ";
	}
	cout << endl;
}

return 0;
}
