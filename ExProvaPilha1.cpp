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
// Coloca um elemento no TOPO da pilha (LIFO: o último a entrar é o primeiro a sair)
// Recebe o descritor da pilha (desc) e os dados a guardar (d). Retorna 1 se deu certo.
int inserirPilha(Descritor* desc, dados d)
{
    Elem* novo;                            // ponteiro que vai apontar pro nó novo
    novo = (Elem*)malloc(sizeof(Elem));    // aloca memória pro nó e guarda o endereço em "novo"

    novo->cadastro = d;                    // copia os dados recebidos pra dentro do nó
    novo->prox = NULL;                     // por segurança, o nó nasce apontando pra nada

    if (desc->tamanho == 0)                // a pilha está vazia?
    {
        desc->inicio = novo;               // o nó novo é o topo (início)
        desc->fim = novo;                  // e também o fundo (fim), pois é o único
    }
    else                                   // a pilha já tem elementos
    {
        novo->prox = desc->inicio;         // 1º) o novo aponta pro topo antigo (liga na pilha)
        desc->inicio = novo;               // 2º) o novo passa a ser o topo
                                           // (se invertesse a ordem, perderia a pilha)
    }
    (desc->tamanho)++;                     // incrementa o contador: um elemento a mais

    return 1;                              
}

// ===== REMOVER (POP) =====
// Tira o elemento do TOPO e devolve os dados dele
dados removerPilha(Descritor* desc)
{
    Elem* elementoremovido;                // ponteiro auxiliar pra guardar o nó que sairá

    dados d;                               // variável que será devolvida
    strcpy_s(d.nome, "");                  // nome vazio (valor padrão de "nada encontrado")
    d.idade = -1;                          // idade -1 é o sinal de que a pilha estava vazia

    if (desc->tamanho == 0)                // pilha vazia?
    {
        return d;                          // sai já devolvendo o dado "vazio"; evita acessar NULL
    }

    elementoremovido = desc->inicio;        // 1) guarda quem é o topo atual
    d = elementoremovido->cadastro;         // 2) salva os dados do topo pra devolver depois
    desc->inicio = elementoremovido->prox;  // 3) o elemento de baixo vira o novo topo
    free(elementoremovido);                 // 4) libera a memória do nó antigo (evita vazamento)
    (desc->tamanho)--;                      // decrementa o contador: um elemento a menos

    return d;                               // devolve os dados do elemento removido
}

// ===== PASSAR DE UMA PILHA PRA OUTRA =====
// Tira tudo de A e coloca em B. A ordem INVERTE (1,2,3 vira 3,2,1)
void passarPilha(Descritor* A, Descritor* B)
{
    dados aux;                             // variável temporária pra carregar cada elemento

    while (A->tamanho != 0)                // repete enquanto A tiver elementos
    {
        aux = removerPilha(A);             // tira o topo de A e guarda em aux
        inserirPilha(B, aux);              // coloca aux no topo de B
    }
}

// ===== LISTAR =====
// Mostra todos os elementos sem perder a pilha original
void listarPilha(Descritor* Pilha)
{
    Descritor* aux_PILHA = criar();        // cria uma pilha auxiliar vazia

    dados aux;                           // variável temporária

    while (Pilha->tamanho != 0)            // 1ª fase: esvazia a pilha original
    {
        aux = removerPilha(Pilha);         // tira o topo da original
        printf("\nNOME: %s", aux.nome);    // mostra o nome
        printf("\nIDADE: %d", aux.idade);  // mostra a idade
        inserirPilha(aux_PILHA, aux);      // guarda na auxiliar (ordem fica invertida lá)
    }

    while (aux_PILHA->tamanho != 0)        // 2ª fase: devolve tudo pra pilha original
    {
        aux = removerPilha(aux_PILHA);     // tira da auxiliar
        inserirPilha(Pilha, aux);          // recoloca na original (inverte de novo = ordem original)
    }

    free(aux_PILHA);                       // libera o descritor da auxiliar (ela já está vazia)
}

void consultarPilha(Descritor*Pilha, char nomeprocurado[])
{
    Descritor*auxPILHA = criar(); // pilha auxiliar vazia
    dados aux;
    int achou = 0;                // 0 = "ainda não achei"

    // FASE 1: tirar, comparar e guardar
    while(Pilha->tamanho != 0)
    {
        aux=removerPilha(Pilha); // tira do topo

        if(strcmp(nomeprocurado, aux.nome)== 0) // strcmp devolve 0 se iguais
        {
            printf("\nNome: %s", aux.nome);
            printf("\nIdade: %d", aux.idade);
            achou = 1;  // marca que achou
        }

        inserirPilha(auxPILHA,aux); // FORA do if: todo elemento precisa ser guardado
    }

    // FASE 2: devolver pra Pilha
    while(auxPILHA->tamanho != 0)
    {
        aux=removerPilha(auxPILHA);
        inserirPilha(Pilha,aux);
    }

    if(achou == 0) // só depois de olhar TODOS dá pra dizer que não achou
    {
        printf("\nNome não encontrado!");
    }

    free(auxPILHA);
}

void passarMaiores(Descritor*A, Descritor*B)
{
    Descritor*auxPILHA = criar(); // pilha auxiliar vazia
    dados aux;

    // FASE 1: tirar de A, filtrar pra B, guardar TODOS na auxiliar
    while(A->tamanho != 0)
    {
        aux=removerPilha(A); // tira do topo de A

        if(aux.idade >= 18) // use > 18 se o enunciado disser "maiores de 18"
        {
            inserirPilha(B, aux); // só quem passa no filtro vai pra B
        }

        inserirPilha(auxPILHA, aux); // FORA do if: A precisa voltar completa
}

    // FASE 2: devolver tudo pra A
    while(auxPILHA->tamanho != 0) 
    {
        aux=removerPilha(auxPILHA);
        inserirPilha(A, aux); // atenção: é A, não "Pilha"
    }

    free(auxPILHA);

}

