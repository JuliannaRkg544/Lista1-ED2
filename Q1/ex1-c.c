#include <stdio.h>
#include <stdlib.h>  // Para usar rand()

// Função para mesclar dois subarrays
void merge(int lista[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Cria arrays temporários
    int esquerda[n1], direita[n2];

    // Copia os dados para os arrays temporários
    for (i = 0; i < n1; i++)
        esquerda[i] = lista[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = lista[meio + 1 + j];

    // Mescla os arrays temporários de volta em lista[inicio..fim]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = inicio; // Índice inicial do array mesclado
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            lista[k] = esquerda[i];
            i++;
        } else {
            lista[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de esquerda[], se houver
    while (i < n1) {
        lista[k] = esquerda[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de direita[], se houver
    while (j < n2) {
        lista[k] = direita[j];
        j++;
        k++;
    }
}

// Função principal de Merge Sort
void mergeSort(int lista[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(lista, inicio, meio);
        mergeSort(lista, meio + 1, fim);

        // Mescla as duas metades
        merge(lista, inicio, meio, fim);
    }
}

int main() {
    int lista[50000];  // Declara um array de 50.000 elementos
printf("mergesort");
    // Preenche o array com números aleatórios 
    for (int i = 0; i < 50000; i++) {
        lista[i] = rand() % 200 + 1;
    }
 printf("Array antes da ordenação:\n");
    for (int i = 0; i < 50000; i++)
        printf("%d ", lista[i]);
    printf("\n");
    // Chama o Merge Sort
    mergeSort(lista, 0, 50000 - 1);

   

      printf("Array após a ordenação:\n");
    for (int i = 0; i <  50000; i++)
        printf("%d ", lista[i]);
    printf("\n");

    return 0;
}
