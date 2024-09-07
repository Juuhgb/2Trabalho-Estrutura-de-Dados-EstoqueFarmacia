#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicamento Medicamento;
typedef struct arvore Arvore;

struct medicamento{
    char nome[20];
    int codigo;
    float valor;
    int data[3];
};

struct arvore{
    Medicamento *m;
    Arvore *esquerda;
    Arvore *direita;
};

Medicamento *CriaMedicamento(char *nome, int codigo, float valor, int *data_validade){
    Medicamento *novo = (Medicamento*)malloc(sizeof(Medicamento));

    strcpy(novo->nome, nome);
    novo->codigo = codigo;
    novo->valor = valor;

    for(int i = 0; i < 3;i++){
        novo->data[i] = data_validade[i];
    }

    return novo;
}

Arvore *CriaArvore(){
    return NULL;
}

Arvore *InsereArvoreMedicamento(Arvore *a, Medicamento *m){
    if(a == NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->m = m;
        a->esquerda = a->direita = NULL;
    }
    else if(m < a->m){
        a->esquerda = InsereArvoreMedicamento(a->esquerda, m);
    }
    else if(m > a->m){
        a->direita = InsereArvoreMedicamento(a->direita, m);
    }

    return a;
}

Arvore *RetiraArvoreMedicamento(Arvore *a, int id_medicamento){
    if(a == NULL){
        return NULL;
    }
    else if(a->m->codigo > id_medicamento){
        a->esquerda = RetiraArvoreMedicamento(a->esquerda, id_medicamento);
    }
    else if(a->m->codigo < id_medicamento){
        a->direita = RetiraArvoreMedicamento(a->direita, id_medicamento);
    }
    else{
        if(a->esquerda == NULL && a->direita == NULL){
            free(a);
            a = NULL;
        }
        else if(a->esquerda == NULL){
            Arvore *aux = a;
            a = a->esquerda;
            free(aux);
        }
        else{
            Arvore *aux2 = a->esquerda;
            while(aux2->direita != NULL){
                aux2 = aux2->direita;
            }
            a->m = aux2->m;
            aux2->m = id_medicamento;
            a->esquerda = RetiraArvoreMedicamento(a->esquerda, id_medicamento);
        }
    }
}