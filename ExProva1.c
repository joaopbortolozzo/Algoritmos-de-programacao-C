#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogador{
    int id;
    char nome[50];
    char posicao[20];
    int numero_camisa;
    int gols;
};

struct jogador tf[30];
int cont;

void cadastrar_jogador(){

    char buffer[100];

    tf[cont].id = cont;

    printf("Nome do Jogador: ");
    fgets(buffer,100,stdin);
    strcpy(tf[cont].nome, buffer);

    printf("Posição do Jogador: ");
    fgets(buffer,100,stdin);
    strcpy(tf[cont].posicao, buffer);

    printf("Numero da camisa do jogador: ");
    fgets(buffer,100,stdin);
    tf[cont].numero_camisa = atoi(buffer);
    
    printf("Gols do jogador: ");
    fgets(buffer,100,stdin);
    tf[cont].gols = atoi(buffer);

    cont++;

}

void listar_jogadores(){
    for(int i = 0; i < cont; i++ ){
        printf("ID: %d", tf[i].id);
        printf("\nNome: %s ", tf[i].nome);
        printf("\nPosição: %s", tf[i].posicao);
        printf("\nNumero da Camisa: %d", tf[i].numero_camisa);
        printf("\nGols: %d", tf[i].gols);


    }


void alterar_jogador(){
    int id_altera;
    int encontrou = 0;
    char buffer[100];
    printf("Insira po ID do jogador que deseja alterar: ");
    scanf("%d", &id_altera);
    getchar();

    for(int i= 0; i < cont; i++){
        if (tf[i].id == id_altera){
            encontrou = 1;

            printf("Nome jogador: ");
            fgets(buffer,100,stdin);
            strcpy(tf[i].nome,buffer);

            printf("Posição: ");
            fgets(buffer,100,stdin);
            strcpy(tf[i].posicao,buffer);

            printf("Numero camisa: ");
            fgets(buffer,100,stdin);
            tf[i].numero_camisa = atoi(buffer);

            printf("Gols: ");
            fgets(buffer,100,stdin);
            tf[i].gols = atoi(buffer);


        }
    }
    if (encontrou == 0){
        printf("Jogador não encontrado");
        return;
    }
}

}