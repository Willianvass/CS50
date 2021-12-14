#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);//Primeiro erro a declaração precisa estar acima

int main(void)
{
    int i = get_negative_int();
    printf("%i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negative Inteiro: ");
    }
    while (n >= 0);//para negativo
    return n;
}
//debug50 nome - para depurar arquivos colocar ponto de parada e inicio