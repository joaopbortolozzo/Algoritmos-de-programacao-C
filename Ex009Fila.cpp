void cadastrarComPrioridade(Descritor* fila, dados novo)
{
    inserirFILA(fila, novo);              

    if (novo.prioritario)                 
    {
        Descritor* filaP = criar();
        Descritor* filaN = criar();
        dados aux;
        int tam = fila->tamanho;

        for (int i = 0; i < tam; i++)     
        {
            aux = removerFILA(fila);
            if (aux.prioritario) inserirFILA(filaP, aux);
            else                 inserirFILA(filaN, aux);
        }
        while (filaP->tamanho > 0) inserirFILA(fila, removerFILA(filaP));
        while (filaN->tamanho > 0) inserirFILA(fila, removerFILA(filaN));

        free(filaP);
        free(filaN);
    }
}