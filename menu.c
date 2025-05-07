#include <stdio.h>
#include <stdlib.h>

void jogar() {
    printf("Você escolheu jogar!\n");
    // LÓGICA DO JOGO
}

void verHistorico() {
    printf("Exibindo histórico...\n");
    // LOGICA DO HISTORICO
}

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