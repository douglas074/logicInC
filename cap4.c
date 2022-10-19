#define Cap4
#include "stdio.h"

#ifdef ex1
/*
1 - Escreva um programa que receba um vector de tamanho 10 e o decomponha em dois
    outros vectores. Um contera' as componentes de ordem impar e o outro contera'
    as componentes de ordem par.
    Por exemplo, se o vector dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7}, o programa
    deve gerar os vectores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3}.
*/

int main()
{
    int array[10];
    int impar[5];
    int par[5];
    int a, b;
    int aux;

    printf("Selecione uma funcionalidade:\n1 - Executar o programa;\n2 - Sair do programa;\n");
    scanf("%d", &aux);

    do
    {
        switch (aux)
        {

        case 1:
            printf("você irá informar dez valores\n\n");

            for (size_t i = 0; i < 10; i++)
            {
                a++;
                printf("Informe o %dº valor: ", a);
                scanf("%d", &array[i]);
            }

            a = 0;
            b = 0;

            for (size_t i = 0; i < 10; i++)
            {
                if (i % 2 == 0)
                {
                    par[b] = array[i];
                    b++;
                }
                else
                {
                    impar[a] = array[i];
                    a++;
                }
            }

            size_t n = sizeof(impar) / sizeof(impar[0]);

            printf("\nOs valores das casas impares do array são: \n");
            for (size_t i = 0; i < n; ++i)
            {
                printf("%d\n", impar[i]);
            }

            size_t m = sizeof(impar) / sizeof(impar[0]);

            printf("\nOs valores das casas pares do array são: \n");
            for (size_t i = 0; i < m; i++)
            {
                printf("%d\n", par[i]);
            }

            printf("Informe um valor respectivo para continuar ou sair:?\n1 - Continuar;\n2 - Sair;");
            scanf("%d", &aux);

            break;

        case 2:
            continue;
            break;

        default:
            printf("Comando não encontrado;");
            break;
        }

    } while (aux != 2);
    return 0;
}

#endif

#ifdef ex2

/*Receba via teclado valores do tipo int para uma vector 5 x 5. Receba via
    teclado um valor x. O programa dever fazer a busca desse valor x no vector
    e, ao final escrever a localizacao (linha e coluna) ou uma mensagem de
    �nao encontrado�.
*/
// Online C compiler to run C program online

int matriz[5][5];
int iLocal[20];
int jLocal[20];

int search();
int main()
{
    int aux;
    int num;
    int a, b;
    printf("Selecione uma funcionalidade:\n0 - Executar o programa;\n1 - Sair do programa;\n");
    scanf("%d", &aux);

    do
    {
        switch (aux)
        {
        case 0:

            printf("Você informará valores que serão armazenados em uma matriz 5 x 5\n");
            a = 0;
            for (size_t i = 0; i < 5; i++)
            {
                a++;
                b = 0;
                printf("Valores da %dº linha:\n", a);
                for (size_t j = 0; j < 5; j++)
                {
                    b++;
                    printf("%dº valor -> ", b);
                    scanf("%d", &matriz[i][j]);
                }
            }

            printf("Digite o valor que será procurado na matriz: \n");
            scanf("%d", &num);

            search(num);
            printf("\nDeseja pesquisar outro?\n Se sim, digite 1;\n Se não digite 2;\n");
            scanf("%d", &aux);

            do
            {
                switch (aux)
                {
                case 1:
                    printf("Digite o valor que será procurado na matriz: ");
                    scanf("%d", &num);
                    search(num);
                    break;
                case 2:
                    continue;
                    break;
                default:
                    printf("Opção não encontrada, tente novamente");
                    scanf("%d", &aux);
                }
            } while (aux != 2);

            printf("Informe um valor respectivo para continuar ou sair:?\n0 - Informar novos valores;\n1 - Sair;\n");
            scanf("%d", &aux);

            break;
        case 2:
            continue;
            break;

        default:
            printf("Opção não encontrada, tente novamente");
            scanf("%d", &aux);
            break;
        }
    } while (aux != 1);
    return 0;
}

int search(int num)
{
    int aux;
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (num == matriz[i][j])
            {
                printf("%d foi encontrado na posição:\n %ldx%ld\n", num, i, j);
                aux = 1;
            }
        }
    }
    if (aux != 1)
    {
        printf("Valor não encontrado, ddeseja tentar novamente?");
        return 1;
    }
    return 0;
}
#endif

#ifdef ex3
/*3 - Defina 2 vectores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vectores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vectores e guarde o
    resultado em um 3. vector. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vectores.*/

int first[2][3], second[2][3];

