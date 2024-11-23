# Lista Linear Sequencial
### Lista Linear
- Estrutura de dados na qual **cada elemento e precedido por um elemento e sucedido por outro** (exceto o primeiro que nao tem predecessor e o ultimo que nao tem sucessor).
- Os elementos estao em uma dada **ordem** (por exemplo, a ordem de inclusao ou ordenados por uma chave).

### Lista linear sequencial
- Uma **lista linear** na qual a **ordem logica** dos elementos (a ordem "vista" pelo usuario) **e a mesma ordem fisica** (em memoria principal) dos elementos.
- Isto e, elementos vizinhos na lista estarao em posicoes vizinhas de memoria.

### Modelagem:
- Modelaremos usando um **arranjo** de registros;
- **Registros** conterao as informacoes de interesse do usuario;
- Nosso arranjo tera um **tamanho fixo** e controlaremos o numero de elementos com uma **variavel adicional**.
```c++
#define MAX 50 //tamanho pre-definido do nosso arranjo

typedef int TIPOCHAVE; //nomeando o tipo int para TIPOCHAVE

typedef struct{ 
    TIPOCHAVE chave;
    //outros campos...
} REGISTRO;

typedef struct{
    REGISTRO A[MAX]; //arranjo de REGISTRO(s) com o tamanho pre-definido
    int nroElem; //numero de elementos contidos no arranjo; elementos validos
} LISTA;
```
### Funcoes para gerenciamento
- Implementaremos funcoes para:
1. Inicializar a estrutura;
2. Retornar a quantidade de elementos validos;
3. Exibir os elementos da estrutura;
4. Inserir elementos na estrutura;
5. Excluir elementos da estrutura;
6. Reinicializar a estrutura;

## Inicializacao
- Para inicializar uma estrutura qualquer, precisamos pensar nos valores adequados para cada um dos campos de nossa estrutura;
- Para inicializar uma lista sequencial ja criada pelo usuario, so precisamos colocar o valor 0 (zero) no numero de elementos validos;
- Exercicio:
```c++
void inicializarLista(LISTA l) {
    l.nroElem = 0;
}
```
- Ha algum problema nesse codigo?
```c++
void inicializarLista(LISTA* l) {
    l->nroElem = 0;
}
```
- Qual a diferenca entre os codigos?
> Na primeira funcao, e copiada a estrutura LISTA pelo seu parametro quando executada. No momento em que se atribuiu o valor 0 ao campo `nroElem` houve a modificacao somente na copia, a estrutura LISTA originalmente criada nao esta sendo acessada. Tudo que for modificado nessa copia, nao sera refletido na estrutura original. <br> <br>
> Na segunda, recebe-se como parametro o endereco da estrutura LISTA. Quando definimos `l->nroElementos = 0`, na verdade estamos acessando o endereco na qual a variavel `l` aponta (estrutura original LISTA) e atribuindo o valor nesta. Neste caso, todas as modificacoes serao feitas diretamente na estrutura original.<br>

## Retornar numero de elementos
- Para esta estrutura basta retornar o valor do campo `nroElem`.
```c++
int tamanho(LISTA* l) {
    return l->nroElem;
}
```

## Exibicao/impressao dos elementos
- Para exibir os elementos da estrutura precisaremos iterar pelos **elementos** validos e, por exemplo, **imprimir suas chaves**.
```c++
void exibirLista(LISTA* l){
    int i;
    printf("Lista: \" ");
    for(i=0; i< l->nroElem; i++)
    printf("%i ", l->A[i].chave);
    printf("\"\n");
}
```
- Saida:
```shell 
$ Lista: "21 9 55"
```

## Buscar por elemento
- A funcao de busca devera:
1. **Receber uma chave** do usuario;
2. **Retornar a posicao** em que este elemento se encontra na lista (caso seja encontrado);
3. **Retornar -1** caso nao haja um registro com essa chave na lista.
```c++
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    while(i < l->nroElem) {
        if(ch == l->A[i].chave) return i;
        else i++;
    }
    return -1;
}
```

## Insercao de um elemento
- O usuario passa como parametro um registro a ser inserido na lista;
- Ha diferentes possibilidades de insercao:
1. No inicio;
2. No fim;
3. Ordenada pela chave;
4. Numa posicao indicada pelo usuario.

### Como inserir?
- Se a lista **nao estiver cheia** e o **indice** passado pelo usuario for **valido**: **desloca** todos os elementos posteriores uma posicao para a direita;
- **Insere** o elemento na posicao desejada, **soma um** no campo `nroElem` e **retorna `true`**;
- Caso contrario retorna `false`.
```c++
bool inserirElemLista(LISTA* l, REGISTRO reg, int i) {
    int j;
    if((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return false;
    for(j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1]; //deslocando todos os elementos uma posicao a direita
    l->A[i] = reg;
    l->nroElem++;
    return true;
}
```

## Exclusao de um elemento
- O usuario passa a chave do elemento a ser excluido;
- Se houver um elemento com esta chave na lista, "exclui esse elemento", **desloca** todos os elementos posteriores uma posicao para esquerda;
- **Diminui** em um o campo `nroElem` e **retorna `true`**;
- Caso contrario, retorna `false`.
```c++
bool excluirElemento(TIPOCHAVE ch, LISTA* l) {
    int posiscao, j;
    posicao = buscaSequencial(l,ch);
    if(posicao == -1) return false;
    for(j = posicao; j < l->nroElem -1; j++)
        l->A[j] = l->A[j+1];
    l->nroElem--;
    return true;
}    
```

## Reinicializacao da lista
- Para esta estrutura, para reinicializar a lista basta colocar 0(zero) no campo `nroElem`;
```c++
void reinicializarLista(LISTA* l) {
    l->nroElem = 0;
}
```
> - Obs.: importante notar que no momento da criacao da estrutura, o tamanho do arranjo ja esta pre-definido. <br>
> Com isso, potencialmente faz com que haja um desperdicio de uma grande quantidade de memoria.


