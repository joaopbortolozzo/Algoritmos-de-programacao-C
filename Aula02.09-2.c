//DESENVOLVER UMA APLICACAO DE SOFTWARE
//PARA LER OS DADOS DO AQRQUIVO ALUNOS.TXT
// IMPRIMIR NA TELA
// CALCULAR A IDADE MEDIA
// O ALUNO MAIS NOVO E IDADE
// O ALUNO MAIS VELHO E IDADE
// CADA RESGISTRO EH FORMADO POR 2 CAMPOS:
// NOME
// IDADE 
//****************************************

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arq;
    
    char nome[50];
    char nomeMaisNovo[50];
    char nomeMaisVelho[50];

    int idade;
    int idadeMaisNovo;
    int idadeMaisVelho;

    int quantidade = 0;
    int somaIdades = 0;

        // [1] ABRIR O ARQUIVO
    arq = fopen("alunos.txt", "r");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // [2] LER OS DADOS
    while (fscanf(arq, "%s %d", nome, &idade) == 2)
    {
        // IMPRIMIR OS DADOS
        printf("Nome: %s | Idade: %d\n", nome, idade);

        // CALCULAR A MEDIA
        somaIdades += idade;
        quantidade++;

        // PRIMEIRO REGISTRO
        if (quantidade == 1)
        {
            idadeMaisNovo = idade;
            idadeMaisVelho = idade;

            strcpy(nomeMaisNovo, nome);
            strcpy(nomeMaisVelho, nome);
        }

        // ALUNO MAIS NOVO
        if (idade < idadeMaisNovo)
        {
            idadeMaisNovo = idade;
            strcpy(nomeMaisNovo, nome);
        }

        // ALUNO MAIS VELHO
        if (idade > idadeMaisVelho)
        {
            idadeMaisVelho = idade;
            strcpy(nomeMaisVelho, nome);
        }
    }

    // [3] RESULTADOS
    printf("\n============================\n");

    if (quantidade > 0)
    {
        printf("Idade media: %.2f\n",
               (float)somaIdades / quantidade);

        printf("Aluno mais novo: %s - %d anos\n",
               nomeMaisNovo, idadeMaisNovo);

        printf("Aluno mais velho: %s - %d anos\n",
               nomeMaisVelho, idadeMaisVelho);
    }

    // [4] FECHAR O ARQUIVO
    fclose(arq);

    return 0;


}