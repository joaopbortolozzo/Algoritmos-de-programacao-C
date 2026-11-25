#include <iostream>
#include <cstdio>    // printf
#include <cstdlib>   // malloc, free
#include <cstring>   // strcpy, strcmp

// ---------------------------------------------------------
// ESTRUTURAS
// ---------------------------------------------------------

// Dados de cada cliente (a "carga" que a fila guarda)
struct dados {
    char nomeCliente[100];
    int nmAgencia;
    int nmConta;
    char CPF[20];
};

// Nó da fila: guarda um cliente e aponta para o próximo.
// CORRIGIDO: tirei o ponteiro "ant", porque fila só precisa de "prox"
struct elemento {
    dados cadastro;          // dados do cliente
    struct elemento* prox;   // próximo nó (quem está atrás na fila)
};

typedef struct elemento Elem;

// Descritor: controla a fila inteira (não guarda clientes, só os extremos)
struct Descritor {
    Elem* inicio;   // quem está na frente (o próximo a sair)
    Elem* fim;      // quem está no final (o último que entrou)
    int tamanho;    // quantidade atual de clientes na fila
};

// ---------------------------------------------------------
// CRIAR A FILA
// ---------------------------------------------------------
Descritor* criar(void)
{
    Descritor* descritor;

    // Reserva memória para o descritor
    descritor = (Descritor*) malloc(sizeof(Descritor));

    // Fila nasce vazia: sem início, sem fim e tamanho zero
    descritor->inicio = NULL;
    descritor->fim = NULL;
    descritor->tamanho = 0;

    return descritor;
}

// ---------------------------------------------------------
// INSERIR NO FINAL DA FILA (enqueue)
// ---------------------------------------------------------
void inserirFila(Descritor* desc, dados d)
{
    Elem* novo;

    // CORRIGIDO: o tamanho a reservar é o do NÓ (Elem), não do Descritor
    novo = (Elem*) malloc(sizeof(Elem));

    novo->cadastro = d;   // copia os dados do cliente para dentro do nó
    novo->prox = NULL;    // ele será o último, então ninguém vem depois

    // Caso 1: fila vazia -> o novo é, ao mesmo tempo, o primeiro e o último
    if (desc->tamanho == 0)   // CORRIGIDO: "==" compara, "=" atribuiria
    {
        desc->inicio = novo;
        desc->fim = novo;
    }
    // Caso 2: fila com dados -> encaixa depois do último atual
    else
    {
        desc->fim->prox = novo;   // o antigo último passa a apontar pro novo
        desc->fim = novo;         // o novo vira o último
    }

    (desc->tamanho)++;   // mais um cliente na fila
}

// ---------------------------------------------------------
// REMOVER DO INÍCIO DA FILA (dequeue)
// Se a fila estiver vazia, devolve um "dados" com -1 (sinal de vazio)
// ---------------------------------------------------------
dados removerFila(Descritor* desc)
{
    Elem* elementoremovido;
    elementoremovido = desc->inicio;   // guarda quem vai sair

    // Prepara um "dados vazio" para devolver caso a fila esteja vazia
    dados d;
    strcpy(d.nomeCliente, "");
    d.nmAgencia = -1;
    d.nmConta = -1;
    strcpy(d.CPF, "");

    // Fila vazia: não há o que remover
    if (desc->tamanho == 0)   // CORRIGIDO: tamanho é int, então compara com 0
    {
        printf("Fila vazia! ");
    }
    else
    {
        // 1) Pega o dado do nó antes de liberar (senão perde a informação)
        d = elementoremovido->cadastro;

        // 2) Avança o início para o próximo da fila
        desc->inicio = desc->inicio->prox;

        // 3) Libera a memória do nó que saiu
        free(elementoremovido);

        // 4) Um cliente a menos
        desc->tamanho--;

        // 5) Se a fila esvaziou, o "fim" não pode ficar apontando pra
        //    um nó que já foi liberado: zera também
        if (desc->inicio == NULL)
        {
            desc->fim = NULL;
        }
    }

    return d;
}

// ---------------------------------------------------------
// LISTAR A FILA (usa só inserirFila e removerFila)
// Técnica da ROTAÇÃO: tira da frente, mostra e coloca no final.
// Depois de "tam" voltas, a fila volta à ordem original.
// ---------------------------------------------------------
void listarFila(Descritor* desc)
{
    dados auxDados;

    // Guarda o tamanho ANTES do laço, porque desc->tamanho muda
    // a cada remoção e bagunçaria a condição do for
    int tam = desc->tamanho;

    for (int pos = 0; pos < tam; pos++)
    {
        // Tira o cliente da frente
        auxDados = removerFila(desc);

        // Mostra os dados dele (%s para texto, %d para inteiro)
        printf("\n\nNOME: %s", auxDados.nomeCliente);
        printf("\nAgencia: %d", auxDados.nmAgencia);
        printf("\nConta: %d", auxDados.nmConta);
        printf("\nCPF: %s", auxDados.CPF);

        // Devolve para o final da fila, preservando a ordem
        inserirFila(desc, auxDados);
    }
}

// ---------------------------------------------------------
// CONSULTAR UM CLIENTE NA FILA PELO CPF
// Usa só inserirFila e removerFila (técnica da ROTAÇÃO).
// Devolve o cliente encontrado, ou um "dados vazio" (-1) se não achar.
// A ordem da fila é preservada no final.
// ---------------------------------------------------------
dados consultarFila(Descritor* desc, char* cpfprocurado)
{
    dados auxDados;   // guarda o cliente que saiu da frente da fila

    // Resultado começa "vazio": é o que será devolvido se o CPF não existir
    dados d;
    strcpy(d.nomeCliente, "");
    d.nmAgencia = -1;
    d.nmConta = -1;
    strcpy(d.CPF, "");

    // Guarda o tamanho ANTES do laço, porque desc->tamanho muda
    // a cada remoção e bagunçaria a condição do for
    int tam = desc->tamanho;

    for(int pos = 0; pos < tam; pos++)
    {
        // Tira o cliente da frente da fila
        auxDados = removerFila(desc);

        // Compara os CPFs: strcmp devolve 0 quando as strings são iguais
        // (não dá pra usar "==", que compararia endereços de memória)
        if(strcmp(auxDados.CPF, cpfprocurado) == 0)
        {
            d = auxDados;   // achou: guarda o cliente inteiro no resultado
        }

        // Reinsere SEMPRE, achando ou não, para a fila voltar à ordem original.
        // Também não dá return no meio: o laço tem que ir até o fim.
        inserirFila(desc, auxDados);
    }

    return d;   // cliente encontrado, ou o "dados vazio" se não achou
}

void removerCPF(Descritor *desc)
{
    Elem* cpfremovido;
    cpfremovido = desc->inicio;

    dados d;
    strcpy(d.nomeCliente, "");
    d.nmAgencia = -1;
    d.nmConta = -1;
    strcpy(d.CPF, "");

    int tam = desc->tamanho;

    for(int pos = 0; pos < tam; pos++)
    {
        if (desc->tamanho == 0)  
    {
        printf("Fila vazia! ");
    }
    else
    { 
        d = cpfremovido->cadastro;

      
        desc->inicio = desc->inicio->prox;

        free(cpfremovido);

        desc->tamanho--;

        if (desc->inicio == NULL)
        {
            desc->fim = NULL;
        }
    }
    }
     
}