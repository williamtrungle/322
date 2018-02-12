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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % maxrand;
        }
    }
}
