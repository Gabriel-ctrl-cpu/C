#include <stdio.h>
#include <stdlib.h>

float media(int n, float *v){
    int i;
    float s = 0.0f;
    for(i=0; i<n;i++)
    {
        s += v[i];
    }
    return s/n;
}
float soma(int n, float *v){
    int i;
    float s = 0.0f;
    for(i=0; i < n ;i++)
    {
        s += v[i];
    }
    return s;
}
float maior(int n,float *v){
    int i;
    float maior = v[0];
    for (i = 0; i < n; i++){
        if(maior < v[i]){
            maior = v[i];
        }
    }
    return maior;
}
float menor(int n,float *v){
    int i;
    float menor = v[0];
    for (i = 0; i < n; i++){
        if(menor > v[i]){
            menor = v[i];
        }
    }
    return menor;
}
int main(){
    int i, n;
    float *v, med, men, mai, som;
    
    printf("quantos numeros vc deseja cadastrar: ");
    scanf("%d",&n);
    
    v = (float *) malloc(n * sizeof(float));
    if (v == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    
    for(i = 0; i < n; i++){
        printf("Digite o numero: ");
        scanf("%f", &v[i]);
    }
    som = soma(n,v);
    med = media(n,v);
    mai = maior(n,v);
    men = menor(n,v);
    
    printf("\nsoma: %0.2f", som);
    printf("\nmedia: %0.2f", med);
    printf("\nmaior: %0.2f", mai);
    printf("\nmenor: %0.2f", men);
    
    free(v);
    return 0;
}