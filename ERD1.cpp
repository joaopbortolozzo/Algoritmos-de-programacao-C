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



