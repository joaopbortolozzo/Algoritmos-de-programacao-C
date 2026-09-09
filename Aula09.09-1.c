#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIR UMA ESTRUTURA DE DADOS
// CONTENDO AS SEGUINTES INFORMAÇÕES
//
// NOME DO ALUNO
// CÓDIGO DO CURSO
// COEFICIENTE DE RENDIMENTO
// SEMESTRE
// NUMERO DE DISCIPLINAS CURSADAS
// NUMERO DE DP's
//
// DESENVOLVER UMA APLICAÇÃO PARA ATRIBUIR VALOR
// E IMPRIMIR OS VALORES CADASTRADOS
//**********************************************

struct DADOSALUNOS
{
    //DEFINIR OS CAMPOS DA ESTRUTURA
    // NOME DO ALUNO
    char nomeAluno[200];
    // CÓDIGO DO CURSO
    int codigoCurso;
    // COEFICIENTE DE RENDIMENTO
    float cr;
    // SEMESTRE
    int semestreCorrente;
    // NUMERO DE DISCIPLINAS CURSADAS
    int numeroDiciplinasCursadas;
    // NUMERO DE DP's
    int numeroDisciplinasDP;
};

int main()
{
    // DECLARAS UMA VARIÁVEL DO TIPO: DADOSALUNOS
    struct DADOSALUNOS aluno;

    //COMO ATRIBUIR VALORES - LEITURA DO TECLADO
    printf("\nDIGITAR O NOME DO ALUNO: ");
    scanf("%s", aluno.nomeAluno);

    printf("\nDIGITAR O CÓDIGO DO CURSO: ");
    scanf("%d", & aluno.codigoCurso);

    printf("\nDIGITAR COEFICIENTE CR: ");
    scanf("%f", aluno.cr);

    printf("\nDIGITAR SEMESTRE CORRENTE: ");
    scanf("%d", aluno.semestreCorrente);

    printf("\nDIGITAR N# DISCIPLINAS: ");
    scanf("%d", aluno.numeroDiciplinasCursadas);

    printf("\nDIGITAR N# DP: ");
    scanf("%d", aluno.numeroDisciplinasDP);

    strcpy(aluno.nomeAluno,"JUVENAL");
    aluno.codigoCurso=123;
    aluno.cr=0.45;
    aluno.semestreCorrente=2;
    aluno.numeroDiciplinasCursadas=11;
    aluno.numeroDisciplinasDP=3;

    //COMO IMPRIMIR OS VALORES
    printf("\nNOMED ALUNO: %-20s", aluno.nomeAluno);
    printf("\nCODIGO DO CURSO: %4d", aluno.codigoCurso);
    printf("\nCOEFICIENTE RENDIMENTO: %4.2f", aluno.cr);
    printf("\nSEMESTRE CORRENTE: %4d", aluno.semestreCorrente);
    printf("\nDISCIPLINAS CURSADAS: %4d",aluno.numeroDiciplinasCursadas);
    printf("\nDISCIPLINAS EM DP: %4d",aluno.numeroDisciplinasDP);

    printf("\nOBRIGADO POR UTILIZAR O SOFTWARE TABAJARA");
    

    return 0;
}