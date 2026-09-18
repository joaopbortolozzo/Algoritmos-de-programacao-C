#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct DADOS
{
    int id;
    int operacao;
    char label[100];
    char desc[100];
    int cod;
    float valor;
};

struct DADOS dt[100];
int cont;

void cadastrar() {

    char buffer[100];

    dt[cont].id = cont;

    printf("\nInsira o tipo de operacao [1 - Deposito ou entrada de valores | 0 - Retirada ou pagamento]: ");
    fgets(buffer, 100, stdin);
    dt[cont].operacao = atoi(buffer);
   
    printf("\nDefina uma label para tal operacao: ");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(dt[cont].label, buffer);
   
    printf("\nDefina uma descricao para tal operacao: ");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(dt[cont].desc, buffer);

    printf("\nInsira o codigo de operacao [0 - Despesas obrigatorias | 1 - Depositos | 2 - Pagamentos por despesas nao obrigatorias]: ");
    fgets(buffer, 100, stdin);
    dt[cont].cod = atoi(buffer);
   
    printf("\nInsira o valor da operacao: ");
    fgets(buffer, 100, stdin);
    dt[cont].valor = atof(buffer);
   
    cont++;
}

void ler_tudo() {
    char buffer[100];
    FILE *file;
    file = fopen("crud.txt", "rt");

    if (file == NULL) {
        printf("\nArquivo nao encontrado!");
        return;
    }

    while (fgets(buffer, 100, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void salvar() {
    FILE *file;
    file = fopen("crud.txt", "wt");

    if (file == NULL) {
        printf("\nErro ao abrir o arquivo!");
        return;
    }

    for (int i = 0; i < cont; i++) {
        fprintf(file, "%d\n", dt[i].id);
        fprintf(file, "%d\n", dt[i].operacao);
        fprintf(file, "%s\n", dt[i].label);
        fprintf(file, "%s\n", dt[i].desc);
        fprintf(file, "%d\n", dt[i].cod);
        fprintf(file, "%.2f\n", dt[i].valor);
    }

    fclose(file);

    printf("\nArquivo salvo!");
}

void salvar_struct() {
    FILE *file;
    char buffer[100];

    file = fopen("C:\\Users\\26002725\\Desktop\\Aula\\crud.txt", "rt");

    if (file == NULL) {
        printf("\nArquivo nao encontrado!");
        return;
    }

    cont = 0;

    while (cont < 100 && fgets(buffer, 100, file) != NULL) {

        dt[cont].id = atoi(buffer);

        fgets(buffer, 100, file);
        dt[cont].operacao = atoi(buffer);

        fgets(buffer, 100, file);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(dt[cont].label, buffer);

        fgets(buffer, 100, file);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(dt[cont].desc, buffer);

        fgets(buffer, 100, file);
        dt[cont].cod = atoi(buffer);

        fgets(buffer, 100, file);
        dt[cont].valor = atof(buffer);

        cont++;
    }

    fclose(file);

    printf("\nDados carregados!");

}

void consultar_saldo() {
    float saldo = 0;
    for (int i = 0; i < cont; i++) {
        if (dt[i].operacao == 1) {
            saldo += dt[i].valor;
        }
        else {
            saldo -= dt[i].valor;
        }
    }

    printf("\nSaldo atual: R$ %.2f\n", saldo);
}

void consultar_operacoes() {
    float valor_total = 0;
    for (int i = 0; i < cont; i++) {
        printf("--------OPERACAO %d----------\n", i+1);
        printf("ID: %d", dt[i].id);
        printf("\nTipo: %d", dt[i].operacao);
        printf("\nLabel: %s", dt[i].label);
        printf("\nDescricao: %s", dt[i].desc);
        printf("\nCodigo: %d", dt[i].cod);
        printf("\nValor: %.2f", dt[i].valor);
        printf("\n------------------\n");

        valor_total += dt[i].valor;
    }
    printf("\nValor Total: %.2f", valor_total);
}

void listar_tipo() {
    int escolha_tipo;
    float valor_total = 0;
    printf("Escolha o tipo de operacao que quer consultar [1 - Deposito ou entrada de valores | 0 - Retirada ou pagamento]: ");
    scanf("%d", &escolha_tipo);

    if (escolha_tipo != 0 && escolha_tipo != 1) {
        printf("Valor invalido!");
        return;
    }

    for (int i = 0; i < cont; i++) {
        if(dt[i].operacao == escolha_tipo) {
            printf("--------OPERACAO %d----------\n", i+1);
            printf("ID: %d", dt[i].id);
            printf("\nTipo: %d", dt[i].operacao);
            printf("\nLabel: %s", dt[i].label);
            printf("\nDescricao: %s", dt[i].desc);
            printf("\nCodigo: %d", dt[i].cod);
            printf("\nValor: %.2f", dt[i].valor);
            printf("\n------------------\n");

            valor_total += dt[i].valor;
        }
    }
    printf("\nValor Total: %.2f", valor_total);
}

void listar_cod() {
    int escolha_cod;
    float valor_total = 0;
    printf("Escolha o codigo de operacao que quer consultar [0 - Despesas obrigatorias | 1 - Depositos | 2 - Pagamentos por despesas nao obrigatorias]: ");
    scanf("%d", &escolha_cod);
   
    if (escolha_cod < 0 || escolha_cod > 2) {
        printf("Valor invalido!");
        return;
    }
   
    for (int i = 0; i < cont; i++) {
        if(dt[i].cod == escolha_cod) {
            printf("--------OPERACAO %d----------\n", i+1);
            printf("ID: %d", dt[i].id);
            printf("\nTipo: %d", dt[i].operacao);
            printf("\nLabel: %s", dt[i].label);
            printf("\nDescricao: %s", dt[i].desc);
            printf("\nCodigo: %d", dt[i].cod);
            printf("\nValor: %.2f", dt[i].valor);
            printf("\n------------------\n");

            valor_total += dt[i].valor;
        }
    }
    printf("\nValor Total: %.2f", valor_total);
}  

void consultar_label() {
    char label_consulta[100];
    printf("Insira a label que quer consultar: ");
    fgets(label_consulta, 100, stdin);
    label_consulta[strlen(label_consulta) - 1] = '\0';

    for(int i = 0; i < cont; i++) {
        if(strcmp(label_consulta, dt[i].label) == 0) {
            printf("ID: %d", dt[i].id);
            printf("\nTipo: %d", dt[i].operacao);
            printf("\nLabel: %s", dt[i].label);
            printf("\nDescricao: %s", dt[i].desc);
            printf("\nCodigo: %d", dt[i].cod);
            printf("\nValor: %.2f", dt[i].valor);
            printf("\n------------------\n");
        }
    }
}

void alterar() {
    int id_altera;
    int encontrou = 0;
    char buffer[100];
    printf("Insira o ID da operacao que quer alterar: ");
    scanf("%d", &id_altera);
    getchar();

    for(int i = 0; i < cont; i++) {
        if (dt[i].id == id_altera) {
            encontrou = 1;

            printf("\nInsira o tipo de operacao [1 - Deposito ou entrada de valores | 0 - Retirada ou pagamento]: ");
            fgets(buffer, 100, stdin);
            dt[i].operacao = atoi(buffer);
       
            printf("\nDefina uma label para tal operacao: ");
            fgets(buffer, 100, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            strcpy(dt[i].label, buffer);
           
            printf("\nDefina uma descricao para tal operacao: ");
            fgets(buffer, 100, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            strcpy(dt[i].desc, buffer);

            printf("\nInsira o codigo de operacao [0 - Despesas obrigatorias | 1 - Depositos | 2 - Pagamentos por despesas nao obrigatorias]: ");
            fgets(buffer, 100, stdin);
            dt[i].cod = atoi(buffer);
           
            printf("\nInsira o valor da operacao: ");
            fgets(buffer, 100, stdin);
            dt[i].valor = atof(buffer);
        }  
    }

    if (encontrou == 0) {
        printf("\nOperacao nao encontrada!");
        return;
    }
}


int main() {
    salvar_struct();
    int escolha = -1;

    while (escolha != 0) {

        printf("\n===== MENU =====\n");
        printf("1 - Efetuar lancamento\n");
        printf("2 - Consultar saldo\n");
        printf("3 - Listar todas as operacoes\n");
        printf("4 - Listar por tipo\n");
        printf("5 - Listar por codigo\n");
        printf("6 - Consultar por Label\n");
        printf("7 - Alterar operacao\n");
        printf("8 - Gravar dados em arquivo\n");
        printf("9 - Ler dados do arquivo\n");
        printf("0 - Sair\n");
        printf("Lembre-se de salvar antes de sair!\n");

        printf("\nEscolha: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {

            case 1:
                cadastrar();
                break;

            case 2:
                consultar_saldo();
                break;

            case 3:
                consultar_operacoes();
                break;

            case 4:
                listar_tipo();
                break;

            case 5:
                listar_cod();
                break;

            case 6:
                consultar_label();
                break;

            case 7:
                alterar();
                break;

            case 8:
                salvar();
                salvar_struct();
                break;

            case 9:
                ler_tudo();
                break;

            case 0:
                printf("\nSaindo...");
                break;

            default:
                printf("\nOpcao invalida!");
        }
    }
    return 0;
}