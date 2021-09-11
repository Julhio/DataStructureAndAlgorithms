/**
 * @file CoinsChange.cpp
 * @author Julhio Cesar Navas
 * @brief Coins Change Problem Solution
 * @version 0.1
 * @date 2020-10-14
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>

using namespace std;

void imprite(char *a, int *b,int tam){
    printf("%s",a);
    for(int i=0;i<tam/4;i++)
        printf("%3d |", b[i]);
    // while(*b != '\n'){
    //     printf("%3d |", *++b);
    // }
    printf("\n");
}

//Por divisao e conquista
int DCMakeChange(int moedas[], int troco, int size){

    int quant[troco + 1];
    int ultima[troco + 1];
    int cents = 1;

    for(int i = 0; i < troco + 1; i++)
        quant[i] = ultima[i] = 0;

    while(cents <= troco){

        int quantProv = cents;   //solucao provisoria, todas de 1 centavo
        int ultProv = 1;        //ultima moeda dessa solucao

        for(int j = 0; j < size; j++){
            if(moedas[j] > cents)
                break;          //#moeda nao serve

            if(quant[cents - moedas[j]] + 1 < quantProv){
                quantProv = quant[cents - moedas[j]] + 1;
                ultProv = moedas[j];
            }    
        }   
        quant[cents] = quantProv;
        ultima[cents] = ultProv;

        cents +=1;
    }
    cout << "Sera devolvido o troco de " << troco << " centavos em " << quant[troco] << " moedas:" << endl;

    printf("           =>");
    for(int i=0;i<sizeof(quant)/4;i++)
        printf("%3d |", i);
    printf("\n");
    imprite("Quantidade =>",quant,sizeof(quant));
    imprite("Ultima     =>",ultima,sizeof(ultima)230);
    cout << '\n' << endl;

    return quant[troco];
}

int main()
{ 
    int moedas[] = {1, 5, 10};
    int troco = 15;
    DCMakeChange(moedas, troco, 3);

    return 0; 
} 