#include "stdio.h"
#include <stdlib.h>
#include <locale.h>

/*
    Observação, para o desenvolvimento desse sistema utilizei o compilador online Replit, econtrado no site:
        https://replit.com/

        Para melhor performace recomendo executar o código no compilador indicado.
*/

char filme0[20], filme1[20], filme2[20], produtora0[20], produtora1[20], produtora2[20];

int insertData();
int listData();
int searchMovie();
int searchProducer();
int changeData();
int deleteData();

void concatenar();
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int aux;

    do
    {
        system("clear");

        printf("\nSelecione uma função\n1 – entrada de dados.\n\n2 – lista todos os dados na tela.\n\n3 – pesquisa um filme com o nome completo e mostra na tela.\n\n4 – pesquisa produtora pela 1. letra e mostra todas na tela.\n\n5 – altera dados. Pesquisa pelo filme completo.\n\n6 – exclui dados. Pesquisa pelo filme completo.\n\n7 - saída\n");
        scanf("%d", &aux);

        switch (aux)
        {
        case 1:
            aux = insertData();
            break;

        case 2:
            aux = listData();
            break;

        case 3:
            aux = searchMovie();
            break;

        case 4:
            aux = searchProducer();
            break;

        case 5:
            aux = changeData();
            break;

        case 6:
            aux = deleteData();
            break;

        case 7:
            exit(1);
            break;

        default:
            printf("Opção não encontrada, por favor tente novamente:  ");
            scanf("%d", &aux);
            break;
        }
    } while (aux != 2 || aux != 7);
    exit(1);
}

int insertData()
{
    int aux;
    FILE *fileMovie;

    fileMovie = fopen("fileMovie.txt", "w+");

    if (fileMovie == NULL)
    {
        printf("Não foi possível abir o arquivo...");
        exit(1);
    }

    printf("Informe os dados;\n\n");

    printf("Primeiro filme: ");
    getchar();
    gets(&filme0);
    fwrite(filme0, sizeof(filme0), 1, fileMovie);

    printf("Produtora do primeiro filme: ");
    gets(&produtora0);
    fwrite(produtora0, sizeof(produtora0), 1, fileMovie);

    printf("segundo filme: ");
    gets(&filme1);
    fwrite(filme1, sizeof(filme1), 1, fileMovie);

    printf("Produtora do segundo filme: ");
    gets(&produtora1);
    fwrite(produtora1, sizeof(produtora1), 1, fileMovie);

    printf("Terceiro filme: ");
    gets(&filme2);
    fwrite(filme2, sizeof(filme2), 1, fileMovie);

    printf("Produtora do terceiro filme: ");
    gets(&produtora2);
    fwrite(produtora2, sizeof(produtora2), 1, fileMovie);

    printf("Dados inseridos;\n");

    fclose(fileMovie);

    return 1;
}

int listData()
{
    system("clear");

    int aux, count = 0;
    FILE *fileMovie;

    fileMovie = fopen("fileMovie.txt", "r");

    if (fileMovie == NULL)
    {
        printf("Não foi possível abir o arquivo...");
        exit(1);
    }
    printf("\nFilmes e produtoras:\n\n");

    while (fread(&filme0, sizeof(filme0), 1, fileMovie) != NULL)
    {
        if (filme0[0] != '$')
        {
            switch (count)
            {
            case 0:
                printf("filme -> %s", filme0);
                count = 1;
                break;

            case 1:
                printf(" | Produtora -> %s\n", filme0);
                count = 0;
                break;

            default:
                break;
            }
        }
    }

    printf("\nDeseja voltar para o menu?\n1 - Sim;\n2 - Sair;\n");
    scanf("%d", &aux);
    if (aux == 2)
    {
        exit(0);
    }

    fclose(fileMovie);

    return aux;
}

