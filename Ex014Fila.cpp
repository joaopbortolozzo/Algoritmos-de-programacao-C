void inverter(Descritor* f)
{
    if (f->tamanho == 0) return;
    dados x = removerFILA(f);  
    inverter(f);                
    inserirFILA(f, x);         
}

