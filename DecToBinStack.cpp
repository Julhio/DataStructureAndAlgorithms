//============================================================================
// Name        : DecToBinStack.cpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Recursive Dec to Bin converter using Stack
//============================================================================

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
