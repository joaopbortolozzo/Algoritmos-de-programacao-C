#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct produto{
    int codigo;
    char nome[30];
    int categoria;
    int quantidade;
    float valor;
};

struct produto dt[100];
int cont;

void cadastrar(){

    char buffer[100];

    printf("Digite o codigo para cadastro: ");
    fgets(buffer, 100, stdin);
    dt[cont].codigo = atoi (buffer);

    printf("Digite o nome do produto: ");
    fgets(dt[cont].nome, 30, stdin);
    dt[cont].nome[strlen(dt[cont].nome) - 1] = '\0';
    
    printf("Digite a categoria do produto: ");
    fgets(buffer, 100, stdin);
    dt[cont].categoria = atoi (buffer);

    printf("Digite a quantidade do produto: ");
    fgets(buffer, 100, stdin);
    dt[cont].quantidade = atoi (buffer);

    printf("Digite o valor do produto: ");
    fgets(buffer, 100, stdin);
    dt[cont].valor = atof (buffer);

    cont++;
}

void alterar(){
    int i = 0;
    int achou = 0;
    char buffer[100];
    int cod_altera = atoi(buffer);

    printf("Digite o código que deseja alterar: ");
    fgets(buffer, 100, stdin);
    
    while

    

    

}

