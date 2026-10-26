#include <iostream>
#include <string>


struct dados
{
    char nome[50];
    char sexo;
    int idade;
    float peso;
    float altura;
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
};

Descritor* criar (void);
{
    Descritor* descritor;
    descritor = (Descritor*) malloc(sizeof(Descritor));
    descritor-> inicio = NULL;
    descritor-> tamanho = 0;
    descritor-> fim = NULL;

    return descritor;
}

void inserirFimLista(Descritor* descritor, dados d)
{
    Elem* novo;

    // reserva espaço para um NÓ (por isso sizeof(Elem), e não Descritor)
    novo = (Elem*) malloc(sizeof(Elem));

    // se o malloc falhar (sem memória), sai da função sem fazer nada
    if (novo == NULL) return;

    novo->cadastro = d;   // copia os dados do paciente para dentro do nó
    novo->prox = NULL;    // ele será o último, então não tem próximo

    if (descritor->inicio == NULL)
    {
        // LISTA VAZIA: o nó novo é o único da lista
        novo->ant = NULL;          // não tem ninguém antes dele
        descritor->inicio = novo;  // ele é o primeiro...
        descritor->fim = novo;     // ...e também o último
    }
    else
    {
        // LISTA COM ELEMENTOS: encaixa o novo depois do último atual (B)
        novo->ant = descritor->fim;        // o novo olha pra trás, pro antigo último
        descritor->fim->prox = novo;       // o antigo último olha pra frente, pro novo
        descritor->fim = novo;             // só agora o fim passa a ser o novo
    }

    descritor->tamanho++;  // nos dois casos, a lista cresceu um elemento
}

void inserirInicioLista(Descritor* descritor, dados d)
{
     Elem* novo;

    novo = (Elem*) malloc(sizeof(Elem));

    if (novo == NULL) return;

    novo->cadastro = d;
    novo->ant = NULL;

    if (descritor->inicio == NULL)
    {
        novo->ant = NULL;
        descritor->inicio = novo;
        descritor->fim = novo;
    }
    else
    {
        novo->ant = descritor->inicio;
        descritor->inicio->ant = novo;
        descritor->inicio = novo;
    }
    descritor->tamanho++;
}

void inserirMeioLista(Descritor* descritor, dados d, int posicao)
{
    // lista vazia ou posição 1: na prática é inserir no início
    if (descritor->inicio == NULL || posicao <= 1)
    {
        inserirInicioLista(descritor, d);
        return;
    }

    // posição depois do último: na prática é inserir no fim
    if (posicao > descritor->tamanho)
    {
        inserirFimLista(descritor, d);
        return;
    }

    // a partir daqui, o nó entra de verdade no MEIO (entre dois nós existentes)
    Elem* novo = (Elem*) malloc(sizeof(Elem));
    if (novo == NULL) return;
    novo->cadastro = d;

    // anda pela lista até o nó que ficará ANTES do novo (posição - 1)
    Elem* anterior = descritor->inicio;
    for (int i = 1; i < posicao - 1; i++)
    {
        anterior = anterior->prox;
    }

    // o nó que ficará DEPOIS do novo é o próximo do anterior
    Elem* seguinte = anterior->prox;

    // 1) liga o novo nos dois vizinhos (o novo olha pros dois lados)
    novo->ant = anterior;
    novo->prox = seguinte;

    // 2) liga os vizinhos no novo (cada um olha de volta pro novo)
    anterior->prox = novo;
    seguinte->ant = novo;

    // inicio e fim do descritor NÃO mudam: o novo não é nem o primeiro nem o último
    descritor->tamanho++;
}


