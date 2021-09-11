/**
 * @file CheckCodeBalance.cpp
 * @author Julhio Cesar Navas
 * @brief 
 * @version 0.1
 * @date 2020-11-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top; 
char stack[1000];

void checkBrackets(char str[], int size){
	for(int i = 0; i < size; i++){
		if((str[i]=='{')||(str[i]=='[')||(str[i]=='(')){
            top++;
			stack[top] = str[i];	
		}
        else if((str[i]=='}')){
            if(stack[top] == '{')
                stack[top--] = 0;
        }
        else if((str[i]==']')){
            if(stack[top] == '[')
                stack[top--] = 0;
        }
        else if((str[i]==')')){
            if(stack[top] == '(')
                stack[top--] = 0;
        }
	}
	if(top == -1)
		printf("YES\n");
	else
		printf("NO\n");
    top = -1; //stack is empty
    memset(stack,0, sizeof(stack));
}

int main(){
	int num;
	char str[1000];

	scanf("%d",&num);
	while(num > 0){
        memset(str,0, sizeof(str));
		scanf("%s", str);
		checkBrackets(str,strlen(str));
        num--;
	}      
    return 0;
}

