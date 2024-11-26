//
// Created by raul on 26/11/24.
//
/******************************************************************************
//     listaLigadaD.c
// Este programa gerencia listas lineares ligadas (implementacao dinamica).
// As listas gerenciadas podem ter um numero arbitrario de elementos.
// Não usaremos sentinela nesta estrutura.
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define ERRO -1
#define true 1
#define false 0

typedef int bool;
typedef void* TIPOCHAVE2;

typedef struct tempRegistro{
  TIPOCHAVE2 chave;
  struct tempRegistro *prox;
  // outros campos...
} REGISTRO;

typedef REGISTRO* PONT2;

typedef struct {
  PONT2 inicio;
} LISTA;

/* Inicialização da lista ligada (a lista jah esta criada e eh apontada
pelo endereco em l) */
void inicializarLista(LISTA *l){
  l->inicio = NULL;
} /* inicializarLista */

/* Exibição da lista seqüencial */
void exibirLista(LISTA *l){
  PONT2 end = l->inicio;
  printf("Lista: \" ");
  while (end != NULL){
    printf("%d ", end->chave); // soh lembrando TIPOCHAVE2 = int
    end = end->prox;
  }
  printf("\"\n");
} /* exibirLista */

/* Retornar o tamanho da lista (numero de elementos) */
int tamanho(LISTA *l) {
  PONT2 end = l->inicio;
  int tam = 0;
  while (end != NULL){
    tam++;
    end = end->prox;
  }
  return tam;
} /* tamanho */

/* Retornar o tamanho em bytes da lista. Neste caso, isto depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytes(LISTA *l) {
  return(tamanho(l)*sizeof(REGISTRO))+sizeof(LISTA); // sizeof(LISTA) = sizeof(PONT2) pois a "LISTA" eh um ponteiro para o 1o elemento
} /* tamanhoEmBytes */

/* Busca sequencial (lista ordenada ou nao) */
PONT2 buscaSeq(TIPOCHAVE2 ch, LISTA *l){
  PONT2 pos = l->inicio;
  while (pos != NULL){
    if (pos->chave == ch) return pos;
    pos = pos->prox;
  }
  return NULL;
} /* buscaSeq */

/* Busca sequencial - funcao de exclusao (retorna no endereço *ant o indice do
   elemento anterior ao elemento que está sendo buscado [ant recebe o elemento
   anterior independente do elemento buscado ser ou não encontrado]) */
PONT2 buscaSeqExc(TIPOCHAVE2 ch, LISTA *l, PONT2 *ant){
  *ant = NULL;
  PONT2 pos = l->inicio;
  while ((pos != NULL) && (pos->chave<ch)){
    *ant = pos;
    pos = pos->prox;
  }
  if ((pos != NULL) && (pos->chave == ch)) return pos;
  return NULL;
} /* buscaSeqExc */

/* Exclusão do elemento de chave indicada */
bool excluirElemLista(TIPOCHAVE2 ch, LISTA *l){
  PONT2 ant, i;
  i = buscaSeqExc(ch, l, &ant);
  if (i == NULL) return false;
  if (ant == NULL) l->inicio = i->prox;
  else ant->prox = i->prox;
  free(i);
  return true;
} /* excluirElemListaEnc */

/* Destruição da lista sequencial
   libera a memoria de todos os elementos da lista*/
void destruirLista(LISTA *l) {
  PONT2 end = l->inicio;
  while (end != NULL){
    PONT2 apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->inicio = NULL;
} /* destruirLista */


/* Inserção em lista ordenada sem duplicação */
bool inserirElemListaOrd(REGISTRO reg, LISTA *l) {
  TIPOCHAVE2 ch = reg.chave;
  PONT2 ant, i;
  i = buscaSeqExc(ch, l, &ant);
  if (i != NULL)  return false;
  i = (PONT2) malloc(sizeof(REGISTRO));
  *i = reg;
  if (ant == NULL) { // o novo elemento serah o 1o da lista
    i->prox = l->inicio;
    l->inicio = i;
  } else {  // inserção após um elemento já existente
    i->prox = ant->prox;
    ant->prox = i;
  }
  return true;
} /* inserirElemListaOrd */

/* retornarPrimeiro - retorna o endereco do primeiro elemento da lista e (caso
   a lista nao esteja vazia) retorna a chave desse elemento na memoria
   apontada pelo ponteiro ch */
PONT2 retornarPrimeiro(LISTA *l, TIPOCHAVE2 *ch){
  if (l->inicio != NULL) *ch = l->inicio->chave;
  return l->inicio;
} /* retornarPrimeiro */

/* retornarUltimo - retorna o endereco do ultimo elemento da lista e (caso
   a lista nao esteja vazia) retorna a chave desse elemento na memoria
   apontada pelo ponteiro ch */
PONT2 retornarUltimo(LISTA *l, TIPOCHAVE2 *ch){
  PONT2 ultimo = l->inicio;
  if (l->inicio == NULL) return NULL;
  while (ultimo->prox != NULL) ultimo = ultimo->prox;
  *ch = ultimo->chave;
  return ultimo;
} /* retornarUltimo */

