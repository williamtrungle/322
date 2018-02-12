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
void multiplyMatrix_r(int left[rows][cols], int right[rows][cols], int result[rows][cols]);
void fillMatrix_p(int **matrix);
void PrintMatrix_p(int **matrix);
void transposeMatrix_p(int **matrix);
void fillMatrix_s(int matrix[rows * cols]);
void PrintMatrix_s(int matrix[rows * cols]);

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
    int recurs[rows][cols];
    fillMatrix(left);
    fillMatrix(right);
    multiplyMatrix_I(left, right, result);
    multiplyMatrix_r(left, right, recurs);
    cout << endl;
    PrintMatrix(left);
    cout << endl;
    PrintMatrix(right);
    cout << endl;
    PrintMatrix(result);
    cout << endl;
    PrintMatrix(recurs);
    cout << endl;

    int **matrix_p = new int*[rows];
    for (int i = 0; i < cols; i++ ) *(matrix_p+i) = new int[cols];
    cout << "New pointer matrix" << endl;
    fillMatrix_p(matrix_p);
    PrintMatrix_p(matrix_p);

    cout << endl << "Tranpose pointer matrix" << endl;
    transposeMatrix_p(matrix_p);
    PrintMatrix_p(matrix_p);

    int matrix_s[rows * cols];
    cout << "New single matrix" << endl;
    fillMatrix_s(matrix_s);
    PrintMatrix_s(matrix_s);
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

// ----------------------------------------------------------------------------
// Question 6 (15pts)

void multiplyMatrix_r(int left[rows][cols], int right[rows][cols], int result[rows][cols]) {
    static int r = 0, c = 0, i = 0, t = 0;
    if (r >= rows) return;
    else {
        if (c < cols) {
            if (i < rows) {
                t += left[r][i] * right[i][c];
                i++;
                multiplyMatrix_r(left, right, result);
            } else {
                result[r][c] = t;
            }
            i = 0;
            c++;
            t = 0;
            multiplyMatrix_r(left, right, result);
        }
        c = 0;
        r++;
        multiplyMatrix_r(left, right, result);
    }
}

// ----------------------------------------------------------------------------
// Question 7 (15 pts)

void fillMatrix_p(int **matrix) {
    srand(time(NULL));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            *(*(matrix+r)+c) = rand() % maxrand;
        }
    }
}

void PrintMatrix_p(int **matrix) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << *(*(matrix+r)+c);
            if (c != cols-1) cout << "\t";
        }
        cout << endl;
    }
}

void transposeMatrix_p(int **matrix) {
    int t;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (r < c) {
                t = *(*(matrix+r)+c);
                *(*(matrix+r)+c) = *(*(matrix+c)+r);
                *(*(matrix+c)+r) = t;
            }
        }
    }
}

// ----------------------------------------------------------------------------
// Question 8 (15 pts)

void fillMatrix_s(int matrix[rows * cols]) {
    srand(time(NULL));
    for (int rc = 0; rc < rows * cols; rc++) matrix[rc] = rand() % maxrand;
}

void PrintMatrix_s(int matrix[rows * cols]) {
    for (int rc = 0; rc < rows * cols; rc++) {
        if (rc != 0 && rc % rows == 0) cout << endl;
        cout << matrix[rc];
        if ((rc % cols)+1 != 0) cout << "\t";
    }
    cout << endl;
}
