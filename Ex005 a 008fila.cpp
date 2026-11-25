dados consultarCPF(Descritor* d, char* cpf)
{
    dados achado, aux;
    int tam = d->tamanho;
    achado.conta = -1;                    
    for (int i = 0; i < tam; i++)
    {
        aux = removerFILA(d);
        if (strcmp(aux.cpf, cpf) == 0) achado = aux;
        inserirFILA(d, aux);
    }
    return achado;
}

// 005 - remover um cliente qualquer por CPF
int removerCPF(Descritor* d, char* cpf)
{
    dados aux;
    int tam = d->tamanho, achou = 0;
    for (int i = 0; i < tam; i++)
    {
        aux = removerFILA(d);
        if (!achou && strcmp(aux.cpf, cpf) == 0)
            achou = 1;                    
        else
            inserirFILA(d, aux);
    }
    return achou;
}

int contar(Descritor* d) { return d->tamanho; }

int totalInseridos(Descritor* d) { return d->totalInseridos; }

void reinicializar(Descritor* d)
{
    while (d->tamanho > 0) removerFILA(d);  
    d->totalInseridos = 0;
}