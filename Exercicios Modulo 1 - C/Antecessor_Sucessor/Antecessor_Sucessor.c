#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    int num1, antecessor, sucessor;
    printf("Qual o numero: ");
    scanf("%d", &num1);
    antecessor = num1 - 1;
    sucessor = num1 + 1;
    printf("Antecessor � %d e Sucessor � %d", antecessor, sucessor);
    return 0;
}
