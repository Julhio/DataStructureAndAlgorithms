//============================================================================
// Name        : SumDiag.cpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Recursive sum of the diagonal elements of given matrix nxn
//============================================================================
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
