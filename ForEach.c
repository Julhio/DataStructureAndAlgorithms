/**
 * @file ForEach.c
 * @author Julhio Cesar Navas
 * @brief 
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>


void forEach(int *a, int *arr){
    for(a = arr; a < (&arr)[1]; ++a)
       printf("%d\n", *a);
}

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)


int main(void)
{
    int values[] = {1,2,3,4,5};
    
    int *v = (int *) malloc(sizeof(values));

    forEach(v,values);
    
    //foreach(int *v, values)
    //    printf("value: %d\n", *v);

    return 0;   
}