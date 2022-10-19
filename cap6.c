#define Cap4
#include "stdio.h"

#ifdef ex1

/*1 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.*/

int main()
{
    int num[2], aux;

    printf("Você informará dois valores que sofrerão as 4 operações mamtemáticas;\n\n");

    do
    {
        printf("O que deseja fazer?\n1 - Continuar no programa;\n2 - Sair;\n");
        scanf("%d", &aux);

        switch (aux)
        {
        case 1:
            printf("Você informará 2 valores;\n");

            for (size_t i = 0; i < 2; i++)
            {
                size_t j = i + 1;
                printf("Informe o %ldº valor:\n", j);
                scanf("%d", &num[i]);
            }

            printf("\n%d + %d  é: %d;\n", num[0], num[1], num[0] + num[1]);
            printf("\n%d - %d  é: %d;\n", num[0], num[1], num[0] - num[1]);
            printf("\n%d x %d  é: %d;\n", num[0], num[1], num[0] * num[1]);
            printf("\n%d / %d  é: %.2f;\n\n", num[0], num[1], (float)num[0] / num[1]);

            break;

        case 2:
            continue;
            break;

        default:
            printf("\nOção não encontrada, por favor tente novamente;\n");
            scanf("%d", &aux);
            break;
        }
    } while (aux != 2);
    return 1;
}
#endif

#ifdef ex2

/*2 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.
*/

int main()
{
    float num[2], aux;
    int value;

    printf("Você informará dois valores que sofrerão as 4 operações mamtemáticas;\n\n");

    do
    {
        printf("O que deseja fazer?\n1 - Continuar no programa;\n2 - Sair;\n");
        scanf("%d", &value);

        switch (value)
        {
        case 1:
            printf("Você informará 2 valores;\n");

            for (size_t i = 0; i < 2; i++)
            {
                size_t j = i + 1;
                printf("Informe o %ldº valor:\n", j);
                scanf("%f", &num[i]);
            }
            aux = num[0];
            printf("\n%.2f + %.2f  é: %.2f;\n", aux, num[1], num[0] += num[1]);

            num[0] = aux;
            printf("\n%.2f - %.2f  é: %.2f;\n", aux, num[1], num[0] -= num[1]);

            num[0] = aux;
            printf("\n%.2f x %.2f  é: %.2f;\n", aux, num[1], num[0] *= num[1]);

            num[0] = aux;
            printf("\n%.2f / %.2f  é: %.2f;\n\n", aux, num[1], num[0] /= num[1]);

            break;

        case 2:
            continue;
            break;

        default:
            printf("\nOção não encontrada, por favor tente novamente;\n");
            scanf("%d", &value);
            break;
        }
    } while (value != 2);
    return 1;
}

#endif

#ifdef ex3
/*3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.*/

int day[2], month[2], year[2];

int insertDate();
int leapYear(int year);
int dateValidate(int d, int m, int y);

int main()
{
    int aux;
    float birthDate;

    printf("Você irá informar duas datas para calcular a idade de uma pessoa;\n");

    do
    {
        printf("\nO que deseja fazer?\n1 - Continuar no programa;\n2 - Sair;\n");
        scanf("%d", &aux);

        switch (aux)
        {
        case 1:
            insertDate();

            int ageTotal = 365 * year[1] + 30 * month[1] + day[1] - 365 * year[0] - 30 * month[0] - day[0];

            birthDate = ageTotal / 365;

            printf("A idade é: %.0f", birthDate);

            break;
        case 2:
            continue;
            break;
        default:
            printf("\nOpção não encontrada, por favor, tente navamente... ");
            scanf("%d", &aux);
            break;
        }
    } while (aux != 2);
}

int insertDate()
{
    for (int i = 0; i < 2; i++)
    {
        switch (i)
        {
        case 0:
            printf("\nInforme a data de nascimento;\n");
            break;

        case 1:
            printf("\nInforme segunda data;\n");
            break;

        default:
            break;
        }

        printf("Dia: ");
        scanf("%d", &day[i]);

        printf("\nMês: ");
        scanf("%d", &month[i]);

        printf("\nAno: ");
        scanf("%d", &year[i]);

        do
        {
            switch (dateValidate(day[i], month[i], year[i]))
            {
            case 0:
                continue;
                break;
            case 1:
                printf("O mês deve estar entre 1 e 12 e os dias entre 1 e 31, por favor insira valores adequados:\n");
                printf("Dia: ");
                scanf("%d", &day[i]);

                printf("\nMês: ");
                scanf("%d", &month[i]);
                break;

            case 2:
                printf("Mês digitado não possui 31 dias, por favor insira um valore adequado ou mude o mês:\n");
                printf("Dia: ");
                scanf("%d", &day[i]);

                printf("\nMês: ");
                scanf("%d", &month[i]);
                break;

            case 3:
                printf("O mês de fevereiro possui no máximo 29 dias, por favor insira um valor adequado ou mude o mês:\n");
                printf("Dia: ");
                scanf("%d", &day[i]);

                printf("\nMês: ");
                scanf("%d", &month[i]);
                break;

            case 4:
                printf("O ano indicado não é bixesto, logo fevereiro não tem 29 dias, por favor insira um valor adequado ou mude a data:\n");
                printf("Dia: ");
                scanf("%d", &day[i]);

                printf("\nMês: ");
                scanf("%d", &month[i]);

                printf("\nAno: ");
                scanf("%d", &year[i]);

                break;

            case 5:
                printf("Acredito que não haja um ano negativo, por favor insira um valor adequado:\n");

                printf("\nAno: ");
                scanf("%d", &year[i]);

                break;

            case 6:
                printf("O ano atual não pode ser menor que o de nascimento, por favor, informe um novo valor:\n");

                printf("\nAno: ");
                scanf("%d", &year[i]);

                break;

            default:
                printf("Erro não encontrado, por favor tente novamente:\n");
                break;
            }

        } while (dateValidate(day[i], month[i], year[i]) != 0);
    }
    return 1;
}

