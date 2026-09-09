#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIR UMA ESTRUTURA DE DADOS
// CONTENDO AS SEGUINTES INFORMACOES
//
// NOME DO ALUNO
// CODIGO DO CURSO
// COEFICIENTE DE RENDIMENTO
// SEMESTRE
// NUMERO DE DISCIPLINAS CURSADAS
// NUMERO DE DP's
//
// DESENVOLVER UMA APLICACAO PARA ATRIBUIR VALOR
// E IMPRIMIR OS VALORES CADASTRADOS
//**********************************************

struct DADOSALUNOS
{
    // NOME DO ALUNO
    char nomeAluno[200];

    // CODIGO DO CURSO
    int codigoCurso;

    // COEFICIENTE DE RENDIMENTO
    float cr;

    // SEMESTRE
    int semestreCorrente;

    // NUMERO DE DISCIPLINAS CURSADAS
    int numeroDisciplinasCursadas;

    // NUMERO DE DP's
    int numeroDisciplinasDP;
};

int main()
{
    int nAlunos;

    printf("DIGITAR NUMERO DE ALUNOS PARA CADASTRO: ");
    scanf("%d", &nAlunos);

    // VETOR PARA ARMAZENAR OS ALUNOS
    struct DADOSALUNOS alunos[nAlunos];

    // LIMPAR O ENTER DEIXADO PELO scanf
    getchar();

    // LEITURA DOS DADOS
    for (int pos = 0; pos < nAlunos; pos++)
    {
        printf("\n===== ALUNO %d =====\n", pos + 1);

        printf("DIGITAR O NOME DO ALUNO: ");
        fgets(alunos[pos].nomeAluno, 200, stdin);

        // Retirar o ENTER do final do nome
        alunos[pos].nomeAluno[strcspn(alunos[pos].nomeAluno, "\n")] = '\0';

        printf("DIGITAR O CODIGO DO CURSO: ");
        scanf("%d", &alunos[pos].codigoCurso);

        printf("DIGITAR COEFICIENTE CR: ");
        scanf("%f", &alunos[pos].cr);

        printf("DIGITAR SEMESTRE CORRENTE: ");
        scanf("%d", &alunos[pos].semestreCorrente);

        printf("DIGITAR N# DISCIPLINAS: ");
        scanf("%d", &alunos[pos].numeroDisciplinasCursadas);

        printf("DIGITAR N# DP: ");
        scanf("%d", &alunos[pos].numeroDisciplinasDP);

        // Limpar o ENTER
        getchar();
    }

    // IMPRESSAO DOS VALORES
    printf("\n\n========== IMPRIMINDO OS DADOS LIDOS ==========\n");

    for (int pos = 0; pos < nAlunos; pos++)
    {
        printf("\n===== ALUNO %d =====\n", pos + 1);

        printf("NOME DO ALUNO: %s\n", alunos[pos].nomeAluno);
        printf("CODIGO DO CURSO: %d\n", alunos[pos].codigoCurso);
        printf("COEFICIENTE RENDIMENTO: %.2f\n", alunos[pos].cr);
        printf("SEMESTRE CORRENTE: %d\n", alunos[pos].semestreCorrente);
        printf("DISCIPLINAS CURSADAS: %d\n",
               alunos[pos].numeroDisciplinasCursadas);
        printf("DISCIPLINAS EM DP: %d\n",
               alunos[pos].numeroDisciplinasDP);
    }

    printf("\nOBRIGADO POR UTILIZAR O SOFTWARE TABAJARA!\n");

    return 0;
}