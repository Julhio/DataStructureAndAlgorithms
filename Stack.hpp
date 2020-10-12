//============================================================================
// Name        : Stack.hpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Stack implementation
//============================================================================

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stdio.h>
#include <stdlib.h>
#include "Common.hpp"
#include <iostream>

using namespace std;

typedef Vector Stack;

void Erase(Stack *p){
  p->n = -1;
}

int Size(Stack *p){
  return ((p->n+1));
}

int isEmpty(Stack *p){
  if(p->n < 0) return 1; 
  return  0;
}

void Push(Stack *p, int x){
  if(Size(p) == 999)
    exit(-1);
  p->n++;
  p->V[p->n] = x;
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
  return p->V[p->n];
}

#endif /* STACK_HPP_ */