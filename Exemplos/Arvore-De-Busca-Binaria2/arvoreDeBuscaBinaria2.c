//
// Created by raul on 26/11/24.
//

/******************************************************************************
     arvoreDeBuscaBinaria.c
  Este programa gerencia arvores de busca binarias (com algumas funcoes
  adicionais).
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "pilhaEmLLD.c"
#include "filaEmLLD.c"

typedef int TIPOCHAVE;

typedef struct aux{
  TIPOCHAVE chave;
  struct aux *esq, *dir;
} NO;

typedef NO* PONT;


/* retorna o endereco do NO que contem chave=ch ou NULL caso a chave nao seja
   encontrada. Utiliza busca binaria recursiva                                */
PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){
  if (raiz == NULL) return NULL;
  if (raiz->chave == ch) return raiz;
  if (raiz->chave<ch)
    return buscaBinaria(ch,raiz->dir);
  return buscaBinaria(ch,raiz->esq);
}


void travessiaAux(PONT p, int *niv, TIPOCHAVE ch, bool *achou) {
  if(p) {
    (*niv)++;// *niv = *niv + 1;
    if(p->chave == ch) *achou = true;
    else {
      travessiaAux(p->esq, niv, ch, achou);
      if(!(*achou)) travessiaAux(p->dir, niv, ch, achou);
      if(!(*achou)) *niv = *niv - 1;
    }
  }
}

/* Retorna true e o nivel de uma chave (caso seja encontrada) e false caso
   contrario. Funciona para qualquer arvore binaria [de busca ou nao]*/
bool travessia(PONT p, int *niv, TIPOCHAVE ch) {
  *niv = 0;
    bool achou = false;
    travessiaAux(p, niv, ch, &achou);
    return achou;
}



// Percorre a árvore em nível e a exibe
void exibirArvoreEmNivel(PONT raiz) {
  if (!raiz) return;
  FILA f;
  inicializarFila(&f);
  entrarFila(raiz,&f);
  PONT atual;
  while((f.inicio)){
    atual = sairFila(&f);
    printf("%i ", atual->chave);
    if(atual->esq) entrarFila(atual->esq, &f);
    if(atual->dir) entrarFila(atual->dir, &f);
  }
  printf("\n");
}


/* exibe a arvore em pre-ordem - algoritmo nao recursivo                     */
void preOrdemNaoRecursivo(PONT raiz){
  if (!raiz) return;
  PILHA pi;
  inicializarPilha(&pi); // esta é uma pilha de Ponteiros
  push(raiz, &pi);
  PONT atual;
  while (!isEmpty(&pi)) {
     atual = pop(&pi);
     printf("%i ",atual->chave);
     if (atual->dir) push(atual->dir, &pi);
     if (atual->esq) push(atual->esq, &pi);
  }
  printf("\n");
}


/* Exibe arvore Pre Ordem         */
void exibirArvorePreOrdem2(PONT raiz){
  if (raiz == NULL) return;
  printf("%i ",raiz->chave);
  if (raiz->esq) exibirArvorePreOrdem2(raiz->esq);
  if (raiz->dir) exibirArvorePreOrdem2(raiz->dir);
}


/* cria um novo (aloca memoria e preenche valores) no com chave=ch e retorna
   seu endereco */
PONT criarNovoNo(TIPOCHAVE ch){
   PONT novoNo = (PONT)malloc(sizeof(NO));
   novoNo->esq = NULL;
   novoNo->dir = NULL;
   novoNo->chave = ch;
   return novoNo;
}

/* funcao auxiliar (recursiva) para insercao */
bool inserirAux(PONT raiz, TIPOCHAVE ch){
  if (raiz->chave > ch) {
    if (raiz->esq == NULL) {
      raiz->esq = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->esq, ch);
  }else{
    if (raiz->dir == NULL) {
      raiz->dir = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->dir, ch);
  }
}

/* insere um novo no com chave=novaChave na arvore binaria aPONTada por raiz */
bool inserirNo2(PONT * raiz, TIPOCHAVE novaChave){
  if (*raiz == NULL){
    *raiz = criarNovoNo(novaChave);
    return true;
  }
  else return inserirAux(*raiz, novaChave);
}

// Busca binária não recursiva devolvendo o nó pai
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
  PONT atual = raiz;
  *pai = NULL;
  while (atual) {
    if(atual->chave == ch)
    return(atual);
    *pai = atual;
    if(ch < atual->chave) atual = atual->esq;
    else atual = atual->dir;
  }
  return(NULL);
}


/* Auxilir da funcao excluirChave, procura a maior chave menor que a chave que
   serah excluida            */
