#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Pontuação fornecida cada letra do alfabeto
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Codigo de cada letra no alfabeto maiuscula
int small_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// Codigo de cada letra no alfabeto minuscula
int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int temp_Points [] = {};

int compute_score(string word);

int main(void)
{
    // Input dos 2 jogadores
    string word1 = get_string("Jogador 1: ");
    string word2 = get_string("Jogador 2: ");

    // Para calcular as 2 palavras
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the o vencedor
    if (score1 > score2)
    {
        printf("Jogador 1 Venceu!!!");
    }
    else if (score2 > score1)
    {
        printf("Jogador 2 Venceu!!!");
    }
    else
    {
        printf("Empate");
    }
}

int compute_score(string word)
{
    int score = 0;
    //CPU devolve resultado da string
    for (int i = 0; i < strlen(word); i++)
    {
        // Checar as letras maiusculas
        if (isupper(word[i]))
        {
            // Calculando cada valor de cada letra
            for (int f = 0; f < sizeof(capital_letters); f++)
            {
                if (word[i] == capital_letters[f])
                {
                    temp_Points[i] = POINTS[f];
                    score += temp_Points[i];
                }
            }
        }
        else if (islower(word[i]))
        {
            // Adicionando os valores no score
            for (int f = 0; f < sizeof(small_letters); f++)
            {
                if (word[i] == small_letters[f])
                {
                    temp_Points[i] = POINTS[f];
                    score += temp_Points[i];
                }
            }
        }
        else
        {
            i += 1;
        }
    }
    return score;
}
