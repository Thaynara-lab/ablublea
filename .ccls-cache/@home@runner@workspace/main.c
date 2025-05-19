#include <stdio.h>
#include <stdlib.h>

int mod(int a, int n) {
    int q = a / n;
    return a - q * n;
}

void calcularMMC_MDC() {
    int numero1 = 0;
    int numero2 = 0;

    printf("Escreva o numero1: ");
    scanf("%i", &numero1);
    getchar();

    printf("Escreva o numero2: ");
    scanf("%i", &numero2);
    getchar();

    if (numero1 == 0 || numero2 == 0) {
        printf("Não existe MMC entre zero e outro número.\n");
        return;
    }

    int a = numero1;
    int b = numero2;

    int Q, Resto;

    while (numero2 != 0) {
        Q = numero1 / numero2;
        Resto = numero1 - numero2 * Q;

        if (Resto < 0) {
            Resto += abs(numero2);
            Q -= (numero1 * numero2 < 0);
        }

        if (Resto != 0) {
            printf("%i = %i * %i + %i   // diferente de 0\n", numero1, numero2, Q, Resto);
        } else {
            printf("%i = %i * %i + %i   // = 0\n", numero1, numero2, Q, Resto);
        }

        numero1 = numero2;
        numero2 = Resto;
    }

    int mdc = numero1;
    int mmc = abs(a * b) / mdc;

    printf("O MMC entre esses dois numeros e: %i\n", mmc);
    printf("O MDC entre esses dois numeros e: %i\n", mdc);
}

void gerarTabelasZn() {
    int n;

    printf("\nDigite o valor de n para as tabelas Zn: ");
    scanf("%i", &n);

    if (n <= 0) {
        printf("Por favor, digite um numero positivo.\n");
        return;
    }

    // Tabela de Adição
    printf("\nTabela de Adicao Modular Z%d\n", n);
    printf("   |");
    for (int i = 0; i < n; i++) {
        printf("%3i", i);
    }
    printf("\n---+");
    for (int i = 0; i < n; i++) {
        printf("---");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%2d |", i);
        for (int j = 0; j < n; j++) {
            int sum = i + j;
            printf("%3i", mod(sum, n));
        }
        printf("\n");
    }

    // Tabela de Multiplicação
    printf("\nTabela de Multiplicacao Modular Z_%d\n", n);
    printf("   |");
    for (int i = 0; i < n; i++) {
        printf("%3i", i);
    }
    printf("\n---+");
    for (int i = 0; i < n; i++) {
        printf("---");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%2i |", i);
        for (int j = 0; j < n; j++) {
            int product = i * j;
            printf("%3i", mod(product, n));
        }
        printf("\n");
    }
}

int main() {
    calcularMMC_MDC();
    gerarTabelasZn();
    return 0;
}