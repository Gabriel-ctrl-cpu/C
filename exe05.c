#include <stdio.h>
#include <string.h>

struct tarefa{
    int id;
    char descricao[100];
    int prioridade; // 1 - baixa, 2 - media, 3 - alta
    int concluida; // 1 - concluida, 0 - pendente
};
struct lista{
    struct tarefa tarefas[5];
    int tamanho;
};
struct lista inicializaTarefa(){
    struct lista l;
    l.tamanho = 0;
    return l;
};
struct lista inserirTarefa(struct lista l, struct tarefa novo){
    if(l.tamanho >= 5){
        printf("Lista cheia!");
        return l;
    } else {
        l.tarefas[l.tamanho] = novo;
        l.tamanho++;
        return l;
    }
};
struct lista removerTarefa(struct lista l, int id){
    int i, j;
    for(i = 0; i < l.tamanho; i++){
        if(l.tarefas[i].id == id){
            for(j = i; j < l.tamanho; j++)
            {
                l.tarefas[j] = l.tarefas[j+1];
            }
            l.tamanho--;
        }
        printf("\nTarefa removida com sucesso!\n");
    }
    printf("\nTarefa com id %i nao encontrada\n", id);
    return l;
};
int buscarDescricao(struct lista l, char descricao[100]){
    for(int i = 0; i < l.tamanho; i++){
        if(strcmp(l.tarefas[i].descricao, descricao) == 0){
            return i;
        }
    }
    return -1;
};
int statusTarefa(struct lista l, int id){
    for(int i = 0; i < l.tamanho; i++){
        if(l.tarefas[i].id == id){
            if(l.tarefas[i].concluida == 1){
                printf("Tarefa ja concluida\n");
            } else {
                printf("Tarefa pendente\n");
            }
        }
    }
    return -1;
};
void imprimirTarefas(struct lista l){
    if(l.tamanho == 0){
        printf("\nLista Vazia!\n");
    } else {
        printf("\nLista de tarefas:\n");
        for(int i = 0; i < l.tamanho; i++){
            printf("ID: %i\n", l.tarefas[i].id);
            printf("Descricao: %s\n", l.tarefas[i].descricao);
            if(l.tarefas[i].prioridade == 1){
                printf("Prioridade: Extremamente Alta\n");
            } else if(l.tarefas[i].prioridade == 2){
                printf("Prioridade: Alta\n");
            } else if(l.tarefas[i].prioridade == 3){
                printf("Prioridade: Media\n");
            }else if(l.tarefas[i].prioridade == 4){
                printf("Prioridade: Baixa\n");
            }else{
                printf("Prioridade: Muito Baixa\n");
            }
            if(l.tarefas[i].concluida == 1){
                printf("Status: Concluida\n");
            } else {
                printf("Status: Pendente\n");
            }
        }
    }
};
void imprimirTarefasPendentes(struct lista l){
    int encontrou = 0;
    if(l.tamanho == 0){
        printf("\nLista Vazia!\n");
    } else {
        printf("\nLista de tarefas pendentes:\n");
        for(int i = 0; i < l.tamanho; i++){
            if(l.tarefas[i].concluida == 0){
                printf("ID: %i\n", l.tarefas[i].id);
                printf("Descricao: %s\n", l.tarefas[i].descricao);
                if(l.tarefas[i].prioridade == 1){
                    printf("Prioridade: Extrema\n");
                } else if(l.tarefas[i].prioridade == 2){
                    printf("Prioridade: Alta\n");
                } else if(l.tarefas.prioridade == 3){
                    printf("Prioridade: Média\n");
                } else if(l.tarefas.prioridade == 4){
                    printf("Prioridade: Baixa\n");
                } else{
                    printf("Prioridade: Muito baixa\n");
                }
                printf("Status: Pendente\n");
                encontrou = 1;
            }
        }
        if(!encontrou){
            printf("Nenhuma tarefa pendente encontrada.\n");
        }
    }
};

int marcarConcluida(struct lista l, int id){
    for(int i = 0; i < l.tamanho; i++){
        if(l.tarefas[i].id == id){
           l.tarefas[i].concluida = 1;
           printf("Tarefa marcada como concluida com sucesso\n");
           return 0;
        }
    }
    printf("Tarefa com id %i nao encontrada\n", id);
    return -1;
};
int main(){
    struct lista l = inicializaTarefa();
    struct tarefa nova;
    int quantidade, i, id;
    char descricao[100];
    printf("Quantas tarefas você deseja cadastrar? ");
    scanf("%i", &quantidade);
    for(i = 0; i < quantidade; i++){
        printf("\nCadastrar Tarefa\n");
        printf("ID: ");
        scanf("%i", &nova.id);
        printf("Descricao da Tarefa: ");
        getchar();
        fgets(nova.descricao, 100, stdin);
        printf("Prioridade (1 - Baixa, 2 - Media, 3 - Alta): ");
        scanf("%i", &nova.prioridade);
        printf("Status (1 - Concluida, 0 - Pendente): ");
        scanf("%i", &nova.concluida);
        l = inserirTarefa(l, nova);
    }
    imprimirTarefas(l);

    printf("\nRemover Tarefa\n");
    printf("\nEntre com o id para remover\n");
    scanf("%i", &id);

    l = removerTarefa(l, id);
    imprimirTarefas(l);

    printf("\nQual Tarefa você quer buscar\n");
    scanf("%s", descricao);

    int indice = buscarDescricao(l, descricao);
    if (indice != -1) {
        printf("Tarefa encontrada:\n");
        printf("ID: %i\n", l.tarefas[indice].id);
        printf("Descricao: %s\n", l.tarefas[indice].descricao);
        if(l.tarefas[indice].prioridade == 1){
            printf("Prioridade: Baixa\n");
        } else if(l.tarefas[indice].prioridade == 2){
            printf("Prioridade: Media\n");
        } else {
            printf("Prioridade: Alta\n");
        }
        if(l.tarefas[indice].concluida == 1){
            printf("Status: Concluida\n");
        } else {
            printf("Status: Pendente\n");
        }
    } else {
        printf("Tarefa nao encontrada.\n");
    }

    printf("\nMarcar Tarefa como Concluida\n");
    printf("\nEntre com o id da tarefa a ser marcada como concluida\n");
    scanf("%i", &id);

    marcarConcluida(l, id);
    imprimirTarefas(l); 
    imprimirTarefasPendentes(l);
    return 0;
}