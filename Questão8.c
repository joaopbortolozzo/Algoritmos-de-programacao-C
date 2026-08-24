#include <stdio.h>

int main()
{
    int numero;
    int digito,soma;
    int cont;
    
    printf("\nDIGITE UM NUMERO: ");
    scanf("%d",&numero);
    
    cont=0;
    do
    {
        printf("\n\nNUMERO EM ANALISE: %d",numero);
        soma=0;
        do
        {
            //SEPARAR UM DIGITO
            digito=numero%10;
            printf("\n   NUMERO:  %d  DIGITO: %d  SOMA: %d",numero,digito,soma);
            //CALCULAR A SOMA DOS QUADRADOS
            soma=soma+digito*digito;
            //REMOVER O DIGITO DO numero
            numero=numero/10;
        }while(numero!=0);
        
        cont=cont+1;
        printf("\n   NUMERO:  %d  DIGITO: %d  SOMA: %d",numero,digito,soma);
        numero=soma;
    }while((numero!=1)&&(cont<100));
    
    if(numero==1)
        printf("\n\nO NUMERO Eh FELIZ");
    else
        printf("\n\nO NUMERO NAO Eh FELIZ");
    
    return 0;
}