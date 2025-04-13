#include <stdio.h>

int main()
{
    int tabuleiro[10][10];
    int navio1[3] = {3, 3, 3}, navio2[3] = {3, 3, 3};

    for (int linha = 0; linha < 10; linha++) //percorre linhas e colunas atribuindo o valor 0
    {
        for (int coluna = 0; coluna < 10; coluna++)
        {
            tabuleiro[linha][coluna] = 0;
        }
    }

    if (tabuleiro[3][1] == 0 && tabuleiro[3][2] == 0 && tabuleiro[3][3] == 0) // validação horizontal das posições para não adicionar o navio em algum local que já tenha outro navio
    {
        tabuleiro[3][1] = navio1[0];
        tabuleiro[3][2] = navio1[1];
        tabuleiro[3][3] = navio1[2];
    }

    if (tabuleiro[2][7] == 0 && tabuleiro[3][7] == 0 && tabuleiro[4][7] == 0)// validação vertical das posições para não adicionar o navio em algum local que já tenha outro navio
    {
        tabuleiro[2][7] = navio2[0];
        tabuleiro[3][7] = navio2[1];
        tabuleiro[4][7] = navio2[2];
    }

    printf("   A B C D E F G H I J\n"); // exibição do tabuleiro e as posições dos navios

    for (int linha = 0; linha < 10; linha++)
    {
        printf("%i  ", linha + 1);
        for (int coluna = 0; coluna < 10; coluna++)
        {
            printf("%i ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
