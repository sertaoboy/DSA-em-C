//
// Created by raul on 11/23/24.
//
#include <stdio.h>
#include <malloc.h>

typedef struct {
    int chave;
} REGISTRO;

typedef struct {
    REGISTRO A[50];
    int nroElem;
} LISTA;

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
    exibirLista(&lista); // Exibe a lista vazia
    return 0;
}