int leapYear(int year)
{
    if (year % 4 == 0)
    {
        return 1;
    }

    return 0;
}

int dateValidate(int d, int m, int y)
{
    if (d < 1 || d > 31 || m < 1 || m > 12)
    {
        return 1;
    }
    if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11))
    {
        return 2;
    }
    if (m == 2 && d > 29)
    {
        return 3;
    }
    if (m == 2 && d == 29 && leapYear(y) == 0)
    {
        return 4;
    }
    if (y < 0)
    {
        return 5;
    }
    if (year[0] > y)
    {
        return 6;
    }

    return 0;
}
#endif

#ifdef ex4

/*4 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.
*/
int main()
{
    int num1, num2;
    printf("Digite o 1º numero: ");
    scanf("%d", &num1);
    printf("\nDigite o 2º numero: ");
    scanf("%d", &num2);
    printf("\nAnd\nDecimal: %d\nHexadecimal: %x", num1 & num2, num1 & num2);
    printf("\n\nOu\nDecimal: %d\nHexadecimal: %x", num1 | num2, num1 | num2);
    printf("\n\nOu Exclusivo\nDecimal: %d\nHexadecimal: %x", num1 ^ num2, num1 ^ num2);
    return 1;
}

#endif

#ifdef ex5

/*5 - Escreva um programa que tem o menu abaixo na funcao main(). Receba via teclado
    a opcao do menu.
    Em cada opcao do menu receba o valor da temperatura e chama as funcoes de conversao
    e mostra resultado.
       1 - transforma graus Celsius em Fahrenheit e Kelvin
       2 - transforma graus Fahrenheit em Celsius e Kelvin
       3 - transforma graus Kelvin em Celsius e Fahrenheit
*/

void Celsius_Fahrenheits()
{
    float tc, tf;

    printf("\nDigite a temperatura em Celsius: ");
    scanf("%f", &tc);
    if (tc >= -273.15)
    {
        tf = ((9 * tc + 160) / 5);
        printf("\nA temperatura em Fahrenheits = %.2f\n", tf);
    }
}

void Celsius_Kelvin()
{
    float tc, tk;

    printf("\nDigite a temperatura em Celsius: ");
    scanf("%f", &tc);
    if (tc >= -273.15)
    {
        tk = (tc + 273);
        printf("\nA temperatura em Kelvin = %.2f\n", tk);
    }
}

void Fahrenheits_Celsius()
{
    float tc, tf;

    printf("\nDigite a temperatura em Fahrenheits: ");
    scanf("%f", &tf);
    if (tf >= -459.67)
    {
        tc = ((5 * (tf - 32)) / 9);
        printf("\nA temperatura em Celsius = %.2f\n", tc);
    }
}

void Fahrenheits_Kelvin()
{
    float tf, tk;

    printf("\nDigite a temperatura em Fahrenheits: ");
    scanf("%f", &tf);
    if (tf >= -459.67)
    {
        tk = ((5 * tf + 2297) / 9);
        printf("\nA temperatura em Kelvin = %.2f\n", tk);
    }
}

void Kelvin_Celsius()
{
    float tc, tk;

    printf("\nDigite a temperatura em Kelvin: ");
    scanf("%f", &tk);
    if (tk >= -273.15)
    {
        tc = (tk - 273);
        printf("\nA temperatura em Celsius = %.2f\n", tc);
    }
}

void Kelvin_Fahrenheits()
{
    float tf, tk;

    printf("\nDigite a temperatura em Kelvin: ");
    scanf("%f", &tk);
    if (tk >= -273.15)
    {
        tf = ((9 * tk - 2297) / 5);
        printf("\nA temperatura em Fahrenheits = %.2f\n", tf);
    }
}

main()
{
    int aux, choose;

    do
    {
        printf("\nConversor de temperaturas\n");
        printf("\n1-Celsius -> Fahrenheits\n2-Celsius -> Kelvin\n3-Fahrenheits -> Celsius\n4-Fahrenheits -> Kelvin\n5-Kelvin -> Celsius\n6-Kelvin -> Fahrenheits\n7-Sair\n");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            Celsius_Fahrenheits();
            break;

        case 2:
            Celsius_Kelvin();
            break;

        case 3:
            Fahrenheits_Celsius();
            break;

        case 4:
            Fahrenheits_Kelvin();
            break;

        case 5:
            Kelvin_Celsius();
            break;

        case 6:
            Kelvin_Fahrenheits();
            break;

        case 7:
            printf("\nFinalizando o programa...\n");
            break;

        default:
            printf("\nErro! Opcao inexistente.\n");
            break;
        }
        printf("\nO que deseja fazer?\n1 - Nova conversão;\n2 - Sair;\n");
        scanf("%d", &aux);
    } while (aux != 2);
}
#endif