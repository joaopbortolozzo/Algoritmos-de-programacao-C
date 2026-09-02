#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//********************************
//GRAVAR DADOS DE UM ARQUIVO TXT
//********************************

int main()
{
    
    FILE *arq;

    char nomeAluno[100];
    char idadeAluno


    //[2] ABIR O ARQUIVO PARA OPERACOES
    arq=fopen("ALUNOS.txt", "rt");

    //[3] GRAVAR OS DADOS NO ARQUIVO
    while (!feof (arq))
    {
        //LER O NOME DO ALUNO
        fgets(buffer, 100, arq);
        strcpy(nomeAluno, buffer);
        //LER A IDADE DO ALUNO
        fgets(buffer,100,arq);
        idadeAluno=atoi(buffer);

        printd("\n%s\tIDADE: %d", nomeAluno, idadeAluno)
    }

    //[4] FECHAR ARQUIVO 
    fclose(arq);
}