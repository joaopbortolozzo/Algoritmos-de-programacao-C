#include <stdio.h>

int main()
{
    int dia,mes,ano;
    int A,B,C,D,E,F,G,H,I,diasemana;
    
    printf("\nDIGITE DIA: ");
    scanf("%d",&dia);
    printf("\nDIGITE MES: ");
    scanf("%d",&mes);
    printf("\nDIGITE ANO: ");
    scanf("%d",&ano);
    
    A = (int)((12-mes) / 10) ;
    B = ano - A ;
    C = mes + (12 * A) ;
    D = (int)(B / 100) ;
    E = (int) (D/4) ;
    F = 2 - D + E ;
    G = (int)(365.25 * B) ;
    H = (int)(30.6001 * (C + 1));
    I = (int) ((F+G) + (H + dia) + 5);
    
    diasemana=I%7;
    
    printf("\n%02d/%02d/%04d: ",dia,mes,ano);
    switch(diasemana)
    {
        case 0:
               printf("SABADO\n");
               break;
        case 1:
               printf("DOMINGO\n");
               break;
        case 2:
               printf("SEGUNDA FEIRA\n");
               break;
         case 3:
               printf("TERCA FEIRA\n");
               break;      
        case 4:
               printf("QUARTA FEIRA\n");
               break;       
        case 5:
               printf("QUINTA FEIRA\n");
               break;       
         case 6:
               printf("SEXTA FEIRA\n");
               break;      
    }
    return 0;
}