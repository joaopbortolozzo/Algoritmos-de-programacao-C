#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

struct livro {
    int id;
    char titulo[100];
    char autor [100];
    int ano;
    float preco;
};

struct livro cl [50];
int cont;
char buffer[100];

void cadastrar_livro(){
    printf("Digite título do livro: ");
    fgets(buffer, 100, stdin);
    strcpy(cl[cont].titulo, buffer);
    printf("Digite o autor do livro: ");
    fgets(buffer, 100, stdin);
    strcpy(cl[cont].autor, buffer);
    printf("Digite o ano do livro: ");
    fgets(buffer, 100, stdin);
    cl[cont].ano = atoi(buffer);
    printf("Digite o preço do livro: ");
    fgets(buffer, 100, stdin);
    cl[cont].preco = atof(buffer);

    cont = cont + 1;

}
}