PONT maiorAEsquerda(PONT p, PONT *ant){
  *ant = p;
  p = p->esq;
  while (p->dir) {
    *ant = p;
    p = p->dir;
  }
  return(p);
}



bool inserirNo(PONT* raiz, TIPOCHAVE ch){
  if (*raiz == NULL){
    *raiz = criarNovoNo(ch);
    return true;
  }else{
	if ((*raiz)->chave >= ch) return inserirNo(&(*raiz)->esq, ch);
    else return inserirNo(&(*raiz)->dir, ch);
  }
}


bool excluirNo(PONT* raiz, TIPOCHAVE ch){
  PONT atual = *raiz;
  if (!atual) return false;
  if (atual->chave == ch){
    PONT substituto, pai_substituto;
    if(!atual->esq || !atual->dir) {
      if(atual->esq) substituto = atual->esq;
      else substituto = atual->dir;
      *raiz = substituto;
      free(atual);
      return true;
    }else {
      substituto = maiorAEsquerda(atual,&pai_substituto);
      atual->chave = substituto->chave;
      ch = substituto->chave;
    }
  }
  if (ch > atual->chave) return excluirNo(&(atual->dir), ch);
  else return excluirNo(&(atual->esq), ch);
}




/* Auxilir da funcao excluirChave, procura a maior chave menor que a chave que
   serah excluida            */
PONT maior_esquerdo(PONT p, PONT *ant){
  *ant = p;
  p = p->esq;
  while (p->dir) {
    *ant = p;
    p = p->dir;
  }
  return(p);
}


/* exclui a chave com valor igual a ch   */
bool excluirChave(PONT *raiz, TIPOCHAVE ch){
  PONT atual, no_pai, substituto, pai_substituto;
  substituto=NULL;
  atual = buscaNo(*raiz, ch, &no_pai);
  if(atual == NULL) return false;
  if((!atual->esq)||(!atual->dir)) { // tem zero ou um filho
    if((!atual->esq)) substituto = atual->dir;
    if((!atual->dir)) substituto = atual->esq;
    if(!no_pai) {// o excluido eh raiz
       *raiz = substituto;
    }else {
      if(no_pai->chave > ch) no_pai->esq = substituto;
      else no_pai->dir = substituto;
    }
    free(atual);
  }
  else {   // tem dois filhos
    substituto = maior_esquerdo(atual,&pai_substituto);
    atual->chave = substituto->chave;
    if (pai_substituto->esq == substituto){
      pai_substituto->esq = substituto->esq;
    } else {
      pai_substituto->dir = substituto->esq;
    }
    free(substituto);
  }
  return true;
}

/* Exibe arvore Em Ordem         */
void exibirArvoreEmOrdem(PONT raiz){
  if (raiz == NULL) return;
  exibirArvoreEmOrdem(raiz->esq);
  printf("%i ",raiz->chave);
  exibirArvoreEmOrdem(raiz->dir);
}

/* Exibe arvore Pre Ordem         */
void exibirArvorePreOrdem(PONT raiz){
  if (raiz == NULL) return;
  printf("%i ",raiz->chave);
  exibirArvorePreOrdem(raiz->esq);
  exibirArvorePreOrdem(raiz->dir);
}

/* Exibe arvore Pos Ordem         */
void exibirArvorePosOrdem(PONT raiz){
  if (raiz == NULL) return;
  exibirArvorePosOrdem(raiz->esq);
  exibirArvorePosOrdem(raiz->dir);
  printf("%i ",raiz->chave);
}

/* Exibe arvore em Pre Ordem (com parenteses para os filhos)    */
void exibirArvore(PONT raiz){
  if (raiz == NULL) return;
  printf("%i",raiz->chave);
  printf("(");
  exibirArvore(raiz->esq);
  printf("|");
  exibirArvore(raiz->dir);
  printf(")");
}

/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
void destruirAux(PONT subRaiz){
  if (subRaiz){
    destruirAux(subRaiz->esq);
    destruirAux(subRaiz->dir);
    free(subRaiz);
  }
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz    */
void destruirArvore(PONT * raiz){
  destruirAux(*raiz);
  *raiz = NULL;
}


/* inicializa arvore: raiz=NULL */
void inicializar(PONT * raiz){
  *raiz = NULL;
}


/*
int main(){
  PONT raiz = NULL;
  inserirNo(&raiz, 40);
  inserirNo(&raiz, 30);
  inserirNo(&raiz, 35);
  exibirArvoreEmOrdem(raiz);
  printf("\n");
  excluirNo(&raiz, 30);
  exibirArvoreEmOrdem(raiz);
  printf("\n");
  excluirNo(&raiz, 40);
  exibirArvoreEmOrdem(raiz);
  printf("\n");
  char x;
  scanf("%c", &x);
  return 0;
}
*/

