#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) // Função main com 2 argumentos
{
    if (argc != 2)
    {
        printf("Usage: ./ceasar k");
        return 1;
    }
    for (int key = 0; key < strlen(argv[1]); key++)  // Checando 1 argumento e loop
    {
        if (isalpha(argv[1][key]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]) % 26; // convertendo
    string plaintext = get_string("plaintext: ");// texto a ser traduzido

    printf("ciphertext: ");

    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
        int offset = isupper(plaintext[i]) ? 65 : 97;// Checar as letras maiusculas
        int pi = plaintext[i] - offset;
        int ci = (pi + key) % 26;// Indexando a letra cifra
        printf("%c", ci + offset);
    }
    printf("\n");
    return 0;
}