/**
 * @file Stack.hpp
 * @author Julhio Cesar Navas
 * @brief Stack implementation
 * @version 0.1
 * @date 2020-10-14
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stdio.h>
#include <stdlib.h>
#include "Common.hpp"
#include <iostream>

using namespace std;

typedef _vector<int> Stack;

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

int isFull(Stack *p){
  if(Size(p) == VMAX - 1) return 1; 
  return  0;
}

void Push(Stack *p, int x){
  if(isFull(p))
    cout << "STACK FULL" << endl;
  p->n++;
  p->V[p->n] = x;
}

void Pop(Stack *p){
  if(isEmpty(p)) 
    cout << "STACK EMPTY" << endl;
  p->V[p->n] = (int)' ';
  p->n--;
}

int Top(Stack *p){
  if(isEmpty(p)) 
    cout << "STACK EMPTY" << endl;
  return p->V[p->n];
}

#endif /* STACK_HPP_ */