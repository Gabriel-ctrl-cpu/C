#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
    int i, n;
    char **v;
    
    printf("quantos nomes vc deseja cadastrar: ");
    scanf("%d",&n);
    getchar();
   
    v = (char**) malloc(n * sizeof(char *));
    if (v == NULL) 
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++)
    {
    v[i] = (char *) malloc(50 * sizeof(char));
    if (v[i] == NULL) 
    {
        printf("Erro ao alocar memoria para o nome %d.\n", i + 1);
            return 1;
    }
    }
    
    for(i = 0; i < n; i++){
        printf("digite o nome: ");
        fgets(v[i], 50, stdin);
        
        v[i][strcspn(v[i], "\n")] = '\0';
    }
    
    for(i = 0; i < n; i++){
        printf("\nnome %d: %s",i+1,v[i]);
    }
    
    for(i = 0; i < n; i++) {
    free(v[i]);
    }
    
    free(v);
    
    return 0;
}