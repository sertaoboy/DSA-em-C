cmake_minimum_required(VERSION 3.31)
project(DSA_com_C C)

set(CMAKE_C_STANDARD 11)

add_executable(DSA_com_C main.c
        Aula2/Exemplos/exercicio.c
        Exemplos/Lista-Linear-Sequencial/listaSequencia.c
        Exemplos/Lista-Linear-Sequencial/usaListaSequencialInterativo.c
        "Exemplos/Lista-Ligada(ESTATICA)/listaLigada.c"
        "Exemplos/Lista-Ligada(ESTATICA)/usaListaLigadaInterativo.c"
        "Exemplos/Lista-Ligada(DINAMICA)/listaLigadaD.c"
        "Exemplos/Lista-Ligada(DINAMICA)/usaListaLigadaInterativo.c"
        "Exemplos/Lista-Ligada(DINAMICA)/filaEmLLD.c"
        "Exemplos/Lista-Ligada(DINAMICA)/usaFilaEmLLD.c"
        "Exemplos/Lista-Ligada(DINAMICA)/pilhaEmLLD.c"
        "Exemplos/Lista-Ligada(DINAMICA)/usaPilhaEmLLD.c"
        "Exemplos/Lista-Ligada(DINAMICA)/pilhaInvertidaEmLLD.c"
        "Exemplos/Lista-Ligada(DINAMICA)/usaPilhaInvertidaEmLLD.c"
        Exemplos/Lista-Ligada-Sentinela/listaLigadaSentinela.c
        Exemplos/Lista-Ligada-Sentinela/usaListaLigadaInterativo.c
        Exemplos/Lista-Ligada-Cabeca-Circular/listaLigadaCabCirc.c
        Exemplos/Lista-Ligada-Cabeca-Circular/usaListaLigadaInterativoCC.c
        "Exemplos/Fila (ESTATICA)/filaEstatica.c"
        "Exemplos/Fila (ESTATICA)/usaFilaEstatica.c"
        "Exemplos/Fila (ESTATICA)/impl2/filaEstatica.c"
        "Exemplos/Fila (ESTATICA)/impl2/usaFilaEstatica.c"
        "Exemplos/Fila(DINAMICA)/filaDinamica.c"
        "Exemplos/Fila(DINAMICA)/usaFilaDinamica.c"
        "Exemplos/Deque (DINAMICO)/DequeDinamico.c"
        "Exemplos/Deque (DINAMICO)/usaDeque.c"
        "Exemplos/Pilha(ESTATICA)/pilhaEstatica.c"
        "Exemplos/Pilha(ESTATICA)/usaPilhaEstatica.c"
        "Exemplos/Pilha Dupla(ESTATICA)/duasPilhasEstaticas.c"
        "Exemplos/Pilha Dupla(ESTATICA)/usaDuasPilhasEstaticas.c"
        "Exemplos/Pilha (DINAMICA)/pilhaDinamica.c"
        "Exemplos/Pilha (DINAMICA)/usaPilhaDinamica.c"
        "Exemplos/Lisa-Duplamente-Ligada-Circular-Cabeca(DINAMICA)/listaDuplamenteLigadaCC.c"
        "Exemplos/Lisa-Duplamente-Ligada-Circular-Cabeca(DINAMICA)/usaListaLigadaInterativoDCC.c"
        Exemplos/Arvore-Binaria/arvoreBinaria.c
        Exemplos/Arvore-De-Busca-Binaria/arvoreDeBuscaBinaria.c
        Exemplos/Arvore-De-Busca-Binaria/usaArvoreDeBuscaBinaria.c
        Exemplos/Heap/heap.c
        Exemplos/Heap/heap2.c
        Exemplos/Arvore-Enaria1/arvoreEnaria1.c
        Exemplos/Arvore-Enaria2/arvoreEnaria2.c
        Exemplos/Arvore-De-Busca-Binaria2/arvoreDeBuscaBinaria2.c
        Exemplos/Arvore-De-Busca-Binaria2/usaArvoreDeBuscaBinaria2.c
        Exemplos/Arvore-De-Busca-Binaria2/filaEmLLD.c
        Exemplos/Arvore-De-Busca-Binaria2/listaLigadaD.c
        Exemplos/Arvore-De-Busca-Binaria2/pilhaInvertidaEmLLD.c
        Exemplos/ArvoreAVL/arvoreAVL.c
        Exemplos/ArvoreAVL/usaArvoreAVL.c
)
