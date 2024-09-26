#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior valor no array
int find_max(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Função de ordenação Counting Sort
void counting_sort(int A[], int n) {
    // Encontrar o maior valor em A para determinar o valor de k
    int k = find_max(A, n);

    // Alocar espaço para o array C (de tamanho k+1) e inicializá-lo com 0
    int *C = (int *)calloc(k + 1, sizeof(int));
    
    // Alocar espaço para o array B (array de saída ordenada)
    int *B = (int *)malloc(n * sizeof(int));

    // Passo 1: Contar quantas vezes cada elemento aparece em A
    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    // Passo 2: Modificar C para que C[i] contenha o número de elementos menores ou iguais a i
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    // Passo 3: Construir o array B ordenado
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    // Copiar os valores de B de volta para A
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

    // Liberar a memória alocada
    free(C);
    free(B);
}

// Função para imprimir o array
void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    // Exemplo de uso
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original:\n");
    print_array(A, n);

    counting_sort(A, n);

    printf("Array ordenado:\n");
    print_array(A, n);

    return 0;
}
