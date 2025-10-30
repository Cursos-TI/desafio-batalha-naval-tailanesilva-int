/*
 * Desafio Batalha Naval - Nível Novato
 *
 * Objetivo: Criar um tabuleiro 10x10, inicializá-lo com 0 (água)
 * e posicionar dois navios de tamanho 3 (um horizontal, um vertical)
 * representados pelo valor 3. O tabuleiro final deve ser exibido.
 */

#include <stdio.h> // Para funções de entrada e saída (printf)

// --- Constantes do Jogo ---
// Usar constantes torna o código mais fácil de ler e modificar.
#define TAM_TABULEIRO 10 // Tamanho da linha e coluna do tabuleiro
#define TAM_NAVIO 3      // Tamanho fixo dos navios
#define AGUA 0           // Valor para representar a água no tabuleiro
#define NAVIO 3          // Valor para representar um navio no tabuleiro

/**
 * @brief Função principal que executa o programa.
 */
int main() {
    
    // 1. Representar o Tabuleiro
    // Declara uma matriz 10x10 para o tabuleiro.
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Variáveis de controle para os loops (iteradores)
    int i, j;

    // Inicializa todo o tabuleiro com ÁGUA (0)
    // Loop aninhado para percorrer cada célula da matriz
    for (i = 0; i < TAM_TABULEIRO; i++) { // Loop para as linhas (i)
        for (j = 0; j < TAM_TABULEIRO; j++) { // Loop para as colunas (j)
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionar os Navios
    
    // Declara um "vetor" modelo para os navios, como sugerido na Dica.
    // Todos os navios terão tamanho 3 e serão representados pelo valor NAVIO.
    int navio_modelo[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // {3, 3, 3}

    // --- Navio 1: Posicionamento Horizontal ---
    
    // Define as coordenadas iniciais (linha, coluna) fixas no código
    int navioH_linha = 2;
    int navioH_coluna = 1;

    // Validação: Verifica se o navio cabe no tabuleiro
    // A coluna inicial + tamanho do navio não pode ultrapassar o tamanho do tabuleiro
    if (navioH_coluna + TAM_NAVIO <= TAM_TABULEIRO) {
        // Posiciona o navio horizontalmente
        printf("Posicionando navio horizontal em (%d, %d)\n", navioH_linha, navioH_coluna);
        
        // Loop para "copiar" as partes do navio para o tabuleiro
        for (j = 0; j < TAM_NAVIO; j++) {
            // A linha permanece a mesma (navioH_linha)
            // A coluna é incrementada (navioH_coluna + j)
            tabuleiro[navioH_linha][navioH_coluna + j] = navio_modelo[j];
        }
    } else {
        // Mensagem de erro caso a coordenada seja inválida
        printf("Erro: Coordenadas do navio horizontal fora dos limites!\n");
    }

    // --- Navio 2: Posicionamento Vertical ---
    
    // Define as coordenadas iniciais (linha, coluna) fixas no código
    // Escolhemos coordenadas que (sabidamente) não sobrepõem o navio horizontal
    int navioV_linha = 5;
    int navioV_coluna = 5;

    // Validação: Verifica se o navio cabe no tabuleiro
    // A linha inicial + tamanho do navio não pode ultrapassar o tamanho do tabuleiro
    if (navioV_linha + TAM_NAVIO <= TAM_TABULEIRO) {
        // Posiciona o navio verticalmente
        printf("Posicionando navio vertical em (%d, %d)\n", navioV_linha, navioV_coluna);

        // Loop para "copiar" as partes do navio para o tabuleiro
        for (i = 0; i < TAM_NAVIO; i++) {
            // A linha é incrementada (navioV_linha + i)
            // A coluna permanece a mesma (navioV_coluna)
            tabuleiro[navioV_linha + i][navioV_coluna] = navio_modelo[i];
        }
    } else {
        // Mensagem de erro caso a coordenada seja inválida
        printf("Erro: Coordenadas do navio vertical fora dos limites!\n");
    }
    
    // 3. Exibir o Tabuleiro
    printf("\n--- Tabuleiro de Batalha Naval ---\n\n");

    // Opcional: Imprime cabeçalho das colunas (0 a 9) para facilitar visualização
    printf("  "); // Espaço para alinhar com o cabeçalho das linhas
    for (j = 0; j < TAM_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n"); // Pula para a próxima linha

    // Loop aninhado para exibir o conteúdo do tabuleiro
    for (i = 0; i < TAM_TABULEIRO; i++) {
        // Opcional: Imprime cabeçalho da linha (0 a 9)
        printf("%d ", i);
        
        // Imprime os valores de cada coluna para a linha 'i'
        for (j = 0; j < TAM_TABULEIRO; j++) {
            // Imprime o valor da célula (0 ou 3) seguido de um espaço
            printf("%d ", tabuleiro[i][j]);
        }
        // Ao final de cada linha, imprime um caractere de nova linha
        printf("\n");
    }

    return 0; // Indica que o programa terminou com sucesso
}