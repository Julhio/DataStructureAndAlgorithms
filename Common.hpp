/**
 * @file Common.hpp
 * @author Julhio Cesar Navas
 * @brief Common and auxiliary functions 
 * @version 0.1
 * @date 2020-10-14
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#ifndef COMMON_HPP_
#define COMMON_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define VMAX 1000

template <class T>
struct _vector{
  size_t n;
  T V[VMAX];
};

int RandomInteger (int low, int high) {
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

template <class P>
void PrintVector(P *p) {
  int i;
  for(i=0; i<=p->n; i++){
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