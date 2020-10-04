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

typedef Vector Heap;

int HeapPai(int i){
  return ((i - 1) / 2);
}


int HeapFilhoEsq(int i){
  return (2 * i + 1);
}


int HeapFilhoDir(int i){
  return (2 * i + 2);
}


void Sobe(Heap *p, int i){
  int x,j;

  x = p->V[i];
  j = HeapPai(i);

  while(i > 0 && p->V[j] < x){
    p->V[i] = p->V[j];
    i = j;
    j = HeapPai(j);
  }
  p->V[i] = x;
}


void Desce(Heap *p, int i){
  int k,x;

  x = p->V[i];
  k = HeapFilhoEsq(i);
  while(k < p->n){
    if(k+1 < p->n){ /* Pega o maior filho. */
      if(p->V[k] < p->V[k+1])
        k = k+1;
    }
    if(p->V[k] > x){
      p->V[i] = p->V[k];
      i = k;
      k = HeapFilhoEsq(k);
    }
    else break;
  }
  p->V[i] = x;
}


/* O(n log n) */
void BuildHeap(Heap *p){
  int i;

  for(i = 1; i < p->n; i++)
    Sobe(p, i);
}


/* O(n)  */
void BuildHeapFast(Heap *p){
  int i,u;

  /* ultimo no nao folha. */
  u = HeapPai(p->n - 1);

  for(i = u; i >= 0; i--)
    Desce(p, i);
}


void InsereHeap(Heap *p, int x){
  p->V[p->n] = x;
  p->n++;
  Sobe(p, p->n-1); 
}


int RemoveHeap(Heap *p){
  int x;

  if(p->n == 0) exit(-1);

  x = p->V[0];
  p->V[0] = p->V[p->n-1];
  p->n--;
  Desce(p, 0);
  return x;
}


void HeapSort(Vector *p){
  int i,tmp,nn;

  nn = p->n;
  BuildHeapFast((Heap *)p);

  for(i=p->n-1; i>0; i--){
    tmp = p->V[0];
    p->V[0] = p->V[i];
    p->V[i] = tmp;

    p->n--;
    Desce((Heap *)p, 0);    
  }
  p->n = nn;
}


int main(){
  Vector A;
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