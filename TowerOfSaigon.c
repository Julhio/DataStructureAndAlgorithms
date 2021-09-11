/**
 * @file TowerOfSaigon.c
 * @author Julhio Cesar Navas
 * @brief 
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include <stdio.h> 

// C recursive function to solve tower of saigon puzzle 
void towerOfSaigon(int n, char from_rod, char to_rod, char aux1_rod, char aux2_rod) 
{ 
	if (n == 1) 
	{ 
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
		return; 
	} 
	towerOfSaigon(n-1, from_rod, aux1_rod, aux2_rod, to_rod); 
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
	towerOfSaigon(n-1, aux1_rod, aux2_rod, to_rod, from_rod); 
} 


int main() 
{ 
	int n = 3; // Number of disks 
	towerOfSaigon(n, 'A', 'C', 'B'); // A, B and C are names of rods 
	
	return 0; 
} 
