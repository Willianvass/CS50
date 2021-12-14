#include <stdio.h>
#include <cs50.h>
#include <math.h> //Biblioteca matematica
// q -25c, d -10c, n-5c, p -1c

int main(void)
{

    float change; //Informando que sera Float
    do //DO para fazer as entradas positivas
    {
        change = get_float("Qual o valor que vai pagar: ");
    }
    while (change < 0); //Condição positiva


    int convertCents = round(change * 100); //Converte para centavos de dolar
    int coins = 0; //Valor inicial

    while (convertCents >= 25) //Loop 0,25
    {
        convertCents = convertCents - 25;
        coins++;
    }
    while (convertCents >= 10) //Loop 0,10
    {
        convertCents = convertCents - 10;
        coins++;
    }
    while (convertCents >= 5) //Loop 0,05
    {
        convertCents = convertCents - 5;
        coins++;
    }
    while (convertCents >= 1 && convertCents > 0) //Loop 0,01
    {
        convertCents = convertCents - 1;
        coins++;
    }

    printf("Moedas %d\n", coins);

}

