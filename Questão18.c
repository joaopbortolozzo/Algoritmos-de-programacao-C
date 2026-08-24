#include <stdio.h>

int main()
{
    float  DistanciaQuilometro,CustoPorQuilometro,CBU;
    float percentualDescontoNumeroBilhete;
    float DescontoNumeroBilhete;
    float percentualDescontoIdade;
    float DescontoIdade;
    float valotTotal;
    float valorBilhete;
    int numeroBilhetes,idade;
    
    printf("\nCALCULAR O CUSTO DE BILHETES - VIAGEM PLANETARIA");
    printf("\nDIGITAR A DISTANCIA:     ");
    scanf("%f",&DistanciaQuilometro);
    printf("\nDIGITAR CUSTO POR Km:    ");
    scanf("%f",&CustoPorQuilometro);
    
    CBU = DistanciaQuilometro * CustoPorQuilometro;
    
    printf("\nDIGITAR NUMERO BILHETES: ");
    scanf("%d",&numeroBilhetes);
    
    //CALCULAR DESCONTO PELO NUMERO DE BILHETES
    if(numeroBilhetes<=1)
        percentualDescontoNumeroBilhete=0;
    else
    if ( (numeroBilhetes>=2)&&(numeroBilhetes<=5) )
        percentualDescontoNumeroBilhete=5;
    else
    if ( (numeroBilhetes>=6)&&(numeroBilhetes<=10) )
        percentualDescontoNumeroBilhete=15;
    else
        percentualDescontoNumeroBilhete=30;
    
    DescontoNumeroBilhete=CBU*percentualDescontoNumeroBilhete/100;
    valorBilhete=CBU-DescontoNumeroBilhete;
    
    printf("\nDIGITAR IDADE        : ");
    scanf("%d",&idade);
    
    //CALCULAR DESCONTO idade
    percentualDescontoIdade=0;
    if ( (idade>=0)&&(idade<=5))
           percentualDescontoIdade=20;
    else
    if ( (idade>=6)&&(idade<=10))
           percentualDescontoIdade=15; 
    else
    if ( (idade>=11)&&(idade<=16))
           percentualDescontoIdade=10;
    else
    if (idade>=60)
           percentualDescontoIdade=30; 
           
    DescontoIdade=valorBilhete*percentualDescontoIdade/100;
    valorBilhete=valorBilhete-DescontoIdade;
    
    valotTotal=valorBilhete*numeroBilhetes;
    
    printf("\nCOMPRA DE BILHETES");
    printf("\nDISTANCIA DO TRAJETO:        %7.2f Km",DistanciaQuilometro);
    printf("\nCUSTO POR Km:             R$ %7.2f",CustoPorQuilometro);
    printf("\nCUSTO BASE BILHETE:       R$ %7.2f",CBU);
    printf("\nNUMERO DE BILHETES:          %7d Bilhetes",numeroBilhetes);
    printf("\nPERCENTUAL DESC N# BILHETES: %7.2f %%",percentualDescontoNumeroBilhete);
    printf("\nDESCONTO N# BILHETES:     R$ %7.2f",DescontoNumeroBilhete);
    printf("\nIDADE:                       %7d Anos",idade);   
    printf("\nPERCENTUAL DESC N# IDADE:    %7.2f %%",percentualDescontoIdade);
    printf("\nDESCONTO IDADE:           R$ %7.2f",DescontoIdade);
    printf("\nVALOR FINAL DO BILHETE:   R$ %7.2f",valorBilhete);
    printf("\nVALOR TOTAL COMPRA:       R$ %7.2f",valotTotal);
    
    return 0;
}