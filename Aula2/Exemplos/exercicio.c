//
// Created by raul on 11/23/24.
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[50];
    int nroElem;
} LISTA;

bool inserirElemento(LISTA* l, REGISTRO reg, int posicao) {
    int aux;
    if (l->nroElem == 50 || posicao < 0 || posicao > l->nroElem) {
        return false;
    }
    for (aux = l->nroElem; aux>posicao; aux--) {
        l->A[aux] = l->A[aux-1]; // trazendo os elementos apos a posicao para a direita
    }
    l->A[posicao] = reg;
    l->nroElem++;
    return true;
}

void inserirNoFinal(LISTA* l, TIPOCHAVE numero) {
    if (l->nroElem == 50) {
        printf("Erro ao inserir elementos no final. Lista cheia.\n");
        return;
    }
    l->A[l->nroElem].chave = numero; // adiciona o numero na ultima posicao disponivel
    l->nroElem++;
}

void inicializarLista(LISTA* l) {
    l->nroElem = 0;
}

void exibirLista(LISTA* l) {
    int i;
    printf("Lista: \" ");
    for(i = 0; i < l->nroElem; i++)
        printf("%i ", l->A[i].chave);
    printf("\"\n");
}

int main() {
    LISTA lista; // Declaração da lista
    inicializarLista(&lista); // Inicializa a lista
    // Insercao de elementos no final
    inserirNoFinal(&lista, 10);
    inserirNoFinal(&lista, 9);
    inserirNoFinal(&lista, 8);
    inserirNoFinal(&lista, 7);
    REGISTRO reg1 = {45}; REGISTRO reg2 = {40}; REGISTRO reg3 = {30}; // Criando registros
    inserirElemento(&lista,reg1,0);
    inserirElemento(&lista,reg2,1);
    inserirElemento(&lista,reg3,2);
    exibirLista(&lista); // Exibe a lista vazia
    return 0;
}

