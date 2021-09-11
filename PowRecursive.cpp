/**
 * @file PowRecursive.cpp
 * @author Julhio Cesar Navas
 * @brief Recursive Function to calculate a number raised to a power
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

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
