#include <stdio.h>
#include <stdlib.h> // Para a função abs() usada no cálculo do octaedro

/**
 * Batalha Naval - Nível Mestre
 * Foco: Matrizes de Habilidade, Áreas de Efeito (AoE) e Lógica Geométrica
 */

#define TAM 10
#define TAM_HAB 5 // Tamanho da matriz de habilidade (5x5)

// Função para exibir o tabuleiro de forma organizada
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Representação visual: 0=., 3=N, 5=*
            if (tabuleiro[i][j] == 3) printf("N ");
            else if (tabuleiro[i][j] == 5) printf("* ");
            else printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // --- Posicionamento dos Navios (do nível anterior) ---
    for (int i = 0; i < 3; i++) tabuleiro[1][1 + i] = 3; // Horizontal
    for (int i = 0; i < 3; i++) tabuleiro[5 + i][8] = 3; // Vertical

    // --- Definição das Matrizes de Habilidade ---
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    // Construção Dinâmica das Matrizes
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Lógica do Cone (Triângulo apontando para baixo)
            if (i == 0 && j == 2) cone[i][j] = 1;
            if (i == 1 && j >= 1 && j <= 3) cone[i][j] = 1;
            if (i == 2) cone[i][j] = 1;

            // Lógica da Cruz (Centro na linha 2, coluna 2)
            if (i == 2 || j == 2) cruz[i][j] = 1;

            // Lógica do Octaedro (Losango)
            // Distância de Manhattan: |x1 - x2| + |y1 - y2| <= 2
            if (abs(i - 2) + abs(j - 2) <= 2) octaedro[i][j] = 1;
        }
    }

    // --- Sobreposição das Habilidades no Tabuleiro ---
    // Origens (Ponto central da matriz 5x5 no tabuleiro)
    int origens[3][2] = {{0, 5}, {4, 1}, {7, 4}}; // Cone, Cruz, Octaedro

    // Aplicando as habilidades (Exemplo com Octaedro no centro do tabuleiro)
    int origemL = 7, origemC = 4;
    
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Cálculo da posição real no tabuleiro (centralizando a matriz 5x5)
            int tabL = origemL + (i - 2);
            int tabC = origemC + (j - 2);

            // Verificação de limites e aplicação do efeito (Octaedro)
            if (tabL >= 0 && tabL < TAM && tabC >= 0 && tabC < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[tabL][tabC] != 3) {
                    tabuleiro[tabL][tabC] = 5; // 5 representa a área de efeito
                }
            }
        }
    }

    printf("--- TABULEIRO MESTRE: ÁREA DE EFEITO (OCTAEDRO) ---\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
