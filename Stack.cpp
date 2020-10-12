//============================================================================
// Name        : Stack.cpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Stack implementation
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stack.hpp"

using namespace std;

int main(){
  Stack A;
  Erase(&A);

  cout << "Push 13" << endl;
  Push(&A, 13);
  cout << "Push 15" << endl;
  Push(&A, 15);
  cout << "Push 9" << endl;
  Push(&A, 9);

  cout << "Size: " << Size(&A) << endl;
  cout << "Vector: ";
  PrintVector(&A);
  cout << "Top: " << Top(&A) << endl;
  
  cout << "Pop" << endl;
  Pop(&A);

  cout << "Size: " << Size(&A) << endl;
  cout << "Vector: ";
  PrintVector(&A);
  cout << "Top: " << Top(&A) << endl;


  cout << endl;
  return 0;
}