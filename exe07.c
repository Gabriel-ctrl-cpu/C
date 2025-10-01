#include <stdio.h>
#include <string.h>

struct filme{
    int id;
    char titulo[50];
    char diretor[30];
    int ano;
    float NotaMedia;
};

struct lista{
    struct filme filmes[5];
    int tamanho;
};

struct lista inicializaFilme(){
    struct lista l;
    l.tamanho = 0;
    return l;
};

struct lista inserirFilme(struct lista l, struct filme novo){
    if(l.tamanho >= 5){
        printf("Lista cheia!");
        return l;
    } else {
        l.filmes[l.tamanho] = novo;
        l.tamanho++;
        return l;
    }
};

struct lista removerFilme(struct lista l, int id){
    int i, j;
    for(i = 0; i < l.tamanho; i++){
        if(l.filmes[i].id == id){
            for(j = i; j < l.tamanho; j++)
            {
                l.filmes[j] = l.filmes[j+1];
            }
            l.tamanho--;
        }
        printf("\nFilme removido com sucesso!\n");
    }
    printf("\nFilme com id %i nao encontrado\n", id);
    return l;
};

int buscarTitulo(struct lista l, char titulo[50]){
    for(int i = 0; i < l.tamanho; i++){
        if(strcmp(l.filmes[i].titulo, titulo) == 0){
            return i;
        }
    }
    return -1;
};
void imprimirFilmes(struct lista l){
    if(l.tamanho == 0){
        printf("\nLista Vazia!\n");
    } else {
        printf("\nLista de filmes:\n");
        for(int i = 0; i < l.tamanho; i++){
            printf("ID: %i\n", l.filmes[i].id);
            printf("Titulo: %s\n", l.filmes[i].titulo);
            printf("Diretor: %s\n", l.filmes[i].diretor);
            printf("Ano: %i\n", l.filmes[i].ano);
            printf("Nota Media : %.2f\n", l.filmes[i].NotaMedia);
        }
    }
};
int main(){
    struct lista l = inicializaFilme();
    struct filme novo;
    int quantidade, i, id;
    char titulo[50];
    printf("Quantos filmes você deseja cadastrar? ");
    scanf("%i", &quantidade);
    for(i = 0; i < quantidade; i++){
        printf("\nCadastrar Filme\n");
        printf("ID: ");
        scanf("%i", &novo.id);
        printf("Titulo do Filme: ");
        getchar();
        fgets(novo.titulo, 50, stdin);
        printf("Diretor do Filme: ");
        fgets(novo.diretor, 30, stdin);
        printf("Ano de Lancamento: ");
        scanf("%i", &novo.ano);
        printf("Nota Media do Filme: ");
        scanf("%f", &novo.NotaMedia);
        l = inserirFilme(l, novo);
    }
    imprimirFilmes(l);

    printf("\nRemover Filme\n");
    printf("\nEntre com o id para remover\n");
    scanf("%i", &id);

    l = removerFilme(l, id);
    imprimirFilmes(l);

    printf("\nQual Filme você quer buscar\n");
    getchar();
    fgets(titulo, 50, stdin);

    int indice = buscarTitulo(l, titulo);
    if (indice != -1) {
        printf("Filme encontrado:\n");
        printf("ID: %i\n", l.filmes[indice].id);
        printf("Titulo: %s\n", l.filmes[indice].titulo);
        printf("Diretor: %s\n", l.filmes[indice].diretor);
        printf("Ano: %i\n", l.filmes[indice].ano);
        printf("Nota Media : %.2f\n", l.filmes[indice].NotaMedia);
    } else {
        printf("Filme com id %i nao encontrado\n", id);
    }
    return 0;
}