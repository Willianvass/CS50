#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int x = get_int("x: ");

    int y = get_float("y: ");

    float z = (float)x / (float)y;/*Forçar as variaveis de resposta para float*/

    printf("%f\n", z);
}