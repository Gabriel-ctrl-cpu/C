#include<stdio.h>
#include<stdlib.h>
struct lista
{
    int valor[5], tamanho, inicio;
};struct lista l;

void inserefinal()
{
    int x;
    if(l.tamanho == 5){
        printf("Lista cheia");
        exit(1);
    }
    else
    {
        printf("digite um valor: ");
        scanf("%i", &x);
        l.valor[l.tamanho] = x;
        l.tamanho++;
        printf("\nElemento %i inserido! ", x);
    }
}

void removefinal()
{
    if(l.tamanho == 0)
    {
        printf("Lista Vazia");
        exit(1);
    }
    else
    {
        l.tamanho--;
        printf("\nElemento %i removido", l.valor[l.tamanho]);
    }
}

void imprime()
{
    int v, i;
    i = l.inicio;
    while(i != l.tamanho)
    {
        v = l.valor[i];
        printf("\nElemento %i da lista: %i",i,v);
        i++;
    }
}

void busca()
{
    int i, valor_buscado, encontrado = 0;
    printf("Digite um valor: ");
    scanf("%i", &valor_buscado);

    for(i = 0; i < l.tamanho; i++)
    {
        if(l.valor[i] == valor_buscado)
        {
            printf("Valor %i encontrado na posição %i\n", valor_buscado, i);
        }
    }
}

int main()
{
    l.inicio = l.tamanho = 0;
    int op;
    while(op != 4)
    {
        printf("\nManipulando Lista Estatica\n");
        printf("Digite 1 para Inserir no Fim\n");
        printf("Digite 2 para Remover do Fim\n");
        printf("Digite 3 para Imprimir a Lista\n");
        printf("Digite 4 para Buscar\n");
        printf("Digite 5 para Sair\n");
        printf("Entre com a opcao: ");
        scanf("%i",&op);
        switch(op)
        {
            case 1: inserefinal(); break;
            case 2: removefinal(); break;
            case 3: imprime(); break;
            case 4: busca(); break;
            case 5: exit(1);
            default: printf("opção invalida");
        }
    }
}