struct dados { int ehOperador; float valor; char op; };

float calc(float a, char op, float b) {
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '+') return a + b;
    return a - b;
}


Descritor* reduz(Descritor* q, const char* ops)
{
    Descritor* novo = criar();
    dados acc = removerFILA(q);            
    while (q->tamanho > 0)
    {
        dados op = removerFILA(q);
        dados n  = removerFILA(q);
        if (strchr(ops, op.op))
            acc.valor = calc(acc.valor, op.op, n.valor);  
        else {
            inserirFILA(novo, acc);        
            inserirFILA(novo, op);
            acc = n;
        }
    }
    inserirFILA(novo, acc);
    return novo;
}

