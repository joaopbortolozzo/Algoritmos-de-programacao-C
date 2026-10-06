#include <stdio.h>
#include <string.h>

struct produto{
    int codigo;
    char nome[50];
    int categoria;
    int quantidade;
    float valor_unitario;
};

int main(){
    struct produto lista[100];
    int total = 0;
    int opcao;

    while(1){
    
    printf("1 - Lançar produto\n");
    printf("2 - Listar todos (valor total)\n");
    printf("3 - Listar por categoria (valor total)\n");
    printf("4 - Alterar produto\n");
    printf("5 - Sair\n");
    scanf("%d", &opcao);

        switch(opcao){

            case 1:

            printf("Codigo: ");
            scanf("%d", &lista[total].codigo);
            printf("Nome: ");
            scanf("%s", lista[total].nome);
            printf("Categoria: ");
            scanf("%d", &lista[total].categoria);
            printf("Quantidade: ");
            scanf("%d", &lista[total].quantidade);
            printf("Valor Unitário: ");
            scanf("%f", &lista[total].valor_unitario);

            total++;
            break;

            case 2:{

            int i = 0;
            float soma = 0;

            while(i < total){
                printf("Codigo: %d | Nome: %s | Categoria: %d | Quantidade: %d | Valor unitário: %.2f\n",
                lista[i].codigo, lista[i].nome, lista[i].categoria, lista[i].quantidade, lista[i].valor_unitario);
                soma += lista[i].valor_unitario * lista[i].quantidade;
                i++;
                }
            
            printf("O valor total é: %.2f\n", soma);
            break;
        }        

            case 3:{
                int ct_busca = 0;
                int i = 0;
                float soma = 0;
                int achou = 0;

                printf("Digite a categoria que está buscando: ");
                scanf("%d", &ct_busca);

                while(i < total){
                    if(lista[i].categoria == ct_busca){
                        printf("Codigo: %d | Nome: %s | Categoria: %d | Quantidade: %d | Valor unitário: %.2f\n",
                        lista[i].codigo, lista[i].nome, lista[i].categoria, lista[i].quantidade, lista[i].valor_unitario);
                        achou = 1;
                        soma += lista[i].valor_unitario * lista[i].quantidade;
                        printf("Categoria encontrada!");
                    }
                    i++;
                }
                if(achou == 0){
                        printf("Nenhum produto encontrado nessa categoria");
                    }
                printf("Valor total: %.2f\n", soma);
                break;
            }

            case 4:{
                int ct_altera = 0;
                int i = 0;
                int achou = 0;

                printf("Digite o codigo a ser alterado: ");
                scanf("%d", &ct_altera);

                while(i < total){
                    if (lista[i].codigo == ct_altera){
                        achou = 1;
                        printf("Codigo: ");
                        scanf("%d", &lista[i].codigo);
                        printf("Nome: ");
                        scanf("%s", lista[i].nome);
                        printf("Categoria: ");
                        scanf("%d", &lista[i].categoria);
                        printf("Quantidade: ");
                        scanf("%d", &lista[i].quantidade);
                        printf("Valor Unitário: ");
                        scanf("%f", &lista[i].valor_unitario);

                        printf("Produto alterado com sucesso!");
                    }
                    i++;
                }
                if (achou == 0){
                    printf("Nenhum codigo encontrado!");
                }
                break;
            }

               case 5:
               printf("Saindo...");
               return 0; 

               default:
               printf("Opção inválida!");
               break;

        }


    }
    
    

}