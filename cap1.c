#define Cap1
#include "stdio.h"

#ifdef ex1

/*1 - Escreva um programa que receba via teclado um tempo em segundos e converta
para horas, minutos e segundos.
Ex.: recebe 3850 segundos que converte para 1h 4min 10s.*/

void main()
{
    int h, m, s, aux;

    printf("Digite um valor em segundo, que será transformado em horas, minutos e segundos:");
    scanf("%d", &aux);

    h = aux / 3600;
    s = aux % 3600;
    m = s / 60;
    s = s - (m * 60);

    printf("Isso e igual a %dh, %dmin e %ds", h, m, s);
    return 0;
}
#endif

#ifdef ex2

/*2 - Acrescente ao exercicio anterior mais uma linha. Receba via teclado os valores
sem sinal char, int e long int e escrevendo nas coluna 10, 30 e 50.*/
void main()
{
    char c;
    short s;
    long l;
    int i;
    float f;
    double d;

    printf("Digite um valor short: ");
    scanf("%d", &s);
    printf("Digite um valor long: ");
    scanf("%ld", &l);
    printf("Digite um valor int: ");
    scanf("%d", &i);
    printf("Digite um valor float: ");
    scanf("%f", &f);
    printf("Digite um valor double: ");
    scanf("%lf", &d);
    printf("Digite um valor char: ");
    scanf("%c", &c);
    c = getchar();

    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");

    printf("%9d%19d%19d\n", s, l, i);
    printf("%19.1f%21.0lf%18c\n", f, d, c);
}
#endif

#ifdef ex3

/*3 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.*/
void main()
{
    int multiple, min, aux;

    do
    {
        printf("Informe um múltiplo inteiro. ");
        scanf("%d", &multiple);

        printf("Informe um valor minímo maior que o múltiplo.");
        scanf("%d", &min);

    } while (multiple > min);

    aux = min + multiple + 1;

    while (aux % multiple != 0)
    {
        aux--;
    }

    printf("O menor múltiplo depois do valor minímo é: %d", aux);
}
#endif

#ifdef ex4
/*4 - Escreva um programa que permute o conte�do de duas vari�veis sem utilizar uma
    vari�vel auxiliar.*/

void main()
{
    int a, b;

    printf("Informe o valor da variável A interia...\n");
    scanf("%d", &a);

    printf("Informe o valor da variável B interia...\n");
    scanf("%d", &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Agora os valores são: a -> %d e b -> %d", a, b);
}

#endif

#ifndef ex5
/* 5 - Escreva um programa que l� um valor em reais e calcula qual o menor n�mero
    poss�vel de notas de $100, $50, $20, $10, $5, $2 e $1 em que o valor lido pode
    ser decomposto. Escrever o valor lido e a rela��o de notas necess�rias.*/

void main()
{
    int valorTotal;

    printf("\nInforme um valor inteiro em Reais: ");
    scanf("%d", &valorTotal);

    int R100 = valorTotal / 100;
    valorTotal = valorTotal - R100 * 100;

    int R50 = valorTotal / 50;
    valorTotal = valorTotal - R50 * 50;

    int R20 = valorTotal / 20;
    valorTotal = valorTotal - R20 * 20;

    int R10 = valorTotal / 10;
    valorTotal = valorTotal - R10 * 10;

    int R5 = valorTotal / 5;
    valorTotal = valorTotal - R5 * 5;

    int R2 = valorTotal / 2;
    valorTotal = valorTotal - R2 * 2;

    int R1 = valorTotal;

    printf("\nO número de notas de 100 é: %d", (R100));
    printf("\nO número de notas de 50 é: %d", (R50));
    printf("\nO número de notas de 20 é: %d", (R20));
    printf("\nO número de notas de 10 é: %d", (R10));
    printf("\nO número de notas de 5 é: %d", (R5));
    printf("\nO número de notas de 2 é: %d", (R2));
    printf("\nO número de notas de 1 é: %d", (R1));
}
#endif