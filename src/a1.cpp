// @author: William Le
// @studentid:260239181 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int rows = 5;
const int cols = 5;
const int maxrand = 10;

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

int main() {
    int matrix[rows][cols];
    fillMatrix(matrix);
    PrintMatrix(matrix);
}
