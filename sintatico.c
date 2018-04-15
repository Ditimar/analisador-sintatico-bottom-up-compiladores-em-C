#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sintatico.h"
#include "pilha.h"

#define alocaPilha (node *) malloc(sizeof(node))


int main(void) {
    int i=0, topoPilha, agulha, item;
    char expressao[50], topoExpressao[2];
    node *pilha = alocaPilha;
    push(pilha, 0);

    printf("Digite a expressao: ");
    scanf("%[^\n]s", expressao);
    remove_esp(expressao);
    changeA2N(expressao);
    strcat(expressao,"$");

    int gramatica[7];
    valorGramatica(gramatica);

    int acao[12][6];
    valorAcao(acao);

    int desvio[12][3];
    valorDesvio(desvio);

    while(expressao[i]){
        topoPilha = top(pilha);
        agulha = convert(expressao[i]);
        item = acao[topoPilha][agulha];
        int qtdRemove, pushDesvio;

        //printf("\nTopo da Pilha: %d ======= Letra lida: %c\n", topoPilha, expressao[i]);
        printf("\n");
        exibe(pilha);
        printf(" Expressao: %s\n", expressao + i);

        if(item == 100){
            printf("\n\n\nExpressao Aceita!\n\n\n");
            return 1;
        }
        if(item == 0){
            printf("\n\n\nInvalida!\n\n\n");
            return 0;
        }
        if(item > 0){
            printf("Push %d\n", item);
            push(pilha, item);
             i++;
        }
        else{
            qtdRemove = gramatica[item * -1];
            printf("Pop %d itens\n", qtdRemove);
            if(item > -3)
                pushDesvio = 0;
            else
                if(item > -5)
                    pushDesvio = 1;
                else
                    pushDesvio = 2;

            while(qtdRemove--)
                pop(pilha);

            printf("  +Push %d+\n",desvio[top(pilha)][pushDesvio]);

            push(pilha, desvio[top(pilha)][pushDesvio]);
        }
    }

    return 0;
}
