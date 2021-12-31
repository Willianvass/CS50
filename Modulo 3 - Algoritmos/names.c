#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //Sabemos o conteudo da Array de antemão
    string nomes[] = {"Maria", "João", "Ana", "Lucas", "Leo", "Tito", "Beto"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(nomes[i], "Leo") == 0)//strcmp compara strings e retorna 3 valores possiveis
        {
            printf("Localizado\n");
            return 0;
        }
    }
    printf("Não localizado\n");
    return 1;
}




