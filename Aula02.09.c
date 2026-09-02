#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//********************************
//GRAVAR DADOS DE UM ARQUIVO TXT
//********************************

int main()
{
    float notas[100]={8.5, 4.5, 9, 7.5, 6.5};
    int nNotas=5;

    //[1] DEFINIR O PONTEIRO DO ARQUIVO
    // FILE * arq
    FILE *arq;

    //[2] ABIR O ARQUIVO PARA OPERACOES
    arq=fopen("notasWRITE001.txt", "wt");

    //[3] GRAVAR OS DADOS NO ARQUIVO
    for (int pos=0; pos < nNotas; pos++)
    {
        fprintf(arq,"%.2f\n", notas[pos]);
        //fprintf(arq,"%.2f", notas[pos]);
    }

    //[4] FECHAR ARQUIVO 
    fclose(arq);
}