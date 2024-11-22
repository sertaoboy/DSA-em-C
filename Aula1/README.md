# Criacao de uma primeira estrutura
- Queremos criar uma estrutura para guardar algumas informacoes
- Como modelamos essa estrutura?
- Como instanciamos essa estrutura?
- Como acessamos seus campos?

### Codigo em Java
```javascript
public class PesoAltura {
    int peso;
    int altura;
}
```
```javascript
public class EstruturaSimples {
    public static final int alturaMaxima = 225;
    public static void main (String [] args) {
        PesoAltura pessoa1 = new PesoAltura();
        pessoa1.peso = 80; //em quilogramas
        pessoa1.altura = 185; //em centimetros
        System.out.println("Peso: "+ pessoa1.peso + ", Altura "+pessoa1.altura+".");
        if(pessoa1.altura > alturaMaxima) {
            System.out.println("Altura acima da maxima.")';
        }else{
            System.out.println("Altura abaixo da maxima.");
        }
    }
}
```
### Codigo em C
- Em C, a seguinte sintaxe e utilizada para definir **estruturas**:
```c++
typedef struct{
    int peso;
    int altura;
} PesoAltura;
```
- A sintaxe `struct {...}` define uma estrutura com os campos definidos dentro das chaves.
- A sintaxe `typedef ... PesoAltura` define o nome **PesoAltura** para o que foi definido nas reticencias, por exemplo:
```c++
typedef int CHAVE;
```
- Definimos que a palavra **CHAVE** podersa ser usada no codigo para representar o tipo _int_, isto e, demos um novo nome para o tipo _int_.
- Em C, para definirmos uma **constante**:
```c++
#define alturaMaxima 225
```
- Para a funcao `main` em C:
```c++
int main() {
//...
return 0
```
- Para instanciar e objetos e acessar atributos;
- Java:
```javascript
PesoAltura pessoa1 = new PesoAltura();
pessoa1.peso = 80;
pessoa1.altura = 185;
```
- C:
```c++
PesoAltura pessoa1;
pessoa1.peso = 80;
pessoa1.altura = 185;
```
- Para realizar a impressao:
```c++
printf("Peso: %i, Altura %i. ", pessoa1.peso, pessoa1.altura);
```
- Em C, para imprimir parametros, escrevemos o texto normalmente no primeiro parametro sendo este uma **_mascara_**, e para acessar variaveis utilizamos `%`;
- Neste caso utilizamos `%i` para sinalizarmos que sera impresso um valor do tipo **inteiro**.
- Nos parametros seguintes de `printf` utilizamos as variaveis que serao impressas respectivamente: `pessoa1.peso` e `pessoa1.altura`.
- Codigo completo:
```c++
#include <stdio.h>
#define alturaMaxima 225

typedef struct{
    int peso; //em quilogramas
    int altura; //em centimetros
} PesoAltura;

int main() {
    PesoAltura pessoa1; //pessoa1 do tipo struct
    pessoa1.peso = 80; //atribuindo valor diretamente no campo peso
    pessoa1.altura = 185; //atribuindo valor diretamente no campo altura
    printf("Peso: %i, Altura %i. ", pessoa1.peso, pessoa1.altura);
    if (pessoa1.altura > alturaMaxima) printf("Altura acima da maxima. \n");
    else printf("Altura abaixo da maxima. \n");
    return 0;
```
- Saida:
```shell
 $ Peso: 80, Altura 185. Altura abaixo da maxima.
```

