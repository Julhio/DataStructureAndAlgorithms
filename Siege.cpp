/**
 * @file Siege.cpp
 * @author Julhio Cesar Navas
 * @brief 
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

#define SIZECACHEL1 1000

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

struct _vector{
  int n;
  int V[SIZECACHEL1];
};
typedef _vector Stack;

Stack b;

double wall_time(void)
{
  struct timeval tv;
  struct timezone tz;

  gettimeofday(&tv, &tz);
  return(tv.tv_sec + tv.tv_usec/1000000.0);
}



void Erase(Stack *p){
  p->n = -1;
}

void Push(Stack *p, int x){
  p->n++;
  p->V[p->n] = x;
}

int count_primes(int n) {
    const int S = 10000;
    long sqrtMax = (long) sqrt(n);
    
    vector<int> primos;
    vector<char> block(S);
    vector<char> is_prime(sqrtMax + 1);

    
    for(int i=0; i <= sqrtMax; i++){
        primos[i]=1;
        is_prime[i]=1;
    }

    for (int i = 2; i <= sqrtMax; i++) {
        if (is_prime[i]) {
            primos.push_back(i);
            for (int j = i * i; j <= sqrtMax; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primos) {
        //for(int i = 0; i < sizeof(primos); i++) {
        //    int p = primos[i];
            
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}





int SimpleSieve2(int *arr, int init, int size){
    int result = 0;
    int i = 0;

    arr[0]=1;                       //Exclui o numero 1 que não é primo

    i = 2;
    for (int j = i * i; j < size; j+=i) {
        arr[j - 1] = 1;             //Marca os números multiplos de 2
    }

    for (i=3; i < size; i=i+2) {    //Só percorre os índices ímpares
      for (int j = i * i; j < size; j+=i) {
         arr[j - 1] = 1;            //Marca os números impares multiplos de i    
      }
   }
   for (int i = 1; i < size; i++) {
      if (arr[i - 1] == 0){         //Se igual a zero, numero primo
        Push(&b,i);
        result++;
        }
   }
   return result;
}

void InitVector(int *a, int n){
    for (int i = 0; i <= n; i++)
		a[i] = 1;
}

void PrintVector(int *a, int n){
    for (int i = 2; i < n; i++){
        if (a[i]){
            printf("%d ", a[i]);			
        }		
    }
}

void PrintVector(Stack *p) {
  int i;
  for(i=0; i<=p->n; i++){
    printf("%d ",p->V[i]);
  }
  printf("\n");
}

int SimpleSieve(int *arr, int init, int size){
    int result = 0;
    int i = 0;

    if((init == 0) || (init == 1)) i = 2;
    else i = init;

    arr[0]=1; //Exclui o numero 1 que não é primo

    for (i; i < size; i++) {
      for (int j = i * i; j < size; j+=i) {
         arr[j - 1] = 1;
      }
   }
   for (int i = 1; i < size; i++) {
      if (arr[i - 1] == 0){
        Push(&b,i);
        result++;
        }
   }
   return result;
}
/*
int SimpleSieve(int *arr, int size){
    int result = 0;
    arr[0]=1;
    for (int i = 2; i < size; i++) {
      for (int j = i * i; j < size; j+=i) {
         arr[j - 1] = 1;
      }
   }
   for (int i = 1; i < size; i++) {
      if (arr[i - 1] == 0){
        Push(&b,i);
        result++;
        }
   }
   return result;
}*/

int main(){
	int sizeBlock = 10;
    int str[sizeBlock] = {0};
    
    int	n = 100;
	int *a = new int[n + 1];


    Erase(&b);

    //int num = SimpleSieve(str,sizeBlock);
	//printf("%d",num);

    //PrintVector(&b);
    //InitVector(a,n);
    int num = SimpleSieve2(a,1,n);
    printf("%d numeros primos \n",count_primes(100));
    PrintVector(&b);

    //printf("%d",count_primes(sizeBlock));
    

    return 0;
}




