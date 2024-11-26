//
// Created by raul on 26/11/24.
//

/******************************************************************************
//     filaEmLLD.c
// Este programa gerencia filas implementadas em listas lineares ligadas
   (implementacao dinamica).
// As filas gerenciadas podem ter um numero arbitrario de elementos.
// Não usaremos sentinela nesta estrutura.
******************************************************************************/
//#include "listaLigadaD.c"

typedef LISTA FILA;

/* Inicialização da fila (a fila jah esta criada e eh apontada
pelo endereco em f) */
void inicializarFila(FILA* f){
     inicializarLista(f);
} /* inicializarFila */

/* Exibição da fila sequencial */
void exibirFila(FILA* f){
  exibirLista(f);
} /* exibirLista */

/* Retornar o tamanho da fila (numero de elementos) */
int tamanhoFila(FILA* f) {
  return tamanho(f);
} /* tamanho */

/* Retornar o tamanho em bytes da fila. Neste caso, isto depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytesFila(FILA* f) {
  return tamanhoEmBytes(f);
} /* tamanhoEmBytes */

/* Busca Fila - retorna primeira chave da fila */
PONT2 buscaFila(FILA* f){
  return f->inicio;
} /* buscaFila */

/* Destruição da fila
   libera a memoria de todos os elementos da fila*/
void destruirFila(FILA* f) {
     destruirLista(f);
} /* destruirFila */

/* inserirElementoFila - insere elemento no "topo" da fila   */
bool inserirElementoFila(REGISTRO reg, FILA* f){
     TIPOCHAVE2 temp;
     PONT2 ultimo = retornarUltimo(f, &temp);
     PONT2 novo = (PONT2) malloc(sizeof(REGISTRO));
     *novo = reg;
     novo->prox = NULL;
     if (ultimo != NULL) ultimo->prox = novo;
     else f->inicio = novo;
     return true;
} /* inserirElementoFila */

void entrarFila(void* pont, FILA * f){
     REGISTRO temp;
     temp.chave = pont;
     inserirElementoFila(temp, f);
}

/* excluirElementoFila - retorna e exclui 1o elemento da fila
retorna false se nao houver elemento a ser retirado */
bool excluirElementoFila(FILA* f, REGISTRO * reg){
   if (f->inicio == NULL) return false;
   *reg = *(f->inicio);
   PONT2 tempInicio = f->inicio;
   f->inicio = f->inicio->prox;
   free(tempInicio);
   return true;
} /* excluirElementoFila */

void* sairFila(FILA *f){
  REGISTRO temp;
  temp.chave = NULL;
  excluirElementoFila(f,&temp);
  return temp.chave;
}

PONT2 retornarPrimeiroFila(FILA* f, TIPOCHAVE2 * ch){
     return retornarPrimeiro(f,ch);
}

