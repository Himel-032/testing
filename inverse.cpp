#include <bits/stdc++.h>
using namespace std;

// Function to perform Gauss-Jordan elimination to compute matrix inverse
void gaussJordanInverse(vector<vector<double>> &matrix, vector<vector<double>> &inverse) {
    int n = matrix.size();

    // Augment the matrix with the identity matrix
    vector<vector<double>> augmented(n, vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];
        }
        augmented[i][n + i] = 1.0; // Identity matrix portion
    }

    // Perform Gauss-Jordan Elimination
    for (int i = 0; i < n; i++) {
        // Ensure the pivot is non-zero
        if (augmented[i][i] == 0) {
            int rowToSwap = i + 1;
            while (rowToSwap < n && augmented[rowToSwap][i] == 0) {
                rowToSwap++;
            }
            if (rowToSwap == n) {
                cout << "Matrix is singular, no inverse exists." << endl;
                return;
            }
            swap(augmented[i], augmented[rowToSwap]);
        }

        // Normalize the pivot row
        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot;
        }

        // Eliminate all other entries in the current column
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = augmented[i][n + j];
        }
    }
}

int main() {
    cout << setprecision(5) << fixed;
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n, 0.0));
    vector<vector<double>> inverse(n, vector<double>(n, 0.0));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    gaussJordanInverse(matrix, inverse);

    cout << "The inverse of the matrix is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << inverse[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
