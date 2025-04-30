#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Definições de constantes para melhorar a legibilidade e manutenção
#define TAMANHO_VETOR 25
#define TENTATIVAS_MAXIMAS 3
#define MOVIMENTOS_MAXIMOS 5
#define POSICAO_INICIAL 10

// Definição da combinação correta do cofre
#define ZERO_CORRETO 2
#define DOIS_CORRETO 2
#define QUATRO_CORRETO 0
#define SEIS_CORRETO 4
#define OITO_CORRETO 2
#define NOVE_CORRETO 0

// Função para limpar a tela (compatível com diferentes sistemas)
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Função para pausar a execução (compatível com diferentes sistemas)
void pausar() {
    printf("\n\tPressione ENTER para continuar...\n");
    getchar(); // Consume newline deixado pelo scanf
    getchar(); // Aguarda a entrada do usuário
}

// Função para exibir a arte do cofre
void exibirCofre() {
    printf("\n\n\n");
    printf("\t******************************\n");
    printf("\t*                            *\n");
    printf("\t*  ***********************   *\n");
    printf("\t*  *                     *   *\n");
    printf("\t*  *                     *   *\n");
    printf("\t*  *                     *   *\n");
    printf("\t*  *                     *   *\n");
    printf("\t*  *                     *   *\n");
    printf("\t*  *    *                *   *\n");
    printf("\t*  *    *            *   *   *\n");
    printf("\t*  *    *           * *  *   *\n");
    printf("\t*  *    *            *   *   *\n");
    printf("\t*  *                     *   *\n");
    printf("\t*  ***********************   *\n");
    printf("\t*                            *\n");
    printf("\t******************************");
    printf("\n\n\n");
}

// Função para exibir a arte de senha correta
void exibirCofreAberto() {
    printf("\t******************************\n");
    printf("\t*                            *\n");
    printf("\t*  ***********************   *\n");
    printf("\t*  *   *                 *   *\n");
    printf("\t*  *   *                 *   *\n");
    printf("\t*  *   *                 *   *\n");
    printf("\t*  *   *                 *   *\n");
    printf("\t*  *   *$                *   *\n");
    printf("\t*  *   *$$              $*   *\n");
    printf("\t*  * * *$$$$          $$$*   *\n");
    printf("\t*  * * *$$$$$$$    $$$$$$*   *\n");
    printf("\t*  *   *$$$$$$$$$$$$$$$$$*   *\n");
    printf("\t*  *   *&$$$$$$$$$$$$$$$$*   *\n");
    printf("\t*  ***********************   *\n");
    printf("\t*                            *\n");
    printf("\t******************************");
    printf("\n\t");
}

