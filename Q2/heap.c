#include <stdio.h>
#include <stdlib.h>

// Estrutura para elementos da fila de prioridade
typedef struct {
    int priority; // Prioridade do elemento
    int order;    // Ordem de chegada
} PriorityQueueElement;

// Função para criar um heap máximo
void criaHeap(PriorityQueueElement arr[], int pai, int fim) {
    PriorityQueueElement aux = arr[pai];
    int filho = 2 * pai + 1;

    // Reorganiza o heap
    while (filho <= fim) {
        // Verifica se o filho da esquerda é maior que o filho da direita
        if (filho < fim) {
            if (arr[filho].priority > arr[filho + 1].priority) {
                filho++;
            } else if (arr[filho].priority == arr[filho + 1].priority && arr[filho].order < arr[filho + 1].order) {
                filho++;
            }
        }

        // Move o pai para baixo se necessário
        if (aux.priority > arr[filho].priority || 
            (aux.priority == arr[filho].priority && aux.order < arr[filho].order)) {
            arr[pai] = arr[filho];
            pai = filho;
            filho = 2 * pai + 1;
        } else {
            filho = fim + 1;
        }
    }
    arr[pai] = aux; // Coloca o elemento pai na posição correta
}

// Função para realizar o Heap Sort
void heapSort(PriorityQueueElement arr[], int n) {
    int i;
    PriorityQueueElement aux;

    // Cria o heap máximo
    for (i = (n - 1) / 2; i >= 0; i--) {
        criaHeap(arr, i, n - 1);
    }

    // Ordena o vetor usando Heap Sort
    for (i = n - 1; i >= 1; i--) {
        // Troca o primeiro elemento (máximo) com o último
        aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;

        // Reorganiza o heap
        criaHeap(arr, 0, i - 1);
    }
}

// Função principal
int main() {
    // Inicializa o vetor com prioridades e ordens de chegada
    PriorityQueueElement input[] = {
        {5, 1}, // Prioridade 5, chegou primeiro
        {4, 2}, // Prioridade 4, chegou segundo
        {3, 3}, // Prioridade 3, chegou terceiro
        {5, 4}  // Prioridade 5, chegou último
    };
    int n = sizeof(input) / sizeof(input[0]);

    // Imprime o vetor inicial
    printf("Vetor Inicial:\n");
    for (int i = 0; i < n; i++) {
        printf("Prioridade: %d, Ordem: %d\n", input[i].priority, input[i].order);
    }
    printf("\n");

    // Calcula a prioridade final
    for (int i = 0; i < n; i++) {
        input[i].priority = (input[i].priority * 100) + (10 - input[i].order);
    }

    // Imprime o vetor com prioridade final
    printf("Vetor com Prioridade Final (baseada em prioridade e ordem de chegada):\n");
    for (int i = 0; i < n; i++) {
        printf("Prioridade Final: %d\n", input[i].priority);
    }
    printf("\n");

    // Ordena o vetor usando HeapSort
    heapSort(input, n);

    // Imprime o vetor ordenado por prioridade
    printf("Vetor Ordenado por Prioridade Final:\n");
    for (int i = 0; i < n; i++) {
        printf("Prioridade Final: %d, Ordem: %d\n", input[i].priority, input[i].order);
    }
    printf("\n");

    return 0;
}
