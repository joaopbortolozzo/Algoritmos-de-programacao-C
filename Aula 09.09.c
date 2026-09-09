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

    //COMO ATIVAR VALORES
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