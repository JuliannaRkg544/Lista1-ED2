#include <stdio.h>
#include <stdlib.h>  // Para usar a função rand()

// Função para garantir que o heap esteja estruturado corretamente (Heapify)
void heapify(int lista[], int n, int i) {
    int maior = i;  // Inicializa o maior como raiz
    int esquerda = 2 * i + 1;  // Filho à esquerda
    int direita = 2 * i + 2;   // Filho à direita

    // Se o filho à esquerda é maior que a raiz
    if (esquerda < n && lista[esquerda] > lista[maior])
        maior = esquerda;

    // Se o filho à direita é maior que o maior até agora
    if (direita < n && lista[direita] > lista[maior])
        maior = direita;

    // Se o maior não for a raiz
    if (maior != i) {
        // Troca a raiz com o maior filho
        int temp = lista[i];
        lista[i] = lista[maior];
        lista[maior] = temp;

        // Heapify o sub-heap afetado recursivamente
        heapify(lista, n, maior);
    }
}

// Função principal de Heap Sort
void heapSort(int lista[], int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(lista, n, i);

    // Um por um, extrai os elementos do heap
    for (int i = n - 1; i >= 0; i--) {
        // Move a raiz atual para o final
        int temp = lista[0];
        lista[0] = lista[i];
        lista[i] = temp;

        // Chama heapify na heap reduzida
        heapify(lista, i, 0);
    }
}

int main() {
    int lista[50000];  // Declaração de um array com 50.000 elementos

    // Preenche o array com números aleatórios entre 1 e 10
    for (int i = 0; i < 50000; i++) {
        lista[i] = rand() % 10 + 1;
    }

    // Exibe os primeiros 10 elementos antes da ordenação
    printf("Primeiros 10 elementos antes da ordenação:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    // Chama o Heap Sort
    heapSort(lista, 50000);

    // Exibe os primeiros 10 elementos após a ordenação
    printf("Primeiros 10 elementos após a ordenação:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}
