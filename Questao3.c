/* QUESTAO 3 (2 PONTOS)
   Venda de ingressos da Rapidway com descontos acumulativos:
   - Idade < 16 anos          -> 10%
   - Idade > 60 anos          -> 50%
   - Numero de filhos > 1     -> 10% por filho
   - Anos de escolaridade     -> 1% por ano de estudo

   Requisitos:
   - Calcular o valor do ingresso
   - Calcular o valor do troco */

#include <stdio.h>

int main()
{
    float precoUnico, valorPago, percentualDesconto, valorDesconto, valorFinal, troco;
    int idade, numeroFilhos, anosEscolaridade;

    printf("Digite o preco unico do ingresso: ");
    scanf("%f", &precoUnico);

    printf("Digite a idade do espectador: ");
    scanf("%d", &idade);

    printf("Digite o numero de filhos: ");
    scanf("%d", &numeroFilhos);

    printf("Digite os anos de escolaridade: ");
    scanf("%d", &anosEscolaridade);

    percentualDesconto = 0;

    if (idade < 16)
        percentualDesconto = percentualDesconto + 10;

    if (idade > 60)
        percentualDesconto = percentualDesconto + 50;

    if (numeroFilhos > 1)
        percentualDesconto = percentualDesconto + (numeroFilhos * 10);

    percentualDesconto = percentualDesconto + (anosEscolaridade * 1);

    valorDesconto = precoUnico * (percentualDesconto / 100);
    valorFinal = precoUnico - valorDesconto;

    printf("\nPercentual de desconto acumulado: %.2f %%\n", percentualDesconto);
    printf("Valor do ingresso com desconto: %.2f\n", valorFinal);

    printf("\nDigite o valor pago pelo espectador: ");
    scanf("%f", &valorPago);

    troco = valorPago - valorFinal;

    if (troco < 0)
        printf("\nValor pago insuficiente. Faltam: %.2f\n", -troco);
    else
        printf("\nTroco: %.2f\n", troco);

    return 0;
}
