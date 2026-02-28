#include <stdio.h>

/**
 * Batalha Naval - Nível Novato
 * Foco: Matrizes, Vetores e Posicionamento
 */

int main() {
    // Definição das dimensões do tabuleiro e tamanho dos navios
    #define TAM_TABULEIRO 10
    #define TAM_NAVIO 3

    // Inicialização da matriz do tabuleiro com 0 (Água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Zerando o tabuleiro usando loops aninhados
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vetores que representam os navios (cada posição com valor 3)
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais (Lembre-se: índices em C começam em 0)
    int linhaH = 2, colunaH = 1; // Navio Horizontal começa em [2][1]
    int linhaV = 5, colunaV = 8; // Navio Vertical começa em [5][8]

    // --- Posicionamento do Navio Horizontal ---
    // Verificamos se cabe no tabuleiro: colunaH + TAM_NAVIO deve ser <= TAM_TABULEIRO
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    // --- Posicionamento do Navio Vertical ---
    // Verificamos se cabe no tabuleiro: linhaV + TAM_NAVIO deve ser <= TAM_TABULEIRO
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Aqui incrementamos a linha, mantendo a coluna fixa
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    // --- Exibição do Tabuleiro ---
    printf("--- TABULEIRO BATALHA NAVAL ---\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha ao final de cada linha da matriz
    }

    return 0;
}
