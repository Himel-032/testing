#include <bits/stdc++.h>
using namespace std;

// Function to perform Gauss-Jordan elimination for matrix inversion
void gaussJordanInversion(vector<vector<double>> &matrix)
{
    int n = matrix.size();

    // Perform Gauss-Jordan elimination
    for (int i = 0; i < n; i++)
    {
        // Check if pivot is zero, and swap rows if necessary
        if (matrix[i][i] == 0)
        {
            bool rowSwapped = false;
            for (int j = i + 1; j < n; j++)
            {
                if (matrix[j][i] != 0)
                {
                    swap(matrix[i], matrix[j]);
                    rowSwapped = true;
                    break;
                }
            }
            if (!rowSwapped)
            {
                cout << "Matrix is singular, no inverse exists." << endl;
                return;
            }
        }

        // Normalize the pivot row
        double pivot = matrix[i][i];
        for (int j = 0; j < 2 * n; j++)
        {
            matrix[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = matrix[k][i];
                for (int j = 0; j < 2 * n; j++)
                {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main()
{
    cout << setprecision(5) << fixed;
    int n;
   // cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(2 * n, 0.0));

    // Input the matrix and augment with identity matrix
   // cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
        matrix[i][n + i] = 1.0; // Augment with identity matrix
    }

    // Perform Gauss-Jordan elimination to find the inverse
    gaussJordanInversion(matrix);

    // Extract and print the inverse matrix
    cout << "The inverse of the matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
