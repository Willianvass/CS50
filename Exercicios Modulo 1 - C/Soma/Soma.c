#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    int num1, num2, num3, soma;
    setlocale(LC_ALL, "");

    printf("Primeiro numero: \n");
    scanf("%d", &num1);
    printf("Segundo numero: \n");
    scanf("%d", &num2);
    printf("Terceiro numero: \n");
    scanf("%d", &num3);

    soma = num1 + num2 + num3;

    printf("O total da soma de %d + %d + %d é igual = %d", num1, num2, num3, soma);
    system ("pause");
    return 0;
}
