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
    struct elemnto* prox;
};

typedef struct elemento Elem;

struct Descritor
{
    Elem* inicio;
    int tamanho;
    Elem* final;
};

Descritor* criar(void)
{
    Descritor* descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->inicio = NULL;
    descritor->final = NULL;
    descritor->tamanho = 0;
    return descritor;
}

int inserirFILA(Descritor* descritor, dados d)
{
    Elem* novo = (Elem*)malloc(sizeof(Elem));
    novo->cadastro = d;
    novo->prox = NULL;

    if (descritor->tamanho == 0)        
    {
        descritor->inicio = novo;
        descritor->final = novo;
    }
    else                                 
    {
        descritor->final->prox = novo;    
        descritor->final = novo;          
    }
    (descritor->tamanho)++;
    return 1;
}

dados removerFILA(Descritor* d)
{
    elemento* pos;
    static dados resultado;

    strcpy(resultado.nome, "");
    resultado.idade = -1;                 

    if (d->tamanho > 0)
    {
        pos = d->inicio;
        resultado = pos->cadastro;       
        d->inicio = pos->prox;
        if (d->inicio == NULL)            
            d->final = NULL;
        free(pos);
        (d->tamanho)--;
    }
    return resultado;
}

void listarFILA(Descritor* d)
{
    elemento* pos;
    static dados resultado;

    if (d->tamanho > 0)
    {
        int tam = d->tamanho;             
        for (int i = 0; i < tam; i++)
        {
            resultado = removerFILA(d);
            printf("\nNome: %s | Idade: %d", resultado.nome, resultado.idade);
            inserirFILA(d, resultado);    
        }
    }
}

dados consultarFILANOME(Descritor* d, char* nomeprocurado)
{
    elemento* pos;
    dados resultado, aux;
    int i = 0, tam = d->tamanho;

    strcpy(resultado.nome, "");
    resultado.idade = -1;                 

    while (i < tam)
    {
        aux = removerFILA(d);
        if (strcmp(aux.nome, nomeprocurado) == 0)
            resultado = aux;
        inserirFILA(d, aux);              
        i++;
    }
    return resultado;
}