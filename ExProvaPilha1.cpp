// ===== DADOS QUE FICAM GUARDADOS NA PILHA =====
struct dados
{
    char nome[50];
    int idade;
};

// ===== NÓ DA PILHA =====
// Cada nó guarda os dados e aponta pro nó de BAIXO dele
struct elemento
{
    dados cadastro;
    struct elemento* prox;   // último nó (fundo) tem prox = NULL
};

typedef struct elemento Elem;   // apelido: Elem = struct elemento

// ===== DESCRITOR =====
// "Ficha" da pilha: guarda o topo, o fundo e a quantidade de nós
struct Descritor
{
    Elem* inicio;   // TOPO da pilha (onde entra e sai)
    int tamanho;    // quantos elementos tem
    Elem* fim;      // fundo (pilha não usa, mas faz parte do descritor)
};

// ===== CRIAR =====
// Cria uma pilha vazia e devolve o endereço do descritor
Descritor* criar(void)
{
    Descritor* descritor;
    descritor = (Descritor*)malloc(sizeof(Descritor));  // reserva memória pro descritor
    descritor->inicio = NULL;   // sem topo ainda
    descritor->tamanho = 0;     // vazia
    descritor->fim = NULL;

    return descritor;
}

// ===== INSERIR (PUSH) =====
// Coloca um elemento no TOPO da pilha (LIFO)
int inserirPilha(Descritor* desc, dados d)
{
    Elem* novo;
    novo = (Elem*)malloc(sizeof(Elem));   // reserva memória pro nó novo

    novo->cadastro = d;     // copia os dados pra dentro do nó
    novo->prox = NULL;

    if (desc->tamanho == 0)
    {
        // pilha vazia: o nó novo é o único, então é topo e fundo
        desc->inicio = novo;
        desc->fim = novo;
    }
    else
    {
        // ORDEM IMPORTA: primeiro liga o novo no topo antigo...
        novo->prox = desc->inicio;
        // ...depois o novo vira o topo (se invertesse, perdia a pilha)
        desc->inicio = novo;
    }
    (desc->tamanho)++;   // um elemento a mais

    return 1;
}

// ===== REMOVER (POP) =====
// Tira o elemento do TOPO e devolve os dados dele
dados removerPilha(Descritor* desc)
{
    Elem* elementoremovido;

    // dado "vazio", devolvido se a pilha não tiver nada (idade -1 é o sinal)
    dados d;
    strcpy_s(d.nome, "");
    d.idade = -1;

    // pilha vazia: sai da função, senão acessaria NULL e quebraria
    if (desc->tamanho == 0)
    {
        return d;
    }

    elementoremovido = desc->inicio;        // 1) guarda quem é o topo
    d = elementoremovido->cadastro;         // 2) salva os dados dele
    desc->inicio = elementoremovido->prox;  // 3) o de baixo vira o novo topo
    free(elementoremovido);                 // 4) libera a memória do nó antigo
    (desc->tamanho)--;                      // um elemento a menos

    return d;
}

// ===== PASSAR DE UMA PILHA PRA OUTRA =====
// Tira tudo de A e coloca em B. A ordem INVERTE (1,2,3 vira 3,2,1)
void passarPilha(Descritor* A, Descritor* B)
{
    dados aux;

    while (A->tamanho != 0)          // repete até A esvaziar
    {
        aux = removerPilha(A);       // tira do topo de A
        inserirPilha(B, aux);        // coloca no topo de B
    }
}

void listarPilha(Descritor*Pilha)
{
    Descritor*aux_PILHA = criar();
    dados aux;

    while(Pilha->tamanho != 0)
    {
        aux=  removerPilha(Pilha);
        printf("\nNOME: %s", aux.nome);
        printf("\nIDADE: %d", aux.idade);
        inserirPilha(aux_PILHA, aux);
    }

    while(aux_PILHA->tamanho != 0)
    {
        aux = removerPilha(aux_PILHA);
        inserirPilha(Pilha,aux);
    }

    free(aux_PILHA);
}