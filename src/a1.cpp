// @author: William Le
// @studentid:260239181 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int rows = 5;
const int cols = 5;
const int maxrand = 10;

void fillMatrix(int matrix[rows][cols]);
void PrintMatrix(int matrix[rows][cols]);
void transposeMatrix(int matrix[rows][cols]);
void multiplyMatrix_I(int left[rows][cols], int right[rows][cols], int result[rows][cols]);

int main() {
    int matrix[rows][cols];
    cout << "New matrix" << endl;
    fillMatrix(matrix);
    PrintMatrix(matrix);
    cout << endl << "Tranpose matrix" << endl;
    transposeMatrix(matrix);
    PrintMatrix(matrix);
    cout << endl << "Multiply iteratively matrix" << endl;
    int left[rows][cols];
    int right[rows][cols];
    int result[rows][cols];
    fillMatrix(left);
    fillMatrix(right);
    multiplyMatrix_I(left, right, result);
    cout << endl;
    PrintMatrix(left);
    cout << endl;
    PrintMatrix(right);
    cout << endl;
    PrintMatrix(result);
}

// ----------------------------------------------------------------------------
// Question 1 (5 pts)

/* C++ does not allow returning arrays passed by value. Instead, a pointer to
 * the created array should be returned.
 */

// ----------------------------------------------------------------------------
// Question 2 (10 pts)

void fillMatrix(int matrix[rows][cols]) {
    srand(time(NULL));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            matrix[r][c] = rand() % maxrand;
        }
    }
}

// ----------------------------------------------------------------------------
// Question 3 (10 pts)

void PrintMatrix(int matrix[rows][cols]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << matrix[r][c];
            if (c != cols-1) cout << "\t";
        }
        cout << endl;
        if (r != rows-1) {
            for (int c = 0; c < cols; c++) {
                if (c != cols-1) cout << "\t";
            }
            cout << endl;
        }
    }
}

// ----------------------------------------------------------------------------
// Question 4 (15 pts)

void transposeMatrix(int matrix[rows][cols]) {
    int t;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (r < c) {
                t = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = t;
            }
        }
    }
}

// ----------------------------------------------------------------------------
// Question 5 (15pts)

void multiplyMatrix_I(int left[rows][cols], int right[rows][cols], int result[rows][cols]) {
    int t;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            t = 0;
            for (int i = 0; i < cols; i++) {
                t += left[r][i] * right[i][c];
            }
            result[r][c] = t;
        }
    }
}
