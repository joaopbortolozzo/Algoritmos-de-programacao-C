#include <iostream>
#include <string>
#include <cstring>

using namespace std;

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

void inserirFimLista(Descritor* descritor, dados d)
{
    Elem* novo;

    novo = (Elem*) malloc(sizeof(Elem));

    if (novo == NULL) return;

    novo->cadastro = d;
    novo->prox = NULL;

    if (descritor->inicio == NULL)
    {
        novo->ant = NULL;
        descritor->inicio = novo;
        descritor->fim = novo;
    }
    else
    {
        novo->ant = descritor->fim;
        descritor->fim->prox = novo;
        descritor->fim = novo;
    }

    descritor->tamanho++;
}

void consultarPorNome(Descritor* descritor, char nome[])
{
    Elem* aux = descritor->inicio;
    int posicao = 1;
    int achou = 0;

    while (aux != NULL)
    {
        if (strcmp(aux->cadastro.nome, nome) == 0)
        {
            cout << "Posicao " << posicao << ": "
                 << aux->cadastro.nome << " | "
                 << aux->cadastro.sexo << " | "
                 << aux->cadastro.idade << " anos | "
                 << aux->cadastro.peso << " kg | "
                 << aux->cadastro.altura << " m" << endl;
            achou = 1;
        }
        aux = aux->prox;
        posicao++;
    }

    if (achou == 0)
    {
        cout << "Nome nao encontrado." << endl;
    }
}

void listarFila(Descritor* descritor)
{
    Elem* aux = descritor->inicio;   
    int posicao = 1;

    if (aux == NULL)
    {
        cout << "Fila vazia." << endl;
        return;
    }

    while (aux != NULL)
    {
        cout << posicao << " - "
             << aux->cadastro.nome << " | "
             << aux->cadastro.sexo << " | "
             << aux->cadastro.idade << " anos | "
             << aux->cadastro.peso << " kg | "
             << aux->cadastro.altura << " m" << endl;
        aux = aux->prox;
        posicao++;
    }
}

void calcularIdadeMedia(Descritor* descritor)
{
    Elem* aux = descritor->inicio;
    int soma = 0;

    if (descritor->tamanho == 0)
    {
        descritor->idadeMedia = 0;
        return;
    }

    while (aux != NULL)
    {
        soma = soma + aux->cadastro.idade;
        aux = aux->prox;
    }

    descritor->idadeMedia = (float) soma / descritor->tamanho;
}

void furaFilaInicio(Descritor* descritor, dados d)
{
    Elem* novo;

    novo = (Elem*) malloc(sizeof(Elem));

    if (novo == NULL) return;

    novo->cadastro = d;
    novo->ant = NULL;   

    if (descritor->inicio == NULL)
    {
        novo->prox = NULL;
        descritor->inicio = novo;
        descritor->fim = novo;
    }
    else
    {
        novo->prox = descritor->inicio;    
        descritor->inicio->ant = novo;      
        descritor->inicio = novo;          
    }

    descritor->tamanho++;
}


void furaFilaPosicao(Descritor* descritor, dados d, int posicao)
{
    if (descritor->inicio == NULL || posicao <= 1)
    {
        furaFilaInicio(descritor, d);
        return;
    }

    if (posicao > descritor->tamanho)
    {
        inserirFimLista(descritor, d);
        return;
    }

    Elem* novo = (Elem*) malloc(sizeof(Elem));
    if (novo == NULL) return;
    novo->cadastro = d;

    Elem* anterior = descritor->inicio;
    for (int i = 1; i < posicao - 1; i++)
    {
        anterior = anterior->prox;
    }

    Elem* seguinte = anterior->prox;

    novo->ant = anterior;
    novo->prox = seguinte;

    anterior->prox = novo;
    seguinte->ant = novo;

    descritor->tamanho++;
}

void removerPorNome(Descritor* descritor, char nome[])
{
    Elem* atual = descritor->inicio;

    while (atual != NULL && strcmp(atual->cadastro.nome, nome) != 0)
    {
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        cout << "Nome nao encontrado." << endl;
        return;
    }

    if (atual == descritor->inicio && atual == descritor->fim)
    {
        descritor->inicio = NULL;
        descritor->fim = NULL;
    }
    else if (atual == descritor->inicio)
    {
        descritor->inicio = atual->prox;
        descritor->inicio->ant = NULL;
    }
    else if (atual == descritor->fim)
    {
        descritor->fim = atual->ant;
        descritor->fim->prox = NULL;
    }
    else
    {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }

    free(atual);
    descritor->tamanho--;
    cout << "Item removido." << endl;
}

dados lerDados()
{
    dados d;
    cout << "Nome: ";
    cin >> d.nome;
    cout << "Sexo (M/F): ";
    cin >> d.sexo;
    cout << "Idade: ";
    cin >> d.idade;
    cout << "Peso: ";
    cin >> d.peso;
    cout << "Altura: ";
    cin >> d.altura;
    return d;
}

int main()
{
    Descritor* fila = criar();
    int opcao;
    int posicao;
    char nome[50];
    dados d;

    do
    {
        cout << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Inserir no fim" << endl;
        cout << "2 - Consultar por nome" << endl;
        cout << "3 - Listar" << endl;
        cout << "4 - Calcular idade media" << endl;
        cout << "5 - Fura fila no inicio" << endl;
        cout << "6 - Fura fila em uma posicao" << endl;
        cout << "7 - Remover por nome" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            d = lerDados();
            inserirFimLista(fila, d);
        }
        else if (opcao == 2)
        {
            cout << "Nome: ";
            cin >> nome;
            consultarPorNome(fila, nome);
        }
        else if (opcao == 3)
        {
            listarFila(fila);
        }
        else if (opcao == 4)
        {
            calcularIdadeMedia(fila);
            cout << "Idade media: " << fila->idadeMedia << endl;
        }
        else if (opcao == 5)
        {
            d = lerDados();
            furaFilaInicio(fila, d);
        }
        else if (opcao == 6)
        {
            d = lerDados();
            cout << "Posicao: ";
            cin >> posicao;
            furaFilaPosicao(fila, d, posicao);
        }
        else if (opcao == 7)
        {
            cout << "Nome: ";
            cin >> nome;
            removerPorNome(fila, nome);
        }

    } while (opcao != 0);

    return 0;
}