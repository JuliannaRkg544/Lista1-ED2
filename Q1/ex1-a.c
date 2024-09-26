#include <stdio.h>
#include <stdlib.h>

void shellSort(int lista[], int ultimo) {
    // Definições Locais
    int valorAtual;
    int incremento;
    int posicao;

    // Incremento inicial: metade do tamanho da lista
    incremento = ultimo / 2;

    // Loop até que o incremento seja reduzido a 0
    while (incremento > 0) {
        // Executa a ordenação por inserção em elementos espaçados pelo incremento
        for (int atual = incremento; atual <= ultimo; atual++) {
            valorAtual = lista[atual];
            posicao = atual - incremento;

            // Desloca os elementos na partição atual
            while (posicao >= 0 && valorAtual < lista[posicao]) {
                lista[posicao + incremento] = lista[posicao];
                posicao -= incremento;
            }

            // Insere o valorAtual na posição correta
            lista[posicao + incremento] = valorAtual;
        }

        // Reduz o incremento para a próxima iteração
        incremento /= 2;
    }
}

int main() {
    int lista[50000];
    for (int i = 0; i<50000; i++){
        lista[i] = rand() % 200 + 1;
    }
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("Array antes da ordenação:\n");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", lista[i]);
    printf("\n");

    // Chamada para o shellSort
    shellSort(lista, tamanho - 1);

    printf("Array após a ordenação:\n");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", lista[i]);
    printf("\n");

    return 0;
}
