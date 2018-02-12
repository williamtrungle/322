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

int main() {
    int matrix[rows][cols];
    cout << "New matrix" << endl;
    fillMatrix(matrix);
    PrintMatrix(matrix);
    cout << endl << "Tranpose matrix" << endl;
    transposeMatrix(matrix);
    PrintMatrix(matrix);
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
            if (c != cols-1) cout << " | ";
        }
        cout << endl;
        if (r != rows-1) {
            for (int c = 0; c < cols; c++) {
                cout << "-";
                if (c != cols-1) cout << "---";
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
