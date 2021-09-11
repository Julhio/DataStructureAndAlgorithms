/**
 * @file DecToBin.cpp
 * @author Julhio Cesar Navas
 * @brief Recursive Dec to Bin converter
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

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
