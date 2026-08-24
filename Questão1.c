#include <stdio.h>

int main() {
    char *candidatos[3] = {"Candidato 1", "Candidato 2", "Candidato 3"}; 
    int votos[3] = {0, 0, 0};
    int escolha;
    int votando = 1;

    while (votando == 1) {
        printf("Digite o numero do candidato (0 para encerrar): ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            votando = 0;
        } else if (escolha >= 1 && escolha <= 3) {
            votos[escolha - 1] = votos[escolha - 1] + 1;
        } else {
            printf("Candidato invalido!\n");
        }
    }

    int total = 0;
    int i;
    for (i = 0; i < 3; i++) {
        total = total + votos[i];
    }

    printf("\nTOTALIZACAO\n");
    for (i = 0; i < 3; i++) {
        float percentual = ((float) votos[i] / total) * 100;
        printf("%s - %d votos - %.2f%%\n", candidatos[i], votos[i], percentual);
    }

    return 0;
}