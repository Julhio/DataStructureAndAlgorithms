/**
 * @file josephus.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h> 

//Time complexity: O(n)
int josephus(int n, int k) 
{ 
if (n == 1) 
	return 1; 
else
	/* The position returned by josephus(n - 1, k) is adjusted because the 
	recursive call josephus(n - 1, k) considers the original position 
	k%n + 1 as position 1 */
	return (josephus(n - 1, k) + k-1) % n + 1; 
}

/*
If n is even
   f(n) = 2f(n/2) - 1
Else
   f(n) = 2f((n-1)/2) + 1
*/

//Time complexity: O(Log n)
int josephusLogn(int n) 
{ 
    // Find value of 2 ^ (1 + floor(Log n)) 
    // which is a power of 2 whose value 
    // is just above n. 
    int p = 1; 
    while (p <= n) 
        p *= 2; 
  
    // Return 2n - 2^(1+floor(Logn)) + 1 
    return (2 * n) - p + 1; 
} 


// Driver Program to test above function 
int main() 
{ 
int n = 14; 
int k = 2; 
printf("The chosen place is %d", josephus(n, k)); 
return 0; 
} 
