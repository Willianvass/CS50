#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string ("s: ");
    char *t = get_string ("t: ");

    if (strcmp(s, t) == 0)//Comparando Strings não pelo endereço, usando a biblioteca
    {
        printf("Iguais!!!\n");
    }
    else
    {
        printf("Diferentes!!\n");
    }
}