// Função para exibir a arte de senha incorreta
void exibirSenhaIncorreta() {
    printf("\n\n\n");
    printf("\t*          *"); printf("\n");
    printf("\t *        * "); printf("\n");
    printf("\t  *      *  "); printf("\n");
    printf("\t   *    *   "); printf("\n");
    printf("\t    *  *    "); printf("\n");
    printf("\t     **     "); printf("\n");
    printf("\t     **     "); printf("\n");
    printf("\t    *  *    "); printf("\n");
    printf("\t   *    *   "); printf("\n");
    printf("\t  *      *  "); printf("\n");
    printf("\t *        * "); printf("\n");
    printf("\t*          *"); printf("\n");
    printf("\n\n\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL)); // Inicializa a semente aleatória

    int vetor[TAMANHO_VETOR] = {2, 0, 4, 2, 8, 6, 9, 8, 9, 4, 0, 2, 6, 6, 8, 0, 9, 0, 9, 4, 2, 6, 8, 8, 4};
    int movimentos_restantes = MOVIMENTOS_MAXIMOS;
    int tentativas_restantes = TENTATIVAS_MAXIMAS;
    int posicao_atual = POSICAO_INICIAL;
    int destino;
    int zero, dois, quatro, seis, oito, nove; // Contadores para a tentativa atual
    int posicao_anterior;

    limparTela();

    printf("\n\tBem-vindo!\n\n\tNo programa em questão você tentará abrir o cofre abaixo:\n");
    exibirCofre();
    printf("\n\n\tPara isso, você deverá escolher uma posição para 'girar' o disco de combinação.\n");
    printf("\n\tO disco começará na posição %d e você tem até %d movimentações por tentativa entre as posições 0 e %d.\n",
           POSICAO_INICIAL, MOVIMENTOS_MAXIMOS, TAMANHO_VETOR - 1);
    printf("\n\tPara selecionar a posição desejada, digite o número da posição e pressione ENTER.\n");
    printf("\n\tCaso ache que tenha a combinação correta antes de usar suas %d movimentações,\n", MOVIMENTOS_MAXIMOS);
    printf("\tapenas digite um número negativo e pressione ENTER para parar e conferir.\n");
    printf("\n\tVocê terá %d tentativas para realizar a abertura, caso contrário o programa se encerrará.\n", TENTATIVAS_MAXIMAS);
    printf("\n\tA cada falha, o processo será reiniciado do zero, com a posição inicial do cofre retornando à posição %d.\n", POSICAO_INICIAL);

    pausar();
    limparTela();

    while (tentativas_restantes > 0) {
        movimentos_restantes = MOVIMENTOS_MAXIMOS;
        posicao_atual = POSICAO_INICIAL;
        zero = dois = quatro = seis = oito = nove = 0;

        do {
            printf("\n\t%d Movimentos restantes.", movimentos_restantes);
            printf("\n\tPosição atual do cofre: %d", posicao_atual);
            printf("\n\tDigite a posição para mover o cofre (0-%d, ou negativo para tentar abrir): ", TAMANHO_VETOR - 1);
            if (scanf("%d", &destino) != 1) {
                printf("\n\tEntrada inválida. Tente novamente.\n");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
                continue;
            }

            if (destino < 0) {
                break; // Sai do loop de movimentos para verificar a senha
            } else if (destino < 0 || destino >= TAMANHO_VETOR) {
                printf("\n\tValor inválido! Digite um valor entre 0 e %d.\n", TAMANHO_VETOR - 1);
                continue; // Volta para pedir uma entrada válida
            }

            posicao_anterior = posicao_atual;
            if (posicao_atual < destino) {
                for (; posicao_atual <= destino; posicao_atual++) {
                    switch (vetor[posicao_atual]) {
                        case 0: zero++; break;
                        case 2: dois++; break;
                        case 4: quatro++; break;
                        case 6: seis++; break;
                        case 8: oito++; break;
                        case 9: nove++; break;
                    }
                }
                posicao_atual--; // Ajusta para a posição final desejada
            } else if (posicao_atual > destino) {
                for (; posicao_atual >= destino; posicao_atual--) {
                    switch (vetor[posicao_atual]) {
                        case 0: zero++; break;
                        case 2: dois++; break;
                        case 4: quatro++; break;
                        case 6: seis++; break;
                        case 8: oito++; break;
                        case 9: nove++; break;
                    }
                }
            }

            movimentos_restantes--;
        } while (movimentos_restantes > 0);

        limparTela();

        if (zero == ZERO_CORRETO && dois == DOIS_CORRETO && quatro == QUATRO_CORRETO &&
            seis == SEIS_CORRETO && oito == OITO_CORRETO && nove == NOVE_CORRETO) {
            printf("\n\tSenha Correta!\n");
            printf("\n\tO cofre foi aberto!\n\tParabéns!\n");
            exibirCofreAberto();
            printf("\n\t");
            pausar();
            break; // Sai do loop de tentativas
        } else {
            tentativas_restantes--;
            printf("\n\tSenha Incorreta!\n");
            exibirSenhaIncorreta();
            printf("\n\tTentativas Restantes: %d\n", tentativas_restantes);
            pausar();
            limparTela();
        }
    }

    if (tentativas_restantes == 0) {
        printf("\n\tAs suas tentativas acabaram...\n");
    }

    return 0;
}