int searchMovie()
{
    system("clear");

    int aux, i, count = 0;
    char textAux[20];
    FILE *fileMovie;

    fileMovie = fopen("fileMovie.txt", "r");

    if (fileMovie == NULL)
    {
        printf("Não foi possível abir o arquivo...");
        exit(1);
    }

    do
    {
        do
        {
            count = 0;

            printf("\nInforme o nome do filme que será pesquisado: \n");
            getchar();
            gets(&textAux);

            fclose(fileMovie);
            fileMovie = fopen("fileMovie.txt", "r");

            while (fread(&filme0, sizeof(filme0), 1, fileMovie) && fread(&produtora0, sizeof(produtora0), 1, fileMovie))
            {

                for (i = 0; textAux[i] != '\0'; i++)
                {
                    if (textAux[i] != filme0[i])
                    {
                        break;
                    }
                }
                if (textAux[i] == '\0' && filme0[i] == '\0')
                {
                    printf("Filme -> %s ", filme0);
                    printf("| Produtora -> %s ", produtora0);

                    count = 1;
                    aux = 2;
                }
            }

            if (count != 1)
            {
                printf("\nFilme não encontrado, o que deseja fazer?\n1 - Tentar novamente;\n2 - Sair;\n");
                scanf("%d", &aux);
                system("clear");
            }
        } while (aux != 2);

        if (count == 1)
        {
            printf("\n\nO que deseja fazer?\n1 - Pesquisar novo filme\n2 - Sair\n");
            scanf("%d", &aux);
            system("clear");
        }

        system("clear");

    } while (aux != 2);

    fclose(fileMovie);

    return aux;
}

int searchProducer()
{
    system("clear");

    int aux, i, count = 0;
    char textAux;
    FILE *fileMovie;

    fileMovie = fopen("fileMovie.txt", "r");

    if (fileMovie == NULL)
    {
        printf("Não foi possível abir o arquivo...");
        exit(1);
    }

    do
    {
        do
        {
            count = 0;
            printf("Digite a primeira da produtora que será procurada: \n");
            getchar();
            textAux = getchar();

            fclose(fileMovie);
            fileMovie = fopen("fileMovie.txt", "r");

            while (fread(&filme0, sizeof(filme0), 1, fileMovie) && fread(&produtora0, sizeof(produtora0), 1, fileMovie))
            {
                if (textAux == produtora0[0])
                {
                    printf("\nFilme -> %s ", filme0);
                    printf("| Produtora -> %s ", produtora0);
                    count = 1;
                    aux = 2;
                }
            }

            if (count != 1)
            {
                printf("Produtora não encontrada, o que deseja fazer?\n1 - Tentar novamente;\n2 - Sair;\n");
                scanf("%d", &aux);
                system("clear");
            }
        } while (aux != 2);

        if (count == 1)
        {
            printf("\n\nO que deseja fazer?\n1 - Pesquisar nova produtora\n2 - Sair\n");
            scanf("%d", &aux);
            system("clear");
        }

    } while (aux != 2);
    fclose(fileMovie);
    return aux;
}

