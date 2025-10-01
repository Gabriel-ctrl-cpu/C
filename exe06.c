#include <stdio.h>
#include <string.h>

struct livro{
    int codigo;
    char titulo[50];
    char autor[30];
    int ano;
    int disponivel; // 1 - disponível, 0 - emprestado
};

struct lista{
    struct livro livros[5];
    int tamanho;
};

struct lista inicializaLivro(){
    struct lista l;
    l.tamanho = 0;
    return l;
};

struct lista inserirLivro(struct lista l, struct livro novo){
    if(l.tamanho >= 5){
        printf("Lista cheia!");
        return l;
    } else {
        l.livros[l.tamanho] = novo;
        l.tamanho++;
        return l;
    }
};

struct lista removerLivro(struct lista l, int codigo){
    int i, j;
    for(i = 0; i < l.tamanho; i++){
        if(l.livros[i].codigo == codigo){
            for(j = i; j < l.tamanho; j++)
            {
                l.livros[j] = l.livros[j+1];
            }
            l.tamanho--;
        }
        printf("\nLivro removido com sucesso!\n");
    }
    printf("\nLivro com codigo %i nao encontrado\n", codigo);
    return l;
};

int buscarTitulo(struct lista l, char titulo[50]){
    for(int i = 0; i < l.tamanho; i++){
        if(strcmp(l.livros[i].titulo, titulo) == 0){
            return i;
        }
    }
    return -1;
};

int disponibilidadeLivro(struct lista l, int codigo){
    for(int i = 0; i < l.tamanho; i++){
        if(l.livros[i].codigo == codigo){
            if(l.livros[i].disponivel == 1){
                printf("Livro disponivel para emprestimo\n");
            } else {
                printf("Livro indisponivel para emprestimo\n");
            }
        }
    }
    return -1;
};
int trocarDisponibilidade(struct lista l, int codigo){
    for(int i = 0; i < l.tamanho; i++){
        if(l.livros[i].codigo == codigo){
           l.livros[i].disponivel = !l.livros[i].disponivel;
           printf("Disponibilidade do livro alterada com sucesso\n");
           return 0;
        }
    }
    printf("Livro com codigo %i nao encontrado\n", codigo);
    return -1;
};
void imprimirLivros(struct lista l){
    if(l.tamanho == 0){
        printf("\nLista Vazia!\n");
    } else {
        printf("\nLista de livros:\n");
        for(int i = 0; i < l.tamanho; i++){
            printf("Codigo: %i\n", l.livros[i].codigo);
            printf("Titulo: %s\n", l.livros[i].titulo);
            printf("Autor: %s\n", l.livros[i].autor);
            printf("Ano: %i\n", l.livros[i].ano);
            if(l.livros[i].disponivel == 1){
                printf("Disponibilidade: Disponivel\n");
            } else {
                printf("Disponibilidade: Emprestado\n");
            }
        }
    }
};
int main(){
    struct lista l = inicializaLivro();
    struct livro novo;
    int quantidade, i, codigo;
    char titulo[50];
    printf("Quantos livros você deseja cadastrar? ");
    scanf("%i", &quantidade);
    for(i = 0; i < quantidade; i++){
        printf("\nCadastrar Livro\n");
        printf("Codigo: ");
        scanf("%i", &novo.codigo);
        printf("Titulo do Livro: ");
        getchar();
        fgets(novo.titulo, 50, stdin);
        printf("Autor do Livro: ");
        fgets(novo.autor, 30, stdin);
        printf("Ano de Publicacao: ");
        scanf("%i", &novo.ano);
        printf("Disponibilidade (1 - Disponivel, 0 - Emprestado): ");
        scanf("%i", &novo.disponivel);
        l = inserirLivro(l, novo);
    }
    imprimirLivros(l);

    printf("\nRemover Livro\n");
    printf("\nEntre com o codigo para remover\n");
    scanf("%i", &codigo);

    l = removerLivro(l, codigo);
    imprimirLivros(l);

    printf("\nQual Livro você quer buscar\n");
    scanf("%s", titulo);

    int indice = buscarTitulo(l, titulo);
    if (indice != -1) {
        printf("Livro encontrado:\n");
        printf("Codigo: %i\n", l.livros[indice].codigo);
        printf("Titulo: %s\n", l.livros[indice].titulo);
        printf("Autor: %s\n", l.livros[indice].autor);
        printf("Ano: %i\n", l.livros[indice].ano);
        printf("Disponibilidade: %i\n", l.livros[indice].disponivel);
        if(l.livros[indice].disponivel == 1){
            printf("Disponibilidade: Disponivel\n");
        } else {
            printf("Disponibilidade: Emprestado\n");
        }
    } else {
        printf("Livro com codigo %i nao encontrado\n", codigo);
    }
    printf("\nVerificar disponibilidade do livro\n");
    scanf("%i", &codigo);
    disponibilidadeLivro(l, codigo);
    printf("\nTrocar disponibilidade do livro\n");
    scanf("%i", &codigo);
    trocarDisponibilidade(l, codigo);
    imprimirLivros(l);

    return 0;
}