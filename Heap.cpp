/**
 * @file Heap.cpp
 * @author 
 * @brief 
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */


//============================================================================
// Name        : Heap.cpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Heap
//============================================================================


#include <stdio.h>
#include <stdlib.h>
#include "Common.hpp"

typedef _vector<int> Heap;

int HeapRoot(int i){
  return ((i - 1) / 2);
}


int HeapLeafLeft(int i){
  return (2 * i + 1);
}


int HeapLeafRight(int i){
  return (2 * i + 2);
}


void GoUp(Heap *p, int i){
  int x,j;

  x = p->V[i];
  j = HeapRoot(i);

  while(i > 0 && p->V[j] < x){
    p->V[i] = p->V[j];
    i = j;
    j = HeapRoot(j);
  }
  p->V[i] = x;
}


void GoDown(Heap *p, int i){
  int k,x;

  x = p->V[i];
  k = HeapLeafLeft(i);
  while(k < p->n){
    if(k+1 < p->n){ /* Pega o maior filho. */
      if(p->V[k] < p->V[k+1])
        k = k+1;
    }
    if(p->V[k] > x){
      p->V[i] = p->V[k];
      i = k;
      k = HeapLeafLeft(k);
    }
    else break;
  }
  p->V[i] = x;
}


/* O(n log n) */
void BuildHeap(Heap *p){
  int i;

  for(i = 1; i < p->n; i++)
    GoUp(p, i);
}


/* O(n)  */
void BuildHeapFast(Heap *p){
  int i,u;

  /* ultimo no nao folha. */
  u = HeapRoot(p->n - 1);

  for(i = u; i >= 0; i--)
    GoDown(p, i);
}


void InsertHeap(Heap *p, int x){
  p->V[p->n] = x;
  p->n++;
  GoUp(p, p->n-1); 
}


int RemoveHeap(Heap *p){
  int x;

  if(p->n == 0) exit(-1);

  x = p->V[0];
  p->V[0] = p->V[p->n-1];
  p->n--;
  GoDown(p, 0);
  return x;
}


void HeapSort(Heap *p){
  int i,tmp,nn;
  
  nn = p->n;
  BuildHeapFast((Heap *)p);

  for(i=p->n-1; i>0; i--){
    tmp = p->V[0];
    p->V[0] = p->V[i];
    p->V[i] = tmp;

    p->n--;
    GoDown((Heap *)p, 0);    
  }
  p->n = nn;
}


int main(){
  Heap A;
  int i;

  A.n = 10;
  for(i=0; i < 10; i++){
    A.V[i] = RandomInteger(0, 9);
  }

  PrintVector(&A);

  HeapSort(&A);

  PrintVector(&A);

  return 0;
}