//============================================================================
// Name        : PowRecursive.cpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Recursive Function to calculate a number raised to a power
//============================================================================

#include <iostream>
using namespace std;

// Recursive function to calculate a number raised to a power
int PowRecursive(float base, int exp)
{
    // Base case
    if (exp == 0) 
        return 1.0;
    // Recursive call
    return base * PowRecursive(base, exp - 1);
}

int main() {

	cout << PowRecursive(2,4) << endl << endl;

	return 0;
}
