#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};//Se souber os numeros não precisa colocar o tamanhos nos colchetes da array

    for (int i = 0; i < 7; i++)//Looping padrão
    {
        if (numbers[i] == 0)//Se o numero de [i] for igual a zero
        {
            printf("Se tiver\n");
            return 0;//Retorna 0 se tiver tudo OK
        }
    }
    printf("Não tem nada\n");
    return 1;//Retorna 1 se não tiver OK
}


