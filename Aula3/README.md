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
    while(i < l->nroElem) {
        if(ch == l->A[i].chave) {
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
    l->A[l->nroElem].chave = ch;
    while(l->A[i].chave != ch) {
        i++;
    }
    if(i == l->nroElem) {
        return -1;
    }else{
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