# Lista linear sequencial
### Revisando:
- Utilizamos um **arranjo** para armazenar nosso registros; A lista seria uma estrutura composta por um arranjo de registros e o numero de elementos;
- A **insercao** de registros era feita na posicao indicada pelo usuario.
- Adiante, vamos abordar os seguintes aspectos:
1. **Otimizacao da busca** por elementos; Mais eficiente;
2. Mudanca na **ordem de insercao** dos elementos; Vamos agora inserir de maneira **ordenada pela chave**, isso nos permite fazer por exemplo a **busca binaria**.

## Busca por elementos
- O usuario diz qual elemento e buscado e a funcao retorna a posicao desse elemento:
> As chaves dos elementos **nao** estao em ordem crescente; <br>
> Se o elemento nao existir a funcao retorna -1;
- Busca por elementos (versao inicial, aula2):
```c++
int buscaSequencial(LISTA* 1, TIPOCHAVE ch) {
    int i =0;
    while(i < l->nroElem) {  //1a verificacao; O(n)
        if(ch == l->A[i].chave) { //2a verificacao
            return i;
        }else{
            i++;
        }
    }
    return -1;
}
```
- Problemas desse algoritmo: Para cada elemento, temos que realizar duas verificacoes;
1.  Verificar se o indice e valido (`i < l->nroElem`);
2.  Verificar se a _chave_ do elemento atual e igual a _chave_ inserida.
- Ao inves de fazer duas comparacoes por iteracao, seria possivel fazer so uma?
> Precisamos sempre **comparar a chave do elemento atual** com a chave do elemento inserido; <br>
> Como garantir que nao iremos **passar do ultimo elemento?** <br>
> - Garantindo que **a chave inserida sera encontrada!**

- Criaremos um elemento **sentinela**:
1. **Elemento extra** (um registro) adicionado na lista para auxiliar alguma operacao;
2. Sera **inserido no final da lista** (apos o ultimo elemento valido) durante as buscas;
3. Contera a **chave do elemento buscado**.
- Implementacao:
```c++
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    l->A[l->nroElem].chave = ch; //insercao do sentinela
    while(l->A[i].chave != ch) { 
        i++;
    }
    if(i == l->nroElem) { //nesta condicao, a chave buscada esta sendo atribuida ao sentinela
        return -1;
    }else{ //retornando o indice do elemento encontrado
        return i;
    }
}
```
- A resolucao acima tem um **problema**:
> Se a lista estiver **cheia**, nao havera espaco para criar o sentinela;
- **O que fazer?**
1. Criamos a lista com uma posicao extra(**um registro a mais**) para garantir que havera espaco para o sentinela.
2. Essa posicao extra **nunca tera um registro valido**.
### Modelagem
```c++
#define MAX 50

typedef int TIPOCHAVE;

typdef struct {
    TIPOCHAVE chavel
    //outros campos...
} REGISTRO;

typedef struct {
    REGISTRO A[MAX +1]; // Criacao da lista com uma posicao a mais
    int nroElem;
} LISTA;
```

## Comparando apos a otimizacao:
- Antiga implementacao
```c++
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
    int i =0;
    while(i < l->nroElem) {
        if(ch == l->A[i].chave) {
            return i;
        } else{
            i++;
        }
        return -1;   
    }
}
```
- Implementacao com otimizacao:
```c++
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
    int i =0;
    l->A[l->nroElem].chave = ch;
    while(l->A[i].chave != ch) {
        i++;
    }
    if(i == l->nroElem) {
        return -1;
    } else {
        return i;
    }
}
```

## Busca por elementos
- A **busca binaria** nao e mais eficiente? O(log n);
- Sim, porem ela necessita que as chaves dos elementos estejam **ordenadas**;
- Para isso, precisaremos mudar nossa funcao de **insercao de elementos.**
- A funcao de insercao seguira a logica do _insertion sort_.
```c++
bool inserirElemListaOrd (LISTA* l, REGISTRO reg) {
    if(l->nroElem >= MAX) {
        return false;
    }else{
        int pos = l->nroElem;
        while(pos > 0 && l->A[pos -1].chave > reg.chave) {
            l->A[pos] = l->A[pos -1]; //neste momento os elementos ja estao deslocando um indice para direita
            pos--;
        }
        l->A[pos] = reg; //momento onde adicionamos o registro na posicao inserida
        l->nroElem++;
    }    
}
```
### Busca binaria
```c++
int buscaBinaria(LISTA* l, TIPOCHAVE ch) {
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem -1;
    while(esq <= dir) { 
        meio = ((esq  + dir) / 2);
        if(l->A[meio].chave == ch) {  //comparando a chave do elemento do meio com a buscada
            return meio; //caso seja o elemento, sera retornado
        } else { //a partir daqui temos duas possibilidades: 1- a chave buscada e menor que o elemento esta no meio; 2- a chave buscada e maior que o elemento atual
            if(l->A[meio].chave < ch) {  
                esq = meio +1; //definindo o intervalo menor para a busca
            } else {
                dir = meio -1; //definindo o intervalo maior para a busca
            }
        }
    }
    return -1; //caso o elemento buscado nao seja encontrado
}
```
- Com a ordenacao dos elementos pela chave:
1. A **busca** ficou **mais eficiente** (busca binaria);
2. Nao precisamos do **sentinela**;
3. O que acontece com a **exclusao**?
- Funcao de exclusao antes ja implementada:
```c++
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
    int pos, j;
    pos = buscaSequencial(l,ch);
    if(pos == -1) {
        return false;
    }else {
        for(j = pos; j< l->nroElem -1; i++) {
            l->A[j] = l->A[j+1];
        }
        l->nroElem--;
        return true;
    }
}
```