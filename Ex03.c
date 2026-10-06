#include <stdio.h>
#include <string.h>

struct contato{
    int id;
    char nome [50];
    char telefone[15];
    char label[10];

};

int main(){
    struct contato lista[100];
    int total = 0;
    int opcao = 0;

    while(1){
    printf("1 - Cadastrar contato\n");
    printf("2 - Consultar por label\n");
    printf("3 - Alterar contato\n");
    printf("4 - Gravar em arquivo\n");
    printf("5 - ler arquivo\n");
    printf("6 - Sair\n");
    scanf("%d", &opcao);

    switch(opcao){ 

        case 1:
        printf("ID: ");
        scanf("%d", &lista[total].id);
        printf("Nome: ");
        scanf("%s", lista[total].nome);
        printf("Telefone: ");
        scanf("%s", lista[total].telefone);
        printf("Label: ");
        scanf("%s", lista[total].label);

        total++;
        break;

        case 2:{

        int i = 0;
        int achou = 0;
        char lbl_busca[10]; 

        printf("Digite o contato que quer consultar por label: ");
        scanf("%s", lbl_busca);

        while(i < total){
            if(strcmp(lista[i].label, lbl_busca) == 0){
            printf("ID: %d | Nome: %s | Telefone: %s | Label: %s ", 
            lista[i].id, lista[i].nome, lista[i].telefone, lista[i].label);
            achou = 1;
            }
            i++;
        }
        if (achou == 0){
            printf("Contato não encontrado!");
        }
        break;
    }
        case 3: {
            int id_altera = 0;
            int i = 0;
            int achou = 0;

            printf("Digite o ID a ser alterado: ");
            scanf("%d", &id_altera);

            while(i < total){
            if(lista[i].id == id_altera){
            achou = 1;
            printf("ID: ");
            scanf("%d", &lista[i].id);
            printf("Nome: ");
            scanf("%s", lista[i].nome);
            printf("Telefone: ");
            scanf("%s", lista[i].telefone);
            printf("Label: ");
            scanf("%s", lista[i].label);
            }
            i++;
        }
        if(achou == 0){
            printf("ID não encontrado!");
        }
        break;
        }

        case 4:{
        FILE *arquivo = fopen("Contatos.txt", "w");

        int i = 0;
        while(i < total){
        fprintf(arquivo,"%d %s %s %s\n", lista[i].id, lista[i].nome, lista[i].telefone, lista[i].label);

        i++;
        }
        fclose(arquivo);
        break;
        }

        case 5:{
        FILE *arquivo = fopen("Contatos.txt", "r");
        
        int i = 0;
        while(fscanf(arquivo, "%d %s %s %s\n", &lista[i].id, lista[i].nome, lista[i].telefone, lista[i].label) != - 1){

        i++;
        total++;
        }
        fclose(arquivo);
        break;
        }

        case 6:{
        printf("Saindo...");
        return 0;
        }
    }
    }

    


}