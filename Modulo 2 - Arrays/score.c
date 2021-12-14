#include <stdio.h>
#include <cs50.h>

const int TOTAL = 3;//Const valor se mante continuo; TOTAL para diferenciar em maisusculo

int main(void)
{
    int scores[TOTAL];//Lista de variaveis e sua quantidade interna
    for (int i = 0; i < TOTAL; i++)// Loop de contagem
   {
       scores[i] = get_int("Score: ");
   }
       printf("Average: %f\n", average(TOTAL, scores);
}

float average(int length, int array[])//length é o tamanho; Colchete vazio colcoar uma função
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum = sum + array[i];
    }
    return sum / (float) length;
}


