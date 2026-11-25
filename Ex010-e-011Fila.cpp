dados espiarFILA(Descritor* d)            
{
    dados vazio; vazio.idade = -1;
    if (d->tamanho == 0) return vazio;
    return d->inicio->cadastro;           
}

void separarPorUrgencia(Descritor* geral, Descritor* filas[6])
{
    int tam = geral->tamanho;
    for (int i = 0; i < tam; i++) {
        dados aux = removerFILA(geral);
        inserirFILA(filas[aux.urgencia], aux);
        inserirFILA(geral, aux);          
    }
}