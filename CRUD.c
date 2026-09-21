#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int tipo;
    char label[30];
    char descricao[100];
    int codigo;
    float valor;
} Operacao;

Operacao ops[500];
int qtd = 0;
int contador = 1;

void lancar()
{
    Operacao o;

    if (qtd >= 500) {
        printf("Limite de operacoes atingido.\n");
        return;
    }
    o.id = contador;
    printf("Tipo (1 - Deposito, 0 - Retirada): ");
    scanf("%d", &o.tipo);
    printf("Label: ");
    scanf(" %29[^\n]", o.label);
    printf("Descricao: ");
    scanf(" %99[^\n]", o.descricao);
    printf("Codigo (0 - Despesa obrigatoria, 1 - Deposito, 2 - Despesa nao obrigatoria): ");
    scanf("%d", &o.codigo);
    printf("Valor: ");
    scanf("%f", &o.valor);
    ops[qtd] = o;
    qtd++;
    contador++;
}

void imprimir(Operacao o)
{
    printf("%d | %d | %s | %s | %d | %.2f\n", o.id, o.tipo, o.label, o.descricao, o.codigo, o.valor);
}

void saldo()
{
    int i;
    float total = 0;

    for (i = 0; i < qtd; i++) {
        if (ops[i].tipo == 1) {
            total += ops[i].valor;
        } else {
            total -= ops[i].valor;
        }
    }
    printf("Saldo: %.2f\n", total);
}

void listar(int modo, int filtro)
{
    int i;
    float total = 0;

    for (i = 0; i < qtd; i++) {
        if (modo == 0 || (modo == 1 && ops[i].tipo == filtro) || (modo == 2 && ops[i].codigo == filtro)) {
            imprimir(ops[i]);
            total += ops[i].valor;
        }
    }
    printf("Valor total: %.2f\n", total);
}

void consultarLabel()
{
    int i;
    int achou = 0;
    char busca[30];

    printf("Label: ");
    scanf(" %29[^\n]", busca);
    for (i = 0; i < qtd; i++) {
        if (strcmp(ops[i].label, busca) == 0) {
            imprimir(ops[i]);
            achou = 1;
        }
    }
    if (achou == 0) {
        printf("Label nao encontrado.\n");
    }
}

void alterar()
{
    int i;
    int id;

    printf("ID da operacao: ");
    scanf("%d", &id);
    for (i = 0; i < qtd; i++) {
        if (ops[i].id == id) {
            printf("Novo tipo (1 - Deposito, 0 - Retirada): ");
            scanf("%d", &ops[i].tipo);
            printf("Novo label: ");
            scanf(" %29[^\n]", ops[i].label);
            printf("Nova descricao: ");
            scanf(" %99[^\n]", ops[i].descricao);
            printf("Novo codigo (0, 1 ou 2): ");
            scanf("%d", &ops[i].codigo);
            printf("Novo valor: ");
            scanf("%f", &ops[i].valor);
            return;
        }
    }
    printf("Operacao nao encontrada.\n");
}

void gravar()
{
    int i;
    FILE *f = fopen("fluxo.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (i = 0; i < qtd; i++) {
        fprintf(f, "%d;%d;%s;%s;%d;%.2f\n", ops[i].id, ops[i].tipo, ops[i].label, ops[i].descricao, ops[i].codigo, ops[i].valor);
    }
    fclose(f);
    printf("Dados gravados.\n");
}

void ler()
{
    FILE *f = fopen("fluxo.txt", "r");

    if (f == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }
    qtd = 0;
    while (qtd < 500 && fscanf(f, "%d;%d;%29[^;];%99[^;];%d;%f\n", &ops[qtd].id, &ops[qtd].tipo, ops[qtd].label, ops[qtd].descricao, &ops[qtd].codigo, &ops[qtd].valor) == 6) {
        qtd++;
    }
    fclose(f);
    contador = qtd + 1;
    printf("Dados carregados.\n");
}

int main()
{
    int op;
    int x;

    do {
        printf("\n1 - Lancar operacao\n");
        printf("2 - Consultar saldo\n");
        printf("3 - Listar todas\n");
        printf("4 - Listar por tipo\n");
        printf("5 - Listar por codigo\n");
        printf("6 - Consultar por label\n");
        printf("7 - Alterar operacao\n");
        printf("8 - Gravar em arquivo\n");
        printf("9 - Ler do arquivo\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                lancar();
                break;
            case 2:
                saldo();
                break;
            case 3:
                listar(0, 0);
                break;
            case 4:
                printf("Tipo (1 - Deposito, 0 - Retirada): ");
                scanf("%d", &x);
                listar(1, x);
                break;
            case 5:
                printf("Codigo (0, 1 ou 2): ");
                scanf("%d", &x);
                listar(2, x);
                break;
            case 6:
                consultarLabel();
                break;
            case 7:
                alterar();
                break;
            case 8:
                gravar();
                break;
            case 9:
                ler();
                break;
        }
    } while (op != 0);

    return 0;
}