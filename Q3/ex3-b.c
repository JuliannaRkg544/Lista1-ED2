#include <stdio.h>

// Fun��o para encontrar o maior n�mero no array
int encontrarMaior(int arr[], int n) {
    int maior = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

// Fun��o para realizar a ordena��o Counting Sort em um d�gito espec�fico
void countingSort(int arr[], int n, int exp) {
    int saida[n]; // Array de sa�da tempor�rio
    int contador[10] = {0}; // Contagem de d�gitos de 0 a 9

    // Contagem de d�gitos
    for (int i = 0; i < n; i++) {
        contador[(arr[i] / exp) % 10]++;
    }

    // Atualiza��o do contador para indicar a posi��o correta do d�gito
    for (int i = 1; i < 10; i++) {
        contador[i] += contador[i - 1];
    }

    // Constru��o do array de sa�da
    for (int i = n - 1; i >= 0; i--) {
        saida[contador[(arr[i] / exp) % 10] - 1] = arr[i];
        contador[(arr[i] / exp) % 10]--;
    }

    // Copiar o array de sa�da de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = saida[i];
    }
}

// Fun��o para realizar a ordena��o RadixSort
void radixSort(int arr[], int n) {
    int maior = encontrarMaior(arr, n);
    
    // Aplicar o Counting Sort para cada posi��o de d�gito, come�ando pelo menos significativo
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Fun��o para imprimir um array
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: \n");
    imprimirArray(arr, n);
    
    radixSort(arr, n);
    
    printf("Array ordenado: \n");
    imprimirArray(arr, n);
    
    return 0;
}