## Uso de memoria
- Em Java, na instancia de um objeto temos uma variavel `pessoa1` que contem um endereco do local onde este objeto esta;
- Em C, temos a estrutura em si. A implementacao em C **nao corresponde totalmente** a implementacao em Java.
- Apesar de parecidas, as implementacoes sao bem distintas, uma vez que em Java estamos trabalhando com referencias (objetos). No codigo em C, a implementacao nao esta ainda com essas referencias ou ponteiros. Adiante iremos implementar de maneira mais semelhante.
### Ponteiros e alocacao de memoria
- Em C ha uma distincao bastante explicita entre um tipo (ou estrutura) e um endereco:
> `int x;` significa que `x` e uma variavel do tipo **inteiro** <br>
> `int* y;` significa que `y` e uma variavel do tipo **endereco (ou referencia) para inteiro**. <br>
- O asterisco (*) apos a palavra _int_ indica que estamos falando de um **endereco para inteiro** e nao mais **de um inteiro**.
```c++
#include <stdio.h>
int main() {
    int x = 25; //1
    int* y = &x; //2; O operador "e comercial" (&) retorna a referencia ou endereco onde esta uma variavel
    *y = 30; //3
    printf("Valor atual de x: %i\n", x); //deve imprimir 30
    return 0;
```
1. A variavel `x` e inicializada com valor 25.
2. A variavel `y` recebe o endereco onde esta a variavel `x`.
3. Coloca-se o valor 30 na posicao de memoria referenciada (apontada) pelo endereco armazenado em `y`.
- Em C ha uma funcao para **alocacao de memoria**: `malloc` (_memory allocation_)
- Recebe como parametro o **numero de bytes** que se deseja alocar;
- Retorna o endereco inicial do bloco de bytes que foi alocado, porem esse retorno tem o tipo `void*` **(ponteiro para void)**, abaixo iremos fazer um _casting_ nesse retorno para o tipo _int_: `(int*) malloc(sizeof(int))`
- Ha um operador chamado `sizeof` que recebe como parametro um tipo (simples ou composto) e retorna a quantidade de bytes ocupada por esse tipo.

## Funcao malloc
```c++
#include <stdio.h>
#include <malloc.h>
int main() {
    int* y = (int*) malloc(sizeof(int));
    *y = 20; //na memoria na qual y aponta...
    int z = sizeof(int); 
    printf("*y=%i z=%i\n", *y, z);
    return 0;
}
```
- Saida:
```shell
$ *y=20 z=4 
```
### Nossa segunda implementacao
```c++
#include <stdio.h>
#include <malloc.h> //importamos a biblioteca malloc
#define alturaMaxima 225

typedef struct { //mantemos a estrutura como estava
    int peso;
    int altura;
} PesoAltura;

int main() {
    PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura)); //agora temos um ponteiro para a estrutura PesoAltura; alocamos a memoria em quantidades de bytes necessario para essa estrutura PesoAltura e realizando o casting para um ponteiro de PesoAltura
    pessoa1->peso = 80; // utilizamos -> para realizar as atribuicoes de valores para os campos na memoria, pois agora estamos trabalhando com um PONTEIRO para PesoaAltura
    pessoa1->altura = 185; //antes utilizamos o . para acessar esse campos, porem como se trata agora de um ponteiro para uma estrutura, utilizamos o ->
```
```c++
printf("Peso: %i, Altura %i. ", pessoa1->peso, pessoa1->altura); //para realizarmos a impressao tambem devemos acessar esses campos atraves de ->
```
```c++
if(pessoa1->altura > alturaMaxima) printf("Altura acima da maxima.\n"); //a mesma coisa para o parametro de condicional, utilizamos -> para acessar o valor do campo altura e comparando com a constante alturaMaxima
else printf("Altura abaixo da maxima.\n");
```
- Codigo completo:
```c++
#include <stdio.h>
#include <malloc.h>

typedef struct {
    int peso;
    int altura;
} PesoAltura;

int main() {
    PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));
    pessoa1->peso = 80;
    pessoa1->altura = 185;
    printf("Peso: %i, Altura %i. ", pessoa1->peso, pessoa1->altura);
    if(pessoa1->altura > alturaMaxima) printf("Altura acima da maxima.\n");
    else printf("Altura abaixo da maxima.\n");
    return 0;
}
```


