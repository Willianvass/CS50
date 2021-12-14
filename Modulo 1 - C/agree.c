#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Você concorda? ");
    if (c == 's' || c == 'S') /*Aspas simples para 1 caractere*/
    {
        printf("Concordo!\n");
    }
    else if (c == 'n' || c == 'N')/* Pipes para dizer que a esquerda é igual a direita*/
    {
        printf("Não concordo!\n");
    }
}