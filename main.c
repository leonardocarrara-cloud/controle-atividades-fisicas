#include <stdio.h>

#define MAX_ATIVIDADES 100
#define TAM_NOME 80

static void limpar_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(void) {
    int opcao, minutos, quantidade = 0;
    int tempos[MAX_ATIVIDADES];
    char atividades[MAX_ATIVIDADES][TAM_NOME];
    float calorias, totalCalorias = 0.0f;
    int i;

    printf("=== CONTROLE DE ATIVIDADES FISICAS ===\n");
    printf("Bem-vindo ao sistema de treinos!\n");
    printf("Registre atividades, consulte treinos e estime calorias.\n");

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Registrar atividade fisica\n");
        printf("2 - Consultar atividades\n");
        printf("3 - Calcular calorias gastas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            if (feof(stdin)) break;
            printf("Entrada invalida! Digite um numero.\n");
            limpar_entrada();
            opcao = -1;
            continue;
        }
        limpar_entrada();

        switch (opcao) {
            case 1:
                if (quantidade >= MAX_ATIVIDADES) {
                    printf("Limite de registros atingido.\n");
                    break;
                }
                printf("Nome da atividade: ");
                if (scanf("%79[^\n]", atividades[quantidade]) != 1) {
                    printf("Nome invalido.\n");
                    limpar_entrada();
                    break;
                }
                limpar_entrada();

                printf("Duracao em minutos: ");
                if (scanf("%d", &minutos) != 1) {
                    printf("Tempo invalido.\n");
                    limpar_entrada();
                    break;
                }
                limpar_entrada();

                if (minutos <= 0) {
                    printf("O tempo deve ser maior que zero.\n");
                } else {
                    tempos[quantidade] = minutos;
                    quantidade++;
                    printf("Atividade registrada com sucesso!\n");
                }
                break;

            case 2:
                printf("\n=== ATIVIDADES REGISTRADAS ===\n");
                if (quantidade == 0) {
                    printf("Nenhuma atividade registrada.\n");
                } else {
                    for (i = 0; i < quantidade; i++) {
                        printf("%d - %s: %d minutos\n", i + 1, atividades[i], tempos[i]);
                    }
                }
                break;

            case 3:
                printf("Minutos de treino para estimar calorias: ");
                if (scanf("%d", &minutos) != 1) {
                    printf("Entrada invalida.\n");
                    limpar_entrada();
                    break;
                }
                limpar_entrada();
                if (minutos <= 0) {
                    printf("Informe um tempo maior que zero.\n");
                } else {
                    calorias = minutos * 5.0f;
                    totalCalorias += calorias;
                    printf("Calorias estimadas: %.2f kcal\n", calorias);
                    printf("Estimativa didatica: 5 kcal por minuto.\n");
                }
                break;

            case 0:
                printf("\n=== RESUMO FINAL ===\n");
                printf("Atividades registradas: %d\n", quantidade);
                printf("Total de calorias calculadas: %.2f kcal\n", totalCalorias);
                printf("Obrigado por utilizar o sistema. Ate logo!\n");
                break;

            default:
                printf("Opcao invalida! Escolha 1, 2, 3 ou 0.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
