#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <iostream>
#include <string>

struct dados
{
    char nome[50];
    int idade;
};

struct elemento
{
    dados cadastro;
    struct elemento* prox;
};

typedef struct elemento Elem;

struct Descritor
{
    Elem* inicio;
    int tamanho;
    Elem* fim;
};

Descritor* criar(void)
{
    Descritor*descritor;
    descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->inicio=NULL;
    descritor->tamanho=0;
    descritor->fim=NULL;

    return descritor;
};

void inserirPilha(Descritor* desc, dados d)
{
    Elem* novo;
    novo = (Elem*)malloc(sizeof(Elem));

    novo->cadastro = d;
    novo->prox = NULL;

    if(desc->tamanho == 0)
    {
        desc->inicio=novo;
        desc->fim=novo;
    }
    else
    {
        novo->prox = desc->inicio;
        desc->inicio = novo;
    }

    (desc->tamanho)++;

    return 1;
};

dados removerPilha(Descritor* desc)
{
    Elem* elementoremovido;

    dados d;
    strcpy_s(d.nome, "");
    d.idade = -1;

    if(desc->tamanho == 0)
    {
        return d;
    }
    
    elementoremovido = desc->inicio;

    d = elementoremovido->cadastro;

    desc->inicio = elementoremovido->prox;

    free(elementoremovido);

    (desc->tamanho)--;

    return d;
}

