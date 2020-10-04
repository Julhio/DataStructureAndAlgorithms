//============================================================================
// Name        : Common.hpp
// Author      : Julhio Cesar Navas
// Version     :
// Copyright   : Instituto Tecnológico de Aeronáutica
// Description : Common and auxiliary functions 
//============================================================================

#ifndef COMMON_HPP_
#define COMMON_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define VMAX 1000

typedef struct _vector{
  int n; /* Comprimento atual. */
  int V[VMAX];
} Vector;

int RandomInteger (int low, int high) {
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

void PrintVector(Vector *p) {
  int i;
  for(i=0; i<p->n; i++){
    printf("%d ",p->V[i]);
  }
  printf("\n");
}

bool isEven(int val) {
    return val % 2 == 0;
}

bool isOdd(int val) {
    return val % 2 != 0;
}

void Swap(int *a, int *b) {
    auto tmp = *a;
    *a = *b;
    *b = tmp;
}

#endif /* COMMON_HPP_ */