int changeData()
{
    system("clear");

    int aux = 0, i, count = 0, aux2 = 0, aux3 = 2;
    char textAux[20], choose[20], newTitle[20];
    FILE *fileMovie;

    fileMovie = fopen("fileMovie.txt", "r");

    if (fileMovie == NULL)
    {
        printf("Não foi possível abir o arquivo...");
        exit(1);
    }

    while (aux != 2)
    {
        fileMovie = fopen("fileMovie.txt", "r");

        printf("Filmes e produtoras presentes no arquivo:\n\n");

        while (fread(&filme0, sizeof(filme0), 1, fileMovie) != NULL)
        {
            switch (count)
            {
            case 0:
                printf("filme -> %s", filme0);
                count = 1;
                break;

            case 1:
                printf(" | Produtora -> %s\n", filme0);
                count = 0;
                break;

            default:
                break;
            }
        }
        fclose(fileMovie);

        printf("\nDeseja editar algo?\n1 - Sim;\n2 - Não;\n");
        scanf("%d", &aux);
        fileMovie = fopen("fileMovie.txt", "r");
        aux2 = 0;

        if (aux == 1)
        {
            printf("\nInforme o filme que irá ser editado:\n");
            getchar();
            gets(&choose);
            while (fread(&filme0, sizeof(filme0), 1, fileMovie) != NULL)
            {
                aux2++;
                for (i = 0; choose[i] != '\0'; i++)
                {
                    if (choose[i] != filme0[i])
                    {
                        break;
                    }
                }

                if (choose[i] == '\0' && filme0[i] == '\0')
                {
                    fclose(fileMovie);
                    fileMovie = fopen("fileMovie.txt", "r+");

                    fread(&filme0, sizeof(filme0), 1, fileMovie);
                    fread(&produtora0, sizeof(produtora0), 1, fileMovie);
                    fread(&filme1, sizeof(filme1), 1, fileMovie);
                    fread(&produtora1, sizeof(produtora1), 1, fileMovie);
                    fread(&filme2, sizeof(filme2), 1, fileMovie);
                    fread(&produtora2, sizeof(produtora2), 1, fileMovie);

                    switch (aux2)
                    {
                    case 1:
                        printf("\nFilme encontrado na posição 1º;\n");
                        printf("Informe o novo nome do filme:\n");
                        gets(&filme0);

                        printf("Informe o novo nome da produtora:\n");
                        gets(&produtora0);

                        aux2 = NULL;
                        aux3 = 1;

                        break;

                    case 2:
                        printf("\nFilme encontrado na posição 1º;\n");
                        printf("Informe o novo nome do filme:\n");
                        gets(&filme0);

                        printf("Informe o novo nome da produtora:\n");
                        gets(&produtora0);

                        aux2 = NULL;
                        aux3 = 1;

                        break;

                    case 3:
                        printf("\nFilme encontrado na posição 2º;\n");
                        printf("Informe o novo nome do filme:\n");
                        gets(&filme1);

                        printf("Informe o novo nome da produtora:\n");
                        gets(&produtora1);

                        aux2 = NULL;
                        aux3 = 1;

                        break;
                    case 4:
                        printf("\nFilme encontrado na posição 2º;\n");
                        printf("Informe o novo nome do filme:\n");
                        gets(&filme1);

                        printf("Informe o novo nome da produtora:\n");
                        gets(&produtora1);

                        aux2 = NULL;
                        aux3 = 1;

                        break;
                    case 5:
                        printf("\nFilme encontrado na posição 3º;\n");
                        printf("Informe o novo nome do filme:\n");
                        gets(&filme2);

                        printf("Informe o novo nome da produtora:\n");
                        gets(&produtora2);

                        aux2 = NULL;
                        aux3 = 1;

                        break;

                    case 6:
                        printf("\nFilme encontrado na posição 3º;\n");
                        printf("Informe o novo nome do filme:\n");
                        gets(&filme2);

                        printf("Informe o novo nome da produtora:\n");
                        gets(&produtora2);

                        aux2 = NULL;
                        aux3 = 1;

                        break;

                    default:
                        printf("aaaaaa");
                        break;
                    }
                    fclose(fileMovie);
                    fileMovie = fopen("fileMovie.txt", "w+");

                    fwrite(filme0, sizeof(filme0), 1, fileMovie);
                    fwrite(produtora0, sizeof(produtora0), 1, fileMovie);
                    fwrite(filme1, sizeof(filme1), 1, fileMovie);
                    fwrite(produtora1, sizeof(produtora1), 1, fileMovie);
                    fwrite(filme2, sizeof(filme2), 1, fileMovie);
                    fwrite(produtora2, sizeof(produtora2), 1, fileMovie);

                    fclose(fileMovie);
                    fileMovie = fopen("fileMovie.txt", "r");

                    printf("Deseja alterar outro filme?\n1 - Sim;\n2 - Não;\n");
                    scanf("%d", &aux);
                    system("clear");
                }
            }
            if (aux3 != 1)
            {
                fclose(fileMovie);

                printf("Filme não encontrado, o que deseja fazer?\n1 - Tentar novamente;\n2 - Sair;\n");
                scanf("%d", &aux);
                system("clear");
            }
        }
    }
    if (count == 1)
    {
        printf("\n\nO que deseja fazer?\n1 - Pesquisar nova produtora\n2 - Sair\n");
        scanf("%d", &aux);
        system("clear");
    }

    return aux;
}

