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

struct DADOSALUNOS aluno
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
    
    int nAlunos;

    printf("DIGITAR NÚMERO DE ALUNOS PARA CADASTRO: ");
    scanf("%d", nAlunos);

    // VETOR PARA ARMAZENAR OS ALUNOS
    struct DADOSALUNOS alunos[nAlunos];

    // LIMPAR O ENTER DEIXADO PELO scanf
    getchar();

    // DECLARAS UMA VARIÁVEL DO TIPO: DADOSALUNOS
    // PARA ARMAZENAR n ALUNOS
    //DEFINIR UM VETOR DO TIPO: DADOSALUNOS
    //LER OS DADOS DO TECLADO
    //ARMZENAR EM ARQUIVO.TXT
    struct DADOSALUNOS aluno;

    
    printf("\DIGITAR O NUMERO DE ALUNOS PARA CADASTRO: ");
    scanf("%d", &nAluno);

    //COMO ATRIBUIR VALORES - LEITURA DO TECLADO
    for(int pos=0;pos<nAlunos;pos++)
    {
    printf("\nDIGITAR O NOME DO ALUNO: ", pos);
    scanf("%s", aluno.nomeAluno);

    printf("\nDIGITAR O CÓDIGO DO CURSO: ", pos);
    scanf("%d", & aluno.codigoCurso);

    printf("\nDIGITAR COEFICIENTE CR: ");
    scanf("%f", aluno.cr);

    printf("\nDIGITAR SEMESTRE CORRENTE: ");
    scanf("%d", aluno.semestreCorrente);

    printf("\nDIGITAR N# DISCIPLINAS: ");
    scanf("%d", aluno.numeroDiciplinasCursadas);

    printf("\nDIGITAR N# DP: ");
    scanf("%d", aluno.numeroDisciplinasDP);
    }

    strcpy(aluno.nomeAluno,"JUVENAL");
    aluno.codigoCurso=123;
    aluno.cr=0.45;
    aluno.semestreCorrente=2;
    aluno.numeroDiciplinasCursadas=11;
    aluno.numeroDisciplinasDP=3;

    //COMO IMPRIMIR OS VALORES
    printf("\n\nIMPRIMINDO OS DADOS LIDOS: ");
    for(int pos=0;pos<nAlunos;pos++);
    {
    printf("\nNOME DO ALUNO: [%4d]   %20s", aluno.nomeAluno);
    printf("\nCODIGO DO CURSO: %4d", aluno.codigoCurso);
    printf("\nCOEFICIENTE RENDIMENTO: %4.2f", aluno.cr);
    printf("\nSEMESTRE CORRENTE: %4d", aluno.semestreCorrente);
    printf("\nDISCIPLINAS CURSADAS: %4d",aluno.numeroDiciplinasCursadas);
    printf("\nDISCIPLINAS EM DP: %4d",aluno.numeroDisciplinasDP);
    }

    printf("\nOBRIGADO POR UTILIZAR O SOFTWARE TABAJARA");
    

    return 0;
}