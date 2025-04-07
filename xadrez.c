#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Nível Mestre - Funções Recursivas e Loops Aninhados

// Função recursiva para simular o movimento da Torre para a Direita
void moverTorre(int casasRestantes) {
    if (casasRestantes <= 0) return;

    printf("Direita\n");
    moverTorre(casasRestantes - 1);
}

// Função recursiva para simular o movimento da Rainha para a Esquerda
void moverRainha(int casasRestantes) {
    if (casasRestantes <= 0) return;

    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

// Função recursiva para simular o movimento do Bispo em Diagonal (Cima Direita)
void moverBispoRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) return;

    printf("Cima Direita\n");
    moverBispoRecursivo(casasRestantes - 1);
}

// Função com loops aninhados para simular o movimento do Bispo em um plano 5x5 (Cima Direita)
void moverBispoComLoops(int passosVerticais, int passosHorizontais) {
    for (int i = 1; i <= passosVerticais; i++) {
        for (int j = 1; j <= passosHorizontais; j++) {
            printf("Cima Direita\n");
        }
    }
}

// Função para movimentar o Cavalo em "L": duas casas para cima e uma para a direita
void moverCavalo() {
    const int movimentosVerticais = 2;
    const int movimentosHorizontais = 1;

    printf("Movimentação do Cavalo:\n");

    for (int v = 1, h = 0; v <= movimentosVerticais || h < movimentosHorizontais; ) {
        // Se o cavalo ainda precisa subir
        if (v <= movimentosVerticais) {
            printf("Cima\n");
            v++;
            continue; // Continue para evitar que a casa "Direita" ocorra antes do tempo
        }

        // Quando as casas para cima foram feitas, movemos uma para direita
        if (h < movimentosHorizontais) {
            printf("Direita\n");
            h++;
        }

        // Segurança: quebrar se ultrapassar os limites esperados
        if (v > movimentosVerticais && h >= movimentosHorizontais) {
            break;
        }
    }
}

int main() {
    // Constantes para número de casas
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;

    // Movimentação da Torre
    printf("Movimentação da Torre:\n");
    moverTorre(casasTorre);

    printf("\n");

    // Movimentação do Bispo com recursividade
    printf("Movimentação do Bispo (com recursividade):\n");
    moverBispoRecursivo(casasBispo);

    printf("\n");

    // Movimentação do Bispo com loops aninhados
    printf("Movimentação do Bispo (com loops aninhados):\n");
    moverBispoComLoops(2, 2); // Simula 2x2 passos diagonais

    printf("\n");

    // Movimentação da Rainha
    printf("Movimentação da Rainha:\n");
    moverRainha(casasRainha);

    printf("\n");

    // Movimentação do Cavalo
    moverCavalo();

    return 0;
}
