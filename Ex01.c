#include <stdio.h>
#include <string.h>

struct livro{
    int id;
    char titulo[50];
    char autor[30];
    int ano;
    float preco;
};

int main(){
    struct livro lista[100];
    int total=0;
    int opcao;
    


    while(1){
        printf("------ MENU ------\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar todos os livros com valor total\n");
        printf("3 - Buscar livro por id\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);
    

    
    switch (opcao){

        case 1:
        printf("ID: ");
        scanf("%d", &lista[total].id);
        printf("Título: ");
        scanf("%s", lista[total].titulo);
        printf("Autor: ");
        scanf("%s", lista[total].autor);
        printf("Ano: ");
        scanf("%d", &lista[total].ano);
        printf("Preço: ");
        scanf("%f", &lista[total].preco);
        total++;
        break;

        case 2:
            int i = 0;
            float soma = 0;
            while(i < total){
                printf("ID: %d | Título: %s | Autor: %s | Ano: %d | Preço: %.2f\n",
                lista[i].id, lista[i].titulo, lista[i].autor, lista[i].ano, lista[i].preco);
                soma += lista[i].preco;
                i++;
            }
            printf("Valor total: %.2f\n", soma);
            break;

        case 3:{
            int id_busca;
            int achou=0;
            int i = 0;
            
            printf("Digite o ID que deseja buscar: ");
            scanf("%d", &id_busca);

            while(i < total){
                if (lista[i].id == id_busca){
                    printf("ID: %d | Título: %s | Autor: %s | Ano: %d | Preço: %.2f\n",
                    lista[i].id, lista[i].titulo, lista[i].autor, lista[i].ano, lista[i].preco);
                    achou = 1;

                }  
                   i++; 
                }
                if (achou == 0){
                    printf("ID diferente");
                }
                break;
                
            }

        case 4:
            printf("Saindo...");
            return 0;
    }       

        
            
        
}
}




