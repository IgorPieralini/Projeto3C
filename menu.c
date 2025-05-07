#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variável global do tabuleiro
char tabuleiro[3][3];

// Mostra o tabuleiro formatado
void mostrarTabuleiro() {
    printf("\n");
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            char c = tabuleiro[linha][coluna];
            if (c == ' ')
                printf(" %d ", linha * 3 + coluna + 1);
            else
                printf(" %c ", c);
            if (coluna < 2) printf("|");
        }
        printf("\n");
        if (linha < 2) printf("-----------\n");
    }
    printf("\n");
}

// Inicializa o tabuleiro
void iniciarTabuleiro() {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            tabuleiro[linha][coluna] = ' ';
        }
    }
}

// Verifica se há um vencedor
int verificarVencedor() {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1;
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return 1;
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1;

    return 0;
}

// Verifica se o tabuleiro está cheio
int tabuleiroCheio() {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro[linha][coluna] == ' ')
                return 0;
        }
    }
    return 1;
}

// Salva o resultado no arquivo com data e hora
void salvarHistorico(const char* resultado) {
    FILE *arquivo = fopen("historico.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de histórico.\n");
        return;
    }

    time_t agora = time(NULL);
    struct tm *tempo = localtime(&agora);
    
    fprintf(arquivo, "%s no dia %02d/%02d/%04d às %02d:%02d\n",
            resultado,
            tempo->tm_mday,
            tempo->tm_mon + 1,
            tempo->tm_year + 1900,
            tempo->tm_hour,
            tempo->tm_min);

    fclose(arquivo);
}

// Função principal do jogo
void jogar() {
    int posicao, linha, coluna, jogador = 1;
    char simbolo;

    iniciarTabuleiro();

    while (1) {
        mostrarTabuleiro();
        simbolo = (jogador == 1) ? 'X' : 'O';
        printf("Jogador %d (%c), escolha uma posição (1 a 9): ", jogador, simbolo);
        scanf("%d", &posicao);

        if (posicao < 1 || posicao > 9) {
            printf("Posição inválida! Escolha entre 1 e 9.\n");
            continue;
        }

        linha = (posicao - 1) / 3;
        coluna = (posicao - 1) % 3;

        if (tabuleiro[linha][coluna] != ' ') {
            printf("Essa posição já foi escolhida! Tente outra.\n");
            continue;
        }

        tabuleiro[linha][coluna] = simbolo;

        if (verificarVencedor()) {
            mostrarTabuleiro();
            printf("Jogador %d venceu! Parabéns!\n", jogador);

            char resultado[100];
            snprintf(resultado, sizeof(resultado), "Jogador %d ganhou do jogador %d", jogador, (jogador == 1 ? 2 : 1));
            salvarHistorico(resultado);
            break;
        }

        if (tabuleiroCheio()) {
            mostrarTabuleiro();
            printf("Empate! Ninguém venceu.\n");
            salvarHistorico("O jogo terminou em empate");
            break;
        }

        jogador = (jogador == 1) ? 2 : 1;
    }
}

// Mostra o conteúdo do histórico
void verHistorico() {
    FILE *arquivo = fopen("historico.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum histórico encontrado.\n");
        return;
    }

    char linha[256];
    printf("\n--- HISTÓRICO DE JOGOS ---\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    fclose(arquivo);
    printf("--------------------------\n");
}

// Menu principal
int main() {
    int opcao;
    int rodando = 1;

    while (rodando) {
        printf("\n--- MENU ---\n");
        printf("1. Jogar\n");
        printf("2. Ver Histórico\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogar();
                break;
            case 2:
                verHistorico();
                break;
            case 3:
                printf("Saindo...\n");
                rodando = 0;
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
