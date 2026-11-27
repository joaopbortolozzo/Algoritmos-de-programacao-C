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

void passarPilha(Descritor* A, Descritor* B)
{
    dados aux;                             // variável temporária pra carregar cada elemento

    while (A->tamanho != 0)                // repete enquanto A tiver elementos
    {
        aux = removerPilha(A);             // tira o topo de A e guarda em aux
        inserirPilha(B, aux);              // coloca aux no topo de B
    }
}


void listarPilha(Descritor* Pilha)
{
    Descritor* aux_PILHA = criar();        

    dados aux;                         

    while (Pilha->tamanho != 0)           
    {
        aux = removerPilha(Pilha);        
        printf("\nNOME: %s", aux.nome);    
        printf("\nIDADE: %d", aux.idade);  
        inserirPilha(aux_PILHA, aux);     
    }

    while (aux_PILHA->tamanho != 0)        
    {
        aux = removerPilha(aux_PILHA);     
        inserirPilha(Pilha, aux);          
    }

    free(aux_PILHA);                       
}