#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>


struct dados
{
    char nomeCliente[100];
    int nmAgencia;
    int nmConta;
    char CPF[20];
};


struct elemento
{
    dados cadastro;
    struct elemento* ant;
    struct elemento* prox;
};

typedef struct elemento Elem;

struct Descritor
{
    Elem* inicio;
    Elem* fim;
    int tamanho;
    float idadeMedia;   
};

Descritor* criar(void)
{
    Descritor* descritor;
    descritor = (Descritor*) malloc(sizeof(Descritor));
    descritor->inicio = NULL;
    descritor->fim = NULL;
    descritor->tamanho = 0;
    descritor->idadeMedia = 0;

    return descritor;
}

void inserirFILA(Descritor* desc, dados d)
{
    //ALOCAR MEMORIA PARA UM NOVO ELEMENTO (NOh)
    Elem* novo;
    novo = (Elem* )malloc(sizeof(Elem));

    //INSERIR DADOS NO novo NOh

    novo -> cadastro=d;
    novo -> prox = NULL;

    if(desc -> tamanho == 0)
    {
        desc->inicio=novo;
        desc ->fim=novo;
    }
    else
    {
        desc->fim->prox=novo;
        desc->fim=novo;
    }

    (desc->tamanho)++;

    dados removerFILA(Descritor* desc)
    {
        Elem* elementoremovido;
        elementoremovido = desc -> inicio;

        dados d;
        strcpy_s(d.nmCliente, "");
        d.nmAgencia=-1;
        
    }
}