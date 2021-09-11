##
# @file CoinsChange.py
# @author Julhio Cesar Navas
# @brief Coins Change Problem Solution Python
# @version 0.1
# @date 2020-09-08
# 
# @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
# 

#Por divisao e conquista
def DCMakeChange(moedas, troco):

    quant = [None] * (troco + 1)
    ultima = [None] * (troco + 1)

    quant[0] = 0
    ultima[0] = 0

    cents = 1
    while cents <= troco:

        quantProv = cents   #solucao provisoria, todas de 1 centavo
        ultProv = 1         #ultima moeda dessa solucao

        for j in range(len(moedas)):
            if moedas[j] > cents:
                break       #moeda nao serve

            if quant[cents - moedas[j]] + 1 < quantProv:
                quantProv = quant[cents - moedas[j]] + 1
                ultProv = moedas[j]

        quant[cents] = quantProv
        ultima[cents] = ultProv

        cents +=1
    
    print('Sera devolvido o troco de', troco, 'centavos em', quant[troco], 'moedas do conjunto', moedas,'\n')
    print('           =>', '|'.join(str(i).ljust(3) for i in range(troco + 1)) )
    #print('Quantidade =>', '|'.join(map(str, quant)) )
    #print('Ultima     =>', '|'.join(map(str,ultima)) )
    print('Quantidade =>', '|'.join(str(i).ljust(3) for i in quant) )
    print('Ultima     =>', '|'.join(str(i).ljust(3) for i in ultima) )
    print('\n\n')

    return quant[troco]

moedas = [1, 2, 3, 6]
troco = 13
DCMakeChange(moedas, troco)