#include <stdio.h>
#include <string.h>

//DESENVOLVER UMA FUNÇÃO PARA CONTAR
//O NUMERO DE VOGAIS EM UMA palavra

int nvogais(char *c){
    int pos;

    pos=0;
    while(*c != '\0')
    {
        if(*c == 'A' || *c == 'E' || *c == 'I' || *c == 'O' || *c == 'U' || *c == 'a' || *c == 'e' || *c == 'i' || *c == 'o' || *c == 'u')
        {
            pos++;
        }
        c++;
    }
    return pos;
}


int main(){
    char palavra [100];
    int vogais;

    printf("Digite uma palavra: ");
    scanf("%s", &palavra);

    vogais=nvogais(palavra);
    printf("\nA PALAVRA: %s TEM %d VOGAIS", palavra,vogais);

    return 0;

}