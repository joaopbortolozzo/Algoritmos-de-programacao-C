#include <stdio.h>
#include <string.h>

struct contato{
    int id;
    char nome[50];
    char telefone[10];
    char label[10];
};

int main(){

    struct contato lista[100];
    int total = 0;
    int opcao = 0;

    while(1){
        printf("1 - Cadastrar contato\n");
        printf("2 - Consultar label\n");
        printf("3 - Alterar contato\n");
        printf("4 - Gravar em Arquivo\n");
        printf("5 - Ler arquivo\n");
        printf("6 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:{
            printf("Digite o ID: ");
            scanf("%d", lista[total].id);
            printf("Digite o seu nome: ");
            scanf("%s", lista[total].nome);
            printf("Digite o telefone: ");
            scanf("%s", lista[total].telefone);
            printf("Digite a label: ");
            scanf("%s", lista[total].label);

            total++;
            break;
            }

            case 2:

            int i = 0;
            int achou = 0;
            char lbl_busca = [10];

            printf("Digite o contato que quer consultar na label: ");
            printf("%s", lbl_busca);

            while(i < total){
                if(strcmp(lista[i].label, lbl_busca) == 0){
                printf("ID: %d| Nome: %s| Telefone: %s| Label: %s",
                lista[i].id, lista[i].nome, lista[i].telefone, lista[i].label);
                achou = 1;
                i++;
                }
            }
            if(achou == 0){
            printf("Contato não encontrado!");
            }
            break;

            case 3:{
            int id_altera = 0;
            int i = 0;
            int achou = 0;

            printf("Digite o id que deseja alterar: ");
            scanf("%d", &id_altera);

            while(i < total){
                if(lista[i].id == id_altera){
                    printf("ID: %d | Nome: %s | Telfone: %s | Label: %s",
                    lista[i].id, lista[i].nome, lista[i].telefone, lista[i].label);
                    achou = 1;
                }
                i++;


                if(achou == 0){
                    printf("id não encontrado!");
                };
                break;
            }
            }

            case 4:{
            FILE *arquivo = fopen("Contatos.txt", "w");

            int i = 0;
            while(i < total){
            fprintf(arquivo, "%d %s %s %s\n", lista[i].id, lista[i].nome, lista[i].telefone, lista[i].label);

            i++;
            }
            fclose(arquivo);
            break;
        }

            case 5: {
                FILE*arquivo = fopen("Contatos.txt", "w");

                int i = 0;

                while(fscanf(arquivo, "%d %s %s %s", lista[i].id, lista[i].nome, lista[i].telefone, lista[i].label)){

                    i++;
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