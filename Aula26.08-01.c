#include <stdio.h>
#include <string.h>

//DESENVOLVER UMA FUNÇÃO PARA CONTAR
//O NUMERO DE CARACTERES DE UMA palavra

int numeroCaracteres(char *c){
    int pos;

    pos=0;
    while(c[pos]!='\0')
    {
        pos++;
    }
    return pos;
}


int main(){
    char palavra [100]="PERITONIO";
    int ncaracteres;

    ncaracteres=numeroCaracteres(palavra);
    printf("\nA PALAVRA: %s TEM %d CARACTERES", palavra,ncaracteres);

    return 0;

}