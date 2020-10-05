//============================================================================
// Name        : Stack.cpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Stack implementation
//============================================================================


#include <stdio.h>
#include <stdlib.h>
#include "Common.hpp"
#include <iostream>

using namespace std;

typedef Vector Stack;

int Size(Stack *p){
  return ((p->n));
}

int isEmpty(Stack *p){
  if(p->n < 0) return 1; 
  return  0;
}

void Push(Stack *p, int x){
  if(Size(p) == 999)
    exit(-1);
  p->V[p->n] = x;
  p->n++;
}

void Pop(Stack *p){
  if(isEmpty(p)) 
    exit(-1);
  p->V[p->n] = (int)' ';
  p->n--;
}

int Top(Stack *p){
  if(isEmpty(p)) 
    exit(-1);
  return p->V[p->n - 1];
}


int main(){
  Vector A;

  Push(&A, 13);
  Push(&A, 15);
  Push(&A, 9);

  cout << Size(&A) << endl;
  cout << Top(&A) << endl;
  PrintVector(&A);

  Pop(&A);

  cout << Size(&A) << endl;
  cout << Top(&A) << endl;
  PrintVector(&A);

  cout << endl;
  return 0;
}