//
// Created by raul on 26/11/24.
//

/******************************************************************************
                             heap2.c
   Este programa implementa um heap MAXIMO em uma implementação estática de uma
   árvore binária. A raiz do heap é colocada na posição zero do arranjo.
******************************************************************************/
#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

typedef struct {
  int * A;
  int tamanhoAtual;
  int tamanhoMaximo;
} HEAP;

void inicializarHeap(HEAP * h, int tamanhoMax){
  h->A = (int*) malloc(sizeof(int)*(tamanhoMax));
  h->tamanhoAtual = 0;
  h->tamanhoMaximo = tamanhoMax;
}

void destruirHeap(HEAP * h){
  int tamanho = h->tamanhoMaximo;
  free(h->A);
  h->tamanhoMaximo=0;
  h->tamanhoAtual=0;
}

int pai(int i){
  return (i-1)/2;
}

int filhoEsquerda(int i){
  return 2*i+1;
}

int filhoDireita(int i){
  return 2*i + 2;
}

/* metodo auxiliar que pressupoe que o heap para qualquer j>i estah ordenado
   porem o elemento i nao eh necessariamente maior que seus filhos           */
void maxHeapify(HEAP * h, int i){
  int esq = filhoEsquerda(i);
  int dir = filhoDireita(i);
  int temp;
  int maior = i;
  if ((esq < h->tamanhoAtual) && (h->A[esq]>h->A[i])) maior = esq;
  if ((dir < h->tamanhoAtual) && (h->A[dir]>h->A[maior])) maior = dir;
  if (maior != i) {
     temp = h->A[i];
     h->A[i] = h->A[maior];
     h->A[maior] = temp;
     maxHeapify(h,maior);
  }
}

// Constroi heap a partir do arranjo usando o metodo maxHeapify
void construirHeapMaximo(HEAP * h){
  int i;
  int metadeTamanho = h->tamanhoAtual/2;
  for (i=metadeTamanho;i>=0;i--) maxHeapify(h,i);
}

// Insere no final do arranjo do heap
bool inserirForaDeOrdem(HEAP * h, int valor){
  if (h->tamanhoAtual < h->tamanhoMaximo){
    h->A[h->tamanhoAtual] = valor;
    h->tamanhoAtual++;
    return true;
  }
  return false;
}


// Imprime o arranjo (na ordem que estiver)
void imprimirArranjo(HEAP h){
  int tamanho = h.tamanhoAtual;
  int i;
  for (i=0;i<tamanho;i++) printf("%d ",h.A[i]);
  printf("\n");
}


// Imprime elementos em ordem decrescente e esvazia o heap
void heapSort(HEAP * h){
  int tamanho = h->tamanhoAtual;
  int i, temp;
  construirHeapMaximo(h);  // se o arranjo jah for um heap, nao precisa desta linha
  for (i=tamanho-1;i>0;i--){
     temp = h->A[0];
     h->A[0] = h->A[i];
     h->A[i] = temp;
     //printf("%d ",temp);
     h->tamanhoAtual--;
     maxHeapify(h,0);
  }
  //printf("\n");
  h->tamanhoAtual = tamanho;
}

bool inserirHeap(HEAP * h, int chave){
  int i, temp;
  if (h->tamanhoAtual == h->tamanhoMaximo) return false;
  i = h->tamanhoAtual;
  h->A[i] = chave;
  h->tamanhoAtual++;
  while ((i>0) && (h->A[pai(i)]<h->A[i])){
     temp = h->A[i];
     h->A[i] = h->A[pai(i)];
     h->A[pai(i)] = temp;
     i = pai(i);
  }
  return true;
}


int percursoPreOrdem(HEAP* h, int atual){
  if (atual < h->tamanhoAtual){
    printf("%i ", h->A[atual]);
    percursoPreOrdem(h, filhoEsquerda(atual));
    percursoPreOrdem(h, filhoDireita(atual));
  }
}

int alturaHeap(HEAP* h){
  int altura = -1;
  int i = 0;
  while (i < h->tamanhoAtual){
    i = filhoEsquerda(i);
    altura++;
  }
  return altura;
}


int main(){
  HEAP meuHeap;
  inicializarHeap(&meuHeap, 100);
  inserirForaDeOrdem(&meuHeap,10);
  inserirForaDeOrdem(&meuHeap,5);
  inserirForaDeOrdem(&meuHeap,3);
  inserirForaDeOrdem(&meuHeap,20);
  inserirForaDeOrdem(&meuHeap,8);
  inserirForaDeOrdem(&meuHeap,6);
  inserirForaDeOrdem(&meuHeap,15);
  inserirForaDeOrdem(&meuHeap,1);
  inserirForaDeOrdem(&meuHeap,18);
  inserirForaDeOrdem(&meuHeap,40);
  inserirForaDeOrdem(&meuHeap,17);
  inserirForaDeOrdem(&meuHeap,12);
  imprimirArranjo(meuHeap);
  construirHeapMaximo(&meuHeap);
  imprimirArranjo(meuHeap);
  percursoPreOrdem(&meuHeap,0);
  printf("\n");
  heapSort(&meuHeap);
  imprimirArranjo(meuHeap);
  destruirHeap(&meuHeap);


  printf("\nTestes parte 2\n");
  inicializarHeap(&meuHeap, 50);
  inserirHeap(&meuHeap,10);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,5);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,3);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,20);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,8);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,6);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,15);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,1);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,18);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,40);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,17);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap,12);
  imprimirArranjo(meuHeap);
  /*o Heap ja esta corretamente montado, o comando a seguir nao alterara nada*/
  construirHeapMaximo(&meuHeap);
  imprimirArranjo(meuHeap);
  percursoPreOrdem(&meuHeap,0);
  printf("\n");
  heapSort(&meuHeap);
  imprimirArranjo(meuHeap);

  destruirHeap(&meuHeap);

}

