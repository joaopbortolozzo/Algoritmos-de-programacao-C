int ehPalindromo(char S[])
{
    Descritor* f = criar();
    dados d;
    int n = strlen(S), ok = 1;

    for (int i = 0; i < n; i++) {          
        d.letra = S[i];                    
        inserirFILA(f, d);
    }
    for (int i = n - 1; i >= 0; i--) {     
        d = removerFILA(f);              
        if (d.letra != S[i]) ok = 0;
    }
    free(f);
    return ok;
}