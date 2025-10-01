#include <stdio.h>
#include <string.h>

struct aluno
{
    int matricula;
    char nome[50];
    float NotaFinal;
};

struct lista
{
    struct aluno alunos[5];
    int tamanho;
};

struct lista inicializaLista()
{
    struct lista l;
    l.tamanho = 0;
    return l;
};

struct lista inserirAluno(struct lista l,struct aluno novo)
{
    if(l.tamanho >= 5)
    {
        printf("lista cheia!");
        return l;
    }
    else
    {
        l.alunos[l.tamanho] = novo;
        l.tamanho++;
        return l;
    }
};

struct lista removerAluno(struct lista l, int matricula)
{
    int i ,j;
    for(i = 0; i < l.tamanho;i++)
    {
        if(l.alunos[i].matricula == matricula)
        {
            for(j = i; j < l.tamanho - 1; j++)
            {
                l.alunos[j] = l.alunos[j+1];
            }
            l.tamanho--;
            printf("\nAluno removido com Sucesso!\n");
            return l;
        }
    }
    printf("\nAluno com Matricula %i nao encontrado\n", matricula);
    return l;
};
int buscarAluno(struct lista l, int matricula)
{
    for(int i = 0; i < l.tamanho; i++){
        if(l.alunos[i].matricula == matricula)
        {
            return i;
        }
    }
    return -1;
};

void imprimirAlunos(struct lista l)
{
    if(l.tamanho == 0)
    {
        printf("Nenhum aluno encontrado\n");
    }
    else
    {
        printf("\nLista do(s) aluno(s)\n");
        for(int i = 0; i < l.tamanho;i++)
        {
            printf("Matricula: %i\n",l.alunos[i].matricula);
            printf("Nome: %s\n",l.alunos[i].nome);
            printf("Nota Final : %.2f\n",l.alunos[i].NotaFinal);
        }
    }
};

int main()
{
    struct lista l = inicializaLista();
    struct aluno novo;
    int quantidade, matricula, i;

    printf("Quantos alunos você deseja cadastar? ");
    scanf("%i", &quantidade);
    for(i = 0; i < quantidade; i++)
    {
        printf("\nCadastrar Aluno\n");
        printf("Matricula: ");
        scanf("%i", &novo.matricula);
        printf("Nome do Aluno: ");
        getchar();
        fgets(novo.nome, 50, stdin);
        printf("Media do aluno: ");
        scanf("%f", &novo.NotaFinal);
       
        l = inserirAluno(l,novo);
    }
    imprimirAlunos(l);

    printf("\nRemover Aluno\n");
    printf("\nEntre com a matrcula para remover\n");
    scanf("%i",&matricula);

    l = removerAluno(l,matricula);
    imprimirAlunos(l);

    printf("\nQual Aluno você quer buscar\n");
    scanf("%i",&matricula);

    int indice = buscarAluno(l,matricula);
    if (indice != -1) {
        printf("Aluno encontrado:\n");
        printf("Matricula: %i\n", l.alunos[indice].matricula);
        printf("Nome: %s\n", l.alunos[indice].nome);
        printf("Nota Final : %.2f\n", l.alunos[indice].NotaFinal);
    } else {
        printf("Aluno com Matricula %i nao encontrado\n", matricula);
    }
    return 0;
}