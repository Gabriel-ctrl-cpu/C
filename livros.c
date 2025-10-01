#include <stdio.h>
#include <string.h>

/*Estrutura livro:  usada para armazenar os dados dos livros*/
struct livro
{
    int id, ano;
    char titulo[50], autor[50];
};

/*Estrutura lista: usada para criar uma lista de livros*/
struct lista
{
    struct livro livros[10];
    int tamanho;
};

/*Função para inicializar a lista*/
struct lista inicializarLista()
{
    struct lista l;
    l.tamanho = 0;
    return l;
}

/*Função para inserir o livro*/
struct lista inserirLivro(struct lista l, struct livro novo)
{
    if (l.tamanho >= 10)
    {
        printf("Lista Cheia!");
        return l;
    }
    else
    {
        l.livros[l.tamanho] = novo;
        l.tamanho++;
        return l;
    }
}

/*Função remover livro pelo id*/
struct lista removerLivro(struct lista l, int id)
{
    int i, j;
    for (i = 0; i < l.tamanho; i++)
    {
        if (l.livros[i].id == id)
        {
            // desloca os livros a esquerda
            for (j = i; j < l.tamanho - 1; j++)
            {
                l.livros[j] = l.livros[j + 1];
            }
            l.tamanho--;
            printf("Livro removido com sucesso!\n");
            return l;
        }
    }
    printf("Livro com id %i nao encontrado\n", id);
    return l;
}

/*Função para buscar livro pelo ID*/
int buscarLivros(struct lista l, int id)
{
    for (int i = 0; i < l.tamanho; i++)
    {
        if (l.livros[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

/*Função para imprimir lista de livros*/
void imprimirLivros(struct lista l)
{
    if (l.tamanho == 0)
    {
        printf("nenhum livro cadastrado.\n");
    }
    else
    {
        printf("\nLista de Livros\n");
        for (int i = 0; i < l.tamanho; i++)
        {
            printf("ID: %i\n", l.livros[i].id);
            printf("Titulo: %s\n", l.livros[i].titulo);
            printf("Autor: %s\n", l.livros[i].autor);
            printf("Ano: %i\n", l.livros[i].ano);
        }
    }
}

/*Função Principal do Programa*/
int main()
{

    struct lista l = inicializarLista();
    struct livro novo;
    int quantidade, i, id;
    printf("Quantos livros deseja cadastrar? ");
    scanf("%i", &quantidade);
    for (i = 0; i < quantidade; i++)
    {
        printf("\nCadastro do livro\n");
        printf("ID: ");
        scanf("%i", &novo.id);
        printf("Titulo: ");
        getchar();
        fgets(novo.titulo, 50, stdin);
        printf("Autor: ");
        fgets(novo.autor, 50, stdin);
        printf("Ano: ");
        scanf("%i", &novo.ano);
        l = inserirLivro(l, novo);
    }
    imprimirLivros(l);

    printf("\nRemover Livros\n");
    printf("\nEntre com o ID para remover\n");
    scanf("%i",&id);

    l = removerLivro(l,id);
    imprimirLivros(l);

    printf("\nQual livro você quer buscar\n");
    scanf("%i",&id);

    l = buscarLivros(l,id);
    imprimirLivros(l);
}