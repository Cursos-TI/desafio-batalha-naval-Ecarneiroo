#include <stdio.h>

/**
 * Batalha Naval - Nível Aventureiro
 * Foco: Matrizes e Posicionamento Diagonal
 */

int main() {
    #define TAM 10
    #define NAVIO 3
    
    // Inicializa o tabuleiro 10x10 com 0 (Água)
    int tabuleiro[TAM][TAM] = {0};

    // 1. NAVIO HORIZONTAL (Linha 1, Coluna 1 a 3)
    for (int j = 1; j < 1 + NAVIO; j++) {
        tabuleiro[1][j] = 3;
    }

    // 2. NAVIO VERTICAL (Linha 6 a 8, Coluna 2)
    for (int i = 6; i < 6 + NAVIO; i++) {
        tabuleiro[i][2] = 3;
    }

    // 3. NAVIO DIAGONAL (Descendente: Linha e Coluna aumentam)
    // Coordenada inicial: [2][5]. Posições: [2][5], [3][6], [4][7]
    for (int k = 0; k < NAVIO; k++) {
        tabuleiro[2 + k][5 + k] = 3;
    }

    // 4. NAVIO DIAGONAL (Ascendente: Linha aumenta, Coluna diminui)
    // Coordenada inicial: [7][7]. Posições: [7][7], [8][6], [9][5]
    for (int k = 0; k < NAVIO; k++) {
        tabuleiro[7 + k][7 - k] = 3;
    }

    // EXIBIÇÃO DO TABULEIRO
    printf("--- TABULEIRO AVENTUREIRO (10x10) ---\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
