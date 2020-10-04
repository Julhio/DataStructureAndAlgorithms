//============================================================================
// Name        : DecToBin.cpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Recursive Dec to Bin converter
//============================================================================

#include <iostream>
using namespace std;

// Recursive function to convert n
// to its binary equivalent
int DecToBin(int n)
{
    // Base case
    if (n == 0) return 0;
    // Recursive call
    return (n % 2) + 10 * DecToBin(n / 2);
}

int main() {

	cout << DecToBin(7) << endl;

	return 0;
}
