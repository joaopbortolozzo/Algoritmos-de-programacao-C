#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados {
    char marca[20];
    char modelo[20];
    int anoFabricacao;
    char cor[20];
    int chassi;
};

struct elementos {
    struct dados cadastro;
    struct elementos *prox;
};

struct descritor {
    struct elementos *inicio;
    struct elementos *fim;
    int tamanho;
    int indexador;
};

struct descritor *Criar(void) {
    struct descritor *desc;
    desc = (struct descritor *) malloc(sizeof(struct descritor));
    desc->inicio = NULL;
    desc->fim = NULL;
    desc->tamanho = 0;
    desc->indexador = -1;
    return desc;
}

/* le os dados do teclado e devolve um elemento novo */
struct elementos *lerElemento(void) {
    struct elementos *novo;
    novo = (struct elementos *) malloc(sizeof(struct elementos));

    printf("Digite a marca: ");
    scanf("%s", novo->cadastro.marca);
    printf("Digite o modelo: ");
    scanf("%s", novo->cadastro.modelo);
    printf("Digite o ano de fabricacao: ");
    scanf("%d", &novo->cadastro.anoFabricacao);
    printf("Digite a cor: ");
    scanf("%s", novo->cadastro.cor);
    printf("Digite o chassi: ");
    scanf("%d", &novo->cadastro.chassi);

    novo->prox = NULL;
    return novo;
}

void mostrar(struct elementos *e) {
    printf("Marca: %s\n", e->cadastro.marca);
    printf("Modelo: %s\n", e->cadastro.modelo);
    printf("Ano Fabricacao: %d\n", e->cadastro.anoFabricacao);
    printf("Cor: %s\n", e->cadastro.cor);
    printf("Chassi: %d\n", e->cadastro.chassi);
    printf("-------------------\n");
}

/* insere no final */
void inserirLista(struct descritor *desc) {
    struct elementos *novo = lerElemento();

    if (desc->inicio == NULL) {
        desc->inicio = novo;
        desc->fim = novo;
    } else {
        desc->fim->prox = novo;
        desc->fim = novo;
    }
    desc->tamanho++;
}

void inserirInicioLista(struct descritor *desc) {
    struct elementos *novo = lerElemento();

    if (desc->inicio == NULL) {
        desc->inicio = novo;
        desc->fim = novo;
    } else {
        novo->prox = desc->inicio;
        desc->inicio = novo;
    }
    desc->tamanho++;
}

