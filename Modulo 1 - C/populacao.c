#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int start_size;
    do
    {
        start_size = get_int("População inicial: ");
    }
    while (start_size < 9);

    int end_size;
    do
    {
        end_size = get_int("População final: ");
    }
    while (end_size < start_size);

    int year = 0; // Calcular o crescimento
    int n = start_size;
    int calculator = 0;

    if (start_size == end_size)
    {
        printf("Anos: 0");
    }

    do
    {
        n = round(n + (n / 3) - (n / 4));
        year += 1;
    }
    while (n < end_size);
    printf("Anos para atingir a população final: %i\n",  year);

}