#include <stdio.h>


#define LINHAS_TABULEIRO 10
#define COLUNAS_TABULEIRO 10
#define TAMANHO_HABILIDADE 7


#define AGUA 0
#define NAVIO 3
#define EFEITO_HABILIDADE 5


void exibirTabuleiro(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]) {
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    printf("  ---------------------\n");
    for (int i = 0; i < LINHAS_TABULEIRO; i++) {
        printf("%d| ", i);
        for (int j = 0; j < COLUNAS_TABULEIRO; j++) {
            char simbolo = '.';
            switch (tabuleiro[i][j]) {
                case NAVIO:
                    simbolo = 'N';
                    break;
                case EFEITO_HABILIDADE:
                    simbolo = '*';
                    break;
                default:
                    simbolo = '.';
                    break;
            }
            printf("%c ", simbolo);
        }
        printf("|\n");
    }
    printf("  ---------------------\n\n");
}


void criarHabilidadeCruz(int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int tamanho) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == centro || j == centro) {
                matrizHabilidade[i][j] = 1;
            } else {
                matrizHabilidade[i][j] = 0;
            }
        }
    }
}


void criarHabilidadeCone(int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int tamanho) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                matrizHabilidade[i][j] = 1;
            } else {
                matrizHabilidade[i][j] = 0;
            }
        }
    }
}


void criarHabilidadeOctaedro(int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int tamanho) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            
            int distancia = (i > centro ? i - centro : centro - i) + (j > centro ? j - centro : centro - j);
            if (distancia <= centro) {
                matrizHabilidade[i][j] = 1;
            } else {
                matrizHabilidade[i][j] = 0;
            }
        }
    }
}


void sobreporHabilidade(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO], int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int tamanhoHabilidade, int origemLinha, int origemColuna) {
    int centroHabilidade = tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (matrizHabilidade[i][j] == 1) {

                int linhaNoTabuleiro = origemLinha - centroHabilidade + i;
                int colunaNoTabuleiro = origemColuna - centroHabilidade + j;
                if (linhaNoTabuleiro >= 0 && linhaNoTabuleiro < LINHAS_TABULEIRO &&
                    colunaNoTabuleiro >= 0 && colunaNoTabuleiro < COLUNAS_TABULEIRO) {
                    
                   
                    tabuleiro[linhaNoTabuleiro][colunaNoTabuleiro] = EFEITO_HABILIDADE;
                }
            }
        }
    }
}


int main() {
    int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO] = {0};
    
    tabuleiro[0][1] = NAVIO;
    tabuleiro[0][2] = NAVIO;
    tabuleiro[3][8] = NAVIO;
    tabuleiro[4][8] = NAVIO;
    tabuleiro[5][8] = NAVIO;
    tabuleiro[7][2] = NAVIO;
    tabuleiro[7][3] = NAVIO;
    
    printf("Tabuleiro inicial com os navios:\n");
    exibirTabuleiro(tabuleiro);

    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidadeCruz(habilidadeCruz, TAMANHO_HABILIDADE);
    criarHabilidadeCone(habilidadeCone, TAMANHO_HABILIDADE);
    criarHabilidadeOctaedro(habilidadeOctaedro, TAMANHO_HABILIDADE);
    
    // Aplicando a habilidade CRUZ no ponto (3, 3)
    printf("Aplicando habilidade CRUZ na origem (3, 3)...\n");
    sobreporHabilidade(tabuleiro, habilidadeCruz, TAMANHO_HABILIDADE, 3, 3);
    exibirTabuleiro(tabuleiro);

    // Aplicando a habilidade CONE no ponto (6, 7)
    printf("Aplicando habilidade CONE na origem (6, 7)...\n");
    sobreporHabilidade(tabuleiro, habilidadeCone, TAMANHO_HABILIDADE, 6, 7);
    exibirTabuleiro(tabuleiro);

    // Aplicando a habilidade OCTAEDRO no ponto (0, 8)
    printf("Aplicando habilidade OCTAEDRO na origem (0, 8)...\n");
    sobreporHabilidade(tabuleiro, habilidadeOctaedro, TAMANHO_HABILIDADE, 0, 8);
    exibirTabuleiro(tabuleiro);

    return 0;
}