#include <stdio.h>
#include <math.h>

// ===== Função para imprimir a matriz aumentada =====
void imprimirMatriz(float a[10][11], int n) {
    int i, j;
    // Percorre todas as linhas da matriz
    for (i = 0; i < n; i++) {
        // Percorre todas as colunas (incluindo a coluna dos termos independentes)
        for (j = 0; j <= n; j++) {
            printf("%8.3f ", a[i][j]);  // Imprime cada valor da matriz com 3 casas decimais
        }
        printf("\n");  // Nova linha para a próxima linha da matriz
    }
    printf("---------------------------------------------\n");  // Linha de separação
}

int main() {
    int i, j, k, n;
    float a[10][11], x[10], fator, temp;

    // ===== Entrada de dados =====
    printf("Digite a ordem do sistema (número de variáveis): ");
    scanf("%d", &n);  // O usuário digita o número de variáveis (ordem do sistema)

    printf("\nDigite os elementos da matriz aumentada (coeficientes e termos independentes):\n");
    // O usuário digita os elementos da matriz aumentada (coeficientes e termos independentes)
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);  // Preenche a matriz com os valores fornecidos pelo usuário
        }
    }

    printf("\n===== MATRIZ INICIAL =====\n");
    imprimirMatriz(a, n);  // Exibe a matriz inicial

    // ===== ETAPA 1: ELIMINAÇÃO DIRETA COM PIVOTAMENTO PARCIAL =====
    for (i = 0; i < n - 1; i++) {  // Loop sobre cada linha (exceto a última)
        
        // --- PIVOTAMENTO: encontrar o maior valor absoluto na coluna i ---
        int max = i;
        for (k = i + 1; k < n; k++) {  // Busca o maior valor absoluto na coluna 'i'
            if (fabs(a[k][i]) > fabs(a[max][i])) {  // Compara os valores absolutos
                max = k;  // Atualiza o índice do maior valor
            }
        }

        // --- Se necessário, troca as linhas ---
        if (max != i) {  // Se o maior valor não estiver na linha atual (i)
            for (j = 0; j <= n; j++) {  // Troca as linhas
                temp = a[i][j];
                a[i][j] = a[max][j];
                a[max][j] = temp;
            }
            printf("\n> Troca da linha %d com linha %d (pivotamento)\n", i + 1, max + 1);
            imprimirMatriz(a, n);  // Exibe a matriz após a troca
        }

        // --- Verifica se o pivô é zero ---
        if (a[i][i] == 0) {  // Se o pivô é zero, o sistema pode não ter solução única
            printf("Erro: pivô nulo encontrado. O sistema pode não ter solução única.\n");
            return 1;  // Termina o programa com erro
        }

        // --- Eliminação abaixo do pivô ---
        for (k = i + 1; k < n; k++) {  // Para todas as linhas abaixo da linha atual (i)
            fator = a[k][i] / a[i][i];  // Calcula o fator de eliminação
            printf("Eliminando elemento A[%d][%d] usando fator = %.3f\n", k + 1, i + 1, fator);

            // Subtrai o fator multiplicado pela linha i das outras linhas
            for (j = i; j <= n; j++) {
                a[k][j] = a[k][j] - fator * a[i][j];
            }
        }

        // Exibe a matriz após a eliminação
        printf("\nMatriz após a etapa %d de eliminação:\n", i + 1);
        imprimirMatriz(a, n);
    }

    // ===== ETAPA 2: SUBSTITUIÇÃO REGRESSIVA =====
    for (i = n - 1; i >= 0; i--) {  // Começando da última linha, resolve as variáveis de baixo para cima
        x[i] = a[i][n];  // A última coluna é o termo independente
        for (j = i + 1; j < n; j++) {  // Para as variáveis já calculadas, subtraímos os valores
            x[i] = x[i] - a[i][j] * x[j];  // Subtrai o valor multiplicado da variável já resolvida
        }

        // --- Verifica se o pivô é zero ---
        if (a[i][i] == 0) {  // Se o pivô é zero, o sistema é indeterminado
            printf("Erro: divisão por zero detectada. O sistema pode ser indeterminado.\n");
            return 1;  // Termina o programa com erro
        }

        // Calcula o valor da variável atual dividindo pelo pivô
        x[i] = x[i] / a[i][i];
    }

    // ===== EXIBE O RESULTADO FINAL =====
    printf("\n===== RESULTADO FINAL =====\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);  // Exibe o valor de cada variável x1, x2, ...
    }

    return 0;  // Fim do programa
}