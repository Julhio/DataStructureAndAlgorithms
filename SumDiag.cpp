/**
 * @file SumDiag.cpp
 * @author Julhio Cesar Navas
 * @brief Recursive sum of the diagonal elements of given matrix n x n
 * @version 0.1
 * @date 2020-10-15
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include <string.h>
#include <stdio.h> 
#include <iostream>
using namespace std;

typedef int (*Matrix)[3];

// Recursive function to convert n
// to its binary equivalent using recursive function
Matrix SumDiag(Matrix m, int n){
    // Base case
    if (n == 0) return 0;
    // Recursive call
    return m[n][n] + SumDiag(m,n--);
}

int main() {
    static int m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix = m;

	cout << SumDiag(matrix, 3) << endl;

	return 0;
}
