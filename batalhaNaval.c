#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tabuleiro[10][10];
    int efeito[10][10]; // marca onde a habilidade atingiu

    int i, j;

    // Inicializa tudo com 0
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // água
            efeito[i][j] = 0;    // sem efeito ainda
        }
    }

    // Coloca navios com valor 3
    tabuleiro[3][1] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[3][3] = 3;

    tabuleiro[3][7] = 3;
    tabuleiro[4][7] = 3;
    tabuleiro[5][7] = 3;

    // Matriz da habilidade em cruz
    int cruz[5][5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Matriz do cone (tipo pirâmide pra baixo)
    int cone[5][5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if ((i == 0 && j == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 2 && j >= 0 && j <= 4))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Matriz do octaedro (losango)
    int octaedro[5][5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Aplica habilidade cone no (2,2)
    int origemLinha = 2;
    int origemColuna = 2;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int linha = origemLinha + i - 2;
            int coluna = origemColuna + j - 2;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
            {
                if (cone[i][j] == 1)
                {
                    efeito[linha][coluna] = 1;
                }
            }
        }
    }

    // Aplica cruz no (5,5)
    origemLinha = 5;
    origemColuna = 5;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int linha = origemLinha + i - 2;
            int coluna = origemColuna + j - 2;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
            {
                if (cruz[i][j] == 1)
                {
                    efeito[linha][coluna] = 1;
                }
            }
        }
    }

    // Aplica octaedro no (7,7)
    origemLinha = 7;
    origemColuna = 7;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int linha = origemLinha + i - 2;
            int coluna = origemColuna + j - 2;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
            {
                if (octaedro[i][j] == 1)
                {
                    efeito[linha][coluna] = 1;
                }
            }
        }
    }

    // Mostrar o tabuleiro
    printf("Tabuleiro final:\n\n");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {

            if (tabuleiro[i][j] == 3 && efeito[i][j] == 1)
            {
                printf("5 "); // navio atingido
            }
            else if (tabuleiro[i][j] == 3)
            {
                printf("3 "); // navio normal
            }
            else if (efeito[i][j] == 1)
            {
                printf("* "); // área da habilidade
            }
            else
            {
                printf("0 "); // água
            }
        }
        printf("\n");
    }

    return 0;
}