/* pos = 1 e o primeiro elemento */
void inserirMeioLista(struct descritor *desc) {
    int pos, i;
    struct elementos *novo, *ant;

    printf("Digite a posicao (1 a %d): ", desc->tamanho + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > desc->tamanho + 1) {
        printf("Posicao invalida!\n");
        return;
    }

    novo = lerElemento();

    if (pos == 1) {                        /* vira o primeiro */
        novo->prox = desc->inicio;
        desc->inicio = novo;
        if (desc->fim == NULL)             /* lista estava vazia */
            desc->fim = novo;
    } else if (pos == desc->tamanho + 1) { /* vira o ultimo */
        desc->fim->prox = novo;
        desc->fim = novo;
    } else {                               /* meio */
        ant = desc->inicio;
        for (i = 1; i < pos - 1; i++)
            ant = ant->prox;
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    desc->tamanho++;
}

void listar(struct descritor *desc) {
    struct elementos *aux = desc->inicio;

    if (aux == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    while (aux != NULL) {
        mostrar(aux);
        aux = aux->prox;
    }
}

void listarCOR(struct descritor *desc) {
    char cor[20];
    int achou = 0;
    struct elementos *aux = desc->inicio;

    printf("Digite a cor: ");
    scanf("%s", cor);

    while (aux != NULL) {
        if (strcmp(aux->cadastro.cor, cor) == 0) {
            mostrar(aux);
            achou = 1;
        }
        aux = aux->prox;
    }
    if (!achou)
        printf("Nenhum veiculo dessa cor.\n");
}

void listarANOFABRICACAO(struct descritor *desc) {
    int anoInicial, anoFinal, achou = 0;
    struct elementos *aux = desc->inicio;

    printf("Digite o ano inicial: ");
    scanf("%d", &anoInicial);
    printf("Digite o ano final: ");
    scanf("%d", &anoFinal);

    while (aux != NULL) {
        if (aux->cadastro.anoFabricacao >= anoInicial &&
            aux->cadastro.anoFabricacao <= anoFinal) {
            mostrar(aux);
            achou = 1;
        }
        aux = aux->prox;
    }
    if (!achou)
        printf("Nenhum veiculo nessa faixa de ano.\n");
}

void consultarCHASSI(struct descritor *desc) {
    int chassi;
    struct elementos *aux = desc->inicio;

    printf("Digite o chassi: ");
    scanf("%d", &chassi);

    while (aux != NULL) {
        if (aux->cadastro.chassi == chassi) {
            mostrar(aux);
            return;
        }
        aux = aux->prox;
    }
    printf("Chassi nao encontrado.\n");
}

/* remove o elemento de uma posicao (1 = primeiro) */
void deletarItemLista(struct descritor *desc) {
    int pos, i;
    struct elementos *aux, *ant;

    if (desc->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Digite a posicao a remover (1 a %d): ", desc->tamanho);
    scanf("%d", &pos);

    if (pos < 1 || pos > desc->tamanho) {
        printf("Posicao invalida!\n");
        return;
    }

    if (pos == 1) {                         /* remove o primeiro */
        aux = desc->inicio;
        desc->inicio = aux->prox;
        if (desc->inicio == NULL)           /* lista ficou vazia */
            desc->fim = NULL;
    } else {                                /* remove do meio ou do fim */
        ant = desc->inicio;
        for (i = 1; i < pos - 1; i++)
            ant = ant->prox;
        aux = ant->prox;                    /* o que sera removido */
        ant->prox = aux->prox;
        if (aux == desc->fim)               /* removeu o ultimo */
            desc->fim = ant;
    }

    free(aux);
    desc->tamanho--;
    printf("Item removido.\n");
}

void listarMODELO(struct descritor *desc) {
    char modelo[20];
    int achou = 0;
    struct elementos *aux = desc->inicio;

    printf("Digite o modelo: ");
    scanf("%s", modelo);

    while (aux != NULL) {
        if (strcmp(aux->cadastro.modelo, modelo) == 0) {
            mostrar(aux);
            achou = 1;
        }
        aux = aux->prox;
    }
    if (!achou)
        printf("Nenhum veiculo desse modelo.\n");
}

void listarMARCA(struct descritor *desc) {
    char marca[20];
    int achou = 0;
    struct elementos *aux = desc->inicio;

    printf("Digite a marca: ");
    scanf("%s", marca);

    while (aux != NULL) {
        if (strcmp(aux->cadastro.marca, marca) == 0) {
            mostrar(aux);
            achou = 1;
        }
        aux = aux->prox;
    }
    if (!achou)
        printf("Nenhum veiculo dessa marca.\n");
}

/* localiza pelo chassi e troca os dados */
void alterarCadastro(struct descritor *desc) {
    int chassi;
    struct elementos *aux = desc->inicio;

    printf("Digite o chassi do veiculo a alterar: ");
    scanf("%d", &chassi);

    while (aux != NULL && aux->cadastro.chassi != chassi)
        aux = aux->prox;

    if (aux == NULL) {
        printf("Chassi nao encontrado.\n");
        return;
    }

    printf("Dados atuais:\n");
    mostrar(aux);

    printf("Digite os novos dados:\n");
    printf("Marca: ");
    scanf("%s", aux->cadastro.marca);
    printf("Modelo: ");
    scanf("%s", aux->cadastro.modelo);
    printf("Ano de fabricacao: ");
    scanf("%d", &aux->cadastro.anoFabricacao);
    printf("Cor: ");
    scanf("%s", aux->cadastro.cor);
    printf("Chassi: ");
    scanf("%d", &aux->cadastro.chassi);

    printf("Cadastro alterado.\n");
}

int main(void) {
    struct descritor *desc = Criar();
    int op;

    do {
        printf("\n1 - Inserir no fim\n");
        printf("2 - Inserir no inicio\n");
        printf("3 - Inserir em uma posicao\n");
        printf("4 - Listar todos\n");
        printf("5 - Listar por cor\n");
        printf("6 - Listar por faixa de ano\n");
        printf("7 - Consultar chassi\n");
        printf("8 - Remover item de uma posicao\n");
        printf("9 - Listar por modelo\n");
        printf("10 - Listar por marca\n");
        printf("11 - Alterar cadastro\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:  
            inserirLista(desc); 
            break;

            case 2:  
            inserirInicioLista(desc); 
            break;

            case 3:  
            inserirMeioLista(desc); 
            break;

            case 4:  
            listar(desc); 
            break;

            case 5:  
            listarCOR(desc); 
            break;

            case 6:  
            listarANOFABRICACAO(desc); 
            break;

            case 7:  
            consultarCHASSI(desc); 
            break;

            case 8:  
            deletarItemLista(desc); 
            break;

            case 9:  
            listarMODELO(desc);
            break;

            case 10: 
            listarMARCA(desc); 
            break;

            case 11: 
            alterarCadastro(desc); 
            break;

            case 0:  
            printf("Encerrando...\n"); 
            break;
            
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}