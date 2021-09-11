/**
 * @file Stack.cpp
 * @author Julhio Cesar Navas
 * @brief Stack implementation 
 * @version 0.1
 * @date 2020-10-14
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

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