int adder();
int main()
{
    int aux;

    printf("Você informará valores para dois vectores de 2x3, digite se deseja :\n1 - Continuar;\n2 - Sair do programa;\n");
    scanf("%d", &aux);

    do
    {
        switch (aux)
        {
        case 1:
            printf("Informe os valores do primeiro vector;\n");

            for (size_t i = 0; i < 2; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    printf("Posição %ldx%ld ->", i, j);
                    scanf("%d", &first[i][j]);
                }
            }

            printf("Informe os valores do segundo vector;\n");

            for (size_t i = 0; i < 2; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    printf("Posição %ldx%ld ->", i, j);
                    scanf("%d", &second[i][j]);
                }
            }

            adder();

            printf("O que deseja fazer?\n 1 - Informar novos valores?\n 2 - Sair\n");
            scanf("%d", &aux);
            break;

        case 2:
            continue;
            break;

        default:
            printf("Opção não encontrada, por favor tente novamente:");
            scanf("%d", &aux);

            break;
        }

    } while (aux != 2);
}

int adder()
{
    int third[2][3];

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            third[i][j] = first[i][j] + second[i][j];
        }
    }

    printf("Será impresso os valores dos indices, valores e o resultado da soma:\n\n");

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("indices -> %ldx%ld;\nValores -> %d e %d;\nResultado -> %d\n\n", i, j, first[i][j], second[i][j], third[i][j]);
        }
    }
}
#endif

#ifdef ex4
/*4 - Escreva um programa para receber via teclado em vectores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double*/

int main()
{
    int vectorInt[3], aux;
    long vectorLong[3];
    unsigned vectorUnsigned[3];
    float vectorFloat[3];
    double vectorDouble[3];

    printf("O que deseja fazer?\n1 - Continuar no programa;\n2 - Sair;\n");
    scanf("%d", &aux);

    do
    {
        printf("Você informará 3 valores inteiros:\n");

        for (size_t i = 0; i < 3; i++)
        {
            printf("%ldº valor: ", i);
            scanf("%d", &vectorInt[i]);
        }

        printf("\nVocê informará 3 valores long:\n");

        for (size_t i = 0; i < 3; i++)
        {
            printf("%ldº valor: ", i);
            scanf("%ld", &vectorLong[i]);
        }
        printf("\nVocê informará 3 valores unsigned:\n");

        for (size_t i = 0; i < 3; i++)
        {
            printf("%ldº valor: ", i);
            scanf("%u", &vectorUnsigned[i]);
        }

        printf("\nVocê informará 3 valores float:\n");

        for (size_t i = 0; i < 3; i++)
        {
            printf("%ldº valor: ", i);
            scanf("%f", &vectorFloat[i]);
        }

        printf("\nVocê informará 3 valores double:\n");

        for (size_t i = 0; i < 3; i++)
        {
            printf("%ldº valor: ", i);
            scanf("%lf", &vectorDouble[i]);
        }

        printf("\n        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890\n");
        for (size_t i = 0; i < 3; i++)
        {
            printf("%9d%19ld%19u\n", vectorInt[i], vectorLong[i], vectorUnsigned[i]);
            printf("%19.1f%21.0lf\n", vectorFloat[i], vectorDouble[i]);
        }

        printf("\n\nO que deseja fazer?\n1 - Continuar no programa;\n2 - Sair;");
        scanf("%d", &aux);

    } while (aux != 2);

    return 1;
}

#endif

#ifdef ex5

/*Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vector. Mostre ao final os valores ordenados.*/

int main()
{
    int aux, vector[10];

    printf("Você iniciou um programa que pedirá 10 inteiros e os organizará em forma crescente;");

    do
    {
        printf("\nO que deseja fazer?\n1 - Usar o programa;\n2 - Sair;\n");
        scanf("%d", &aux);
        switch (aux)
        {
        case 1:

            printf("Voce informará 10 valores inteiros;\n\n");

            for (size_t i = 0; i < 10; i++)
            {
                printf("Informe o %ldº valor: ", i);
                scanf("%d", &vector[i]);
            }

            for (int i = 0; i <= 10; i++)
            {
                for (int j = i; j < 10; j++)
                {
                    if (vector[i] > vector[j])
                    {
                        int temp = vector[i];
                        vector[i] = vector[j];
                        vector[j] = temp;
                    }
                }
            }
            for (size_t i = 0; i < 10; i++)
            {
                printf("\n%ld %d", i, vector[i]);
            }

            break;

        case 2:
            continue;
            break;
        default:
            printf("\nOpção não encontrada, por favor tente novamente;\n");
            scanf("%d", &aux);
            break;
        }

        printf("\nVocê deseja continuar no programa?\n1 - Sim;\n2 - Não;");
        scanf("%d", &aux);

    } while (aux != 2);
}
#endif