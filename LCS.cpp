/**
 * @file LCS.cpp
 * @author Julhio Cesar Navas
 * @brief A simple C program to introduce a linked list 
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std; 

// Maximum string length 
#define N 100 

int L[N][N]; 

/* Returns set containing all LCS for X[0..m-1], Y[0..n-1] */
set<string> findLCS(string X, string Y, int m, int n) 
{ 
	// construct a set to store possible LCS 
	set<string> s; 

	// If we reaches end of either string, return 
	// a empty set 
	if (m == 0 || n == 0) 
	{ 
		s.insert(""); 
		return s; 
	} 

	// If the last characters of X and Y are same 
	if (X[m - 1] == Y[n - 1]) 
	{ 
		// recurse for X[0..m-2] and Y[0..n-2] in 
		// the matrix 
		set<string> tmp = findLCS(X, Y, m - 1, n - 1); 

		// append current character to all possible LCS 
		// of substring X[0..m-2] and Y[0..n-2]. 
		for (string str : tmp) 
			s.insert(str + X[m - 1]); 
	} 

	// If the last characters of X and Y are not same 
	else
	{ 
		// If LCS can be constructed from top side of 
		// the matrix, recurse for X[0..m-2] and Y[0..n-1] 
		if (L[m - 1][n] >= L[m][n - 1]) 
			s = findLCS(X, Y, m - 1, n); 

		// If LCS can be constructed from left side of 
		// the matrix, recurse for X[0..m-1] and Y[0..n-2] 
		if (L[m][n - 1] >= L[m - 1][n]) 
		{ 
			set<string> tmp = findLCS(X, Y, m, n - 1); 

			// merge two sets if L[m-1][n] == L[m][n-1] 
			// Note s will be empty if L[m-1][n] != L[m][n-1] 
			s.insert(tmp.begin(), tmp.end()); 
		} 
	} 
	return s; 
} 

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int LCS(string X, string Y, int m, int n) 
{ 
	// Build L[m+1][n+1] in bottom up fashion 
	for (int i = 0; i <= m; i++) 
	{ 
		for (int j = 0; j <= n; j++) 
		{ 
			if (i == 0 || j == 0) 
				L[i][j] = 0; 
			else if (X[i - 1] == Y[j - 1]){
				L[i][j] = L[i - 1][j - 1] + 1; 
				printf("%d", L[i][j]);
			}
			else{
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
				printf("%d", L[i][j]);
			}
			printf(" ");
		} 
		printf("\n");
	} 
	return L[m][n]; 
} 

/* Driver program to test above function */
int main() 
{ 
	string X = "AACGTGGCCTA"; 
	string Y = "CACGTTCCA"; 
	int m = X.length(); 
	int n = Y.length(); 

	int lcs = LCS(X, Y, m, n);

	cout << "LCS length is " << lcs << endl; 

	set<string> s = findLCS(X, Y, m, n); 

	for (string str : s) 
		cout << str << endl; 

	return 0; 
} 