int deleteData()
{
    system("clear");

    int aux, i, count = 0, aux2 = 0, aux3 = 2;
    char textAux[20], choose[20], newTitle[20];
    FILE *fileMovie;

    fileMovie = fopen("fileMovie.txt", "r+");

    if (fileMovie == NULL)
    {
        printf("Não foi possível abir o arquivo...");
        exit(1);
    }
    aux = 1;
    while (aux != 2)
    {
        fileMovie = fopen("fileMovie.txt", "r+");

        printf("Filmes e produtoras presentes no arquivo:\n\n");

        while (fread(&filme0, sizeof(filme0), 1, fileMovie) != NULL)
        {
            if (filme0[0] != '$')
            {
                switch (count)
                {
                case 0:
                    printf("filme -> %s", filme0);
                    count = 1;
                    break;

                case 1:
                    printf(" | Produtora -> %s\n", filme0);
                    count = 0;
                    break;

                default:
                    break;
                }
            }
        }

        fclose(fileMovie);

        printf("\nDeseja excluir algo?\n1 - Sim;\n2 - Não;\n");
        scanf("%d", &aux);

        if (aux == 1)
        {
            printf("\nDigite o nome de qual fime será excluido:\n");
            getchar();
            gets(&choose);

            aux3 = 2;
            fileMovie = fopen("fileMovie.txt", "r");

            while (fread(&filme0, sizeof(filme0), 1, fileMovie) != NULL)
            {
                aux2++;
                for (i = 0; choose[i] != '\0'; i++)
                {
                    if (choose[i] != filme0[i])
                    {
                        break;
                    }
                }

                if (choose[i] == '\0' && filme0[i] == '\0')
                {
                    fclose(fileMovie);
                    fileMovie = fopen("fileMovie.txt", "r+");

                    fread(&filme0, sizeof(filme0), 1, fileMovie);
                    fread(&produtora0, sizeof(produtora0), 1, fileMovie);
                    fread(&filme1, sizeof(filme1), 1, fileMovie);
                    fread(&produtora1, sizeof(produtora1), 1, fileMovie);
                    fread(&filme2, sizeof(filme2), 1, fileMovie);
                    fread(&produtora2, sizeof(produtora2), 1, fileMovie);

                    switch (aux2)
                    {
                    case 1:
                        printf("\nFilme encontrado na posição 1º;\n");
                        printf("Deseja realmente exclui-lo?\n1 - Sim;\n2 - Não;\n");
                        scanf("%d", &aux2);
                        switch (aux2)
                        {
                        case 1:
                            filme0[0] = '$';
                            produtora0[0] = '$';

                            printf("\nFilme excluido com sucesso\n");
                            break;

                        case 2:
                            printf("Operação cancelada...\n");
                            break;

                        default:
                            break;
                        }
                        aux2 = NULL;
                        aux3 = 1;

                        break;

                    case 2:
                        printf("\nFilme encontrado na posição 1º;\n");
                        printf("Deseja realmente exclui-lo?\n1 - Sim;\n2 - Não;\n");
                        scanf("%d", &aux2);
                        switch (aux2)
                        {
                        case 1:
                            filme0[0] = '$';
                            produtora0[0] = '$';

                            printf("\nFilme excluido com sucesso\n");
                            break;

                        case 2:
                            printf("Operação cancelada...\n");
                            break;

                        default:
                            break;
                        }

                        aux2 = NULL;
                        aux3 = 1;

                        break;

                        break;

                    case 3:
                        printf("\nFilme encontrado na posição 2º;\n");
                        printf("Deseja realmente exclui-lo?\n1 - Sim;\n2 - Não;\n");
                        scanf("%d", &aux2);
                        switch (aux2)
                        {
                        case 1:
                            filme1[0] = '$';
                            produtora1[0] = '$';

                            printf("\nFilme excluido com sucesso\n");
                            break;

                        case 2:
                            printf("Operação cancelada...\n");
                            break;

                        default:
                            break;
                        }

                        aux2 = NULL;
                        aux3 = 1;

                        break;
                    case 4:
                        printf("\nFilme encontrado na posição 2º;\n");
                        printf("Deseja realmente exclui-lo?\n1 - Sim;\n2 - Não;\n");
                        scanf("%d", &aux2);
                        switch (aux2)
                        {
                        case 1:
                            filme1[0] = '$';
                            produtora1[0] = '$';

                            printf("\nFilme excluido com sucesso\n");
                            break;

                        case 2:
                            printf("Operação cancelada...\n");
                            break;

                        default:
                            break;
                        }
                        aux2 = NULL;
                        aux3 = 1;

                        break;
                    case 5:
                        printf("\nFilme encontrado na posição 3º;\n");
                        printf("Deseja realmente exclui-lo?\n1 - Sim;\n2 - Não;\n");
                        scanf("%d", &aux2);
                        switch (aux2)
                        {
                        case 1:
                            filme2[0] = '$';
                            produtora2[0] = '$';

                            printf("\nFilme excluido com sucesso\n");
                            break;

                        case 2:
                            printf("Operação cancelada...\n");
                            break;

                        default:
                            break;
                        }
                        aux2 = NULL;
                        aux3 = 1;

                        break;

                    case 6:
                        printf("\nFilme encontrado na posição 3º;\n");
                        printf("Deseja realmente exclui-lo?\n1 - Sim;\n2 - Não;\n");
                        scanf("%d", &aux2);
                        switch (aux2)
                        {
                        case 1:
                            filme2[0] = '$';
                            produtora2[0] = '$';

                            printf("\nFilme excluido com sucesso\n");
                            break;

                        case 2:
                            printf("Operação cancelada...\n");
                            break;

                        default:
                            break;
                        }
                        aux2 = NULL;
                        aux3 = 1;

                        break;

                    default:
                        printf("Opção não encontrada, por favor reinicie o sistema;");
                        exit(1);
                        break;
                    }
                    fclose(fileMovie);
                    fileMovie = fopen("fileMovie.txt", "w+");

                    fwrite(filme0, sizeof(filme0), 1, fileMovie);
                    fwrite(produtora0, sizeof(produtora0), 1, fileMovie);
                    fwrite(filme1, sizeof(filme1), 1, fileMovie);
                    fwrite(produtora1, sizeof(produtora1), 1, fileMovie);
                    fwrite(filme2, sizeof(filme2), 1, fileMovie);
                    fwrite(produtora2, sizeof(produtora2), 1, fileMovie);
                }
            }
            switch (aux3)
            {
            case 1:
                printf("\nDeseja excluir algo mais?\n1 - Sim;\n2 - Não;\n");
                scanf("%d", &aux);
                system("clear");

                break;

            case 2:
                printf("\nO filme não foi encontrado;\n");
                printf("\nDeseja tentar novamente?\n1 - Sim;\n2 - Não;\n");
                scanf("%d", &aux);
                aux2 = NULL;
                aux3 = 1;

                break;

            default:
                break;
            }
        }
    }
    return aux;
}