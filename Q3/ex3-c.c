#include <stdio.h>
#include <stdlib.h>

// Função de inserção para ordenar os elementos dentro dos baldes
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função de ordenação Bucket Sort
void bucket_sort(int A[], int n) {
    // Encontre o valor máximo no array
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    // Crie "n" baldes (arrays) para armazenar os elementos
    int bucket_count = n;
    int **buckets = (int **)malloc(bucket_count * sizeof(int *));
    int *bucket_sizes = (int *)malloc(bucket_count * sizeof(int));

    // Inicialize cada balde
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int)); // Cada balde pode conter até "n" elementos
        bucket_sizes[i] = 0;
    }

    // Distribua os elementos nos baldes com base no intervalo
    for (int i = 0; i < n; i++) {
        int bucket_index = (A[i] * bucket_count) / (max + 1); // Defina o índice do balde
        buckets[bucket_index][bucket_sizes[bucket_index]++] = A[i];
    }

    // Ordene cada balde usando o algoritmo de inserção
    for (int i = 0; i < bucket_count; i++) {
        insertion_sort(buckets[i], bucket_sizes[i]);
    }

    // Concatenar os baldes no array original
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            A[index++] = buckets[i][j];
        }
        free(buckets[i]); // Liberar memória de cada balde
    }

    // Liberar memória
    free(buckets);
    free(bucket_sizes);
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

    bucket_sort(A, n);

    printf("Array ordenado:\n");
    print_array(A, n);

    return 0;
}
