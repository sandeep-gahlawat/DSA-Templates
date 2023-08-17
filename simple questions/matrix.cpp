#include <bits/stdc++.h>
using namespace std;

// Function to find transpose of a matrix.
vector<vector<int>> transpose(vector<vector<int>> &A)
{
    vector<vector<int>> vRes(A[0].size(), vector<int>(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            vRes[j][i] = A[i][j];
        }
    }
    return vRes;
}



int main()
{

    int row, column;

    cout << "Enter rows and columns of matrix: ";
    cin >> row >> column;

    vector<vector<int>> matrix(row, vector<int>(column));

    cout << "\nEnter elements of matrix: " << endl;

    // Storing matrix elements
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << "Enter element matrix" << i + 1 << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    // Printing the a matrix
    cout << "\nEntered Matrix: " << endl;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << " " << matrix[i][j];
            if (j == column - 1)
                cout << endl
                     << endl;
        }
    }
    vector<vector<int>> mat = transpose(matrix);
    cout << endl
         << "matrix after transpose" << endl;
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j)
        {

            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
} 