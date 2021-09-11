/**
 * @file DecToBinStack.cpp
 * @author Julhio Cesar Navas
 * @brief Recursive Dec to Bin converter using Stack
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include "Stack.hpp"
#include <iostream>

using namespace std;

// Recursive function to convert n
// to its binary equivalent using Stack
Stack DecToBinStack(Stack *bin, int n)
{
    // Base case
    if (n == 0) return *bin;
    // Recursive call
    DecToBinStack(bin, n/2);
    Push(bin, n%2);
}

int main() {
    Stack bin;
    Erase(&bin);
    DecToBinStack(&bin,88);
    PrintVector(&bin);
    cout << endl;
	return 0;
}
