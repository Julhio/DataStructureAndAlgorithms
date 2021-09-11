/**
 * @file BFS.cpp
 * @author Julhio Cesar Navas
 * @brief Recursive Breadth-First Search
 * @version 0.1
 * @date 2020-10-14
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include <string.h>
#include <stdio.h> 
#include <iostream>
using namespace std;

typedef struct node node;
struct node {
    int data;
    node *left, *right;
};

// Recursive function to verify BFS structure
bool verifyBFS(node* root){
    // Base case
    if(root != nullptr)


        if (root->right != nullptr){
          
        }
        
        
        if (root->left != nullptr){


        } 
        
        // Recursive call
        return 0;
}

// Recursive function to print BFS structure
bool printBFS(node* root){
    // Base case
    if(root != nullptr)

        if (root->right != nullptr){

            

            
        }
        
        
        if (root->left != nullptr){


        } 
        
        // Recursive call
        return 0;
}

int main() {
    node* root = (node *)malloc(sizeof(node));
    root->data = 1;
    root->left->data = 2;
    root->right->data = 3;
	
    //cout << verifyBFS(root) << endl;
    cout << root << endl;
    


	return 0;
}