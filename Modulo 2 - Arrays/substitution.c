#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h> // Para String maiscula e minuscula

int checkKey(); // Validação da Key
void Do_substitute(); // Mudar no futuro
void alpha_arr_val(char pos, string key);
// Para alterar o texto futuro (ex:plaintext = h|alphabet array = 8 {a=0, b=1 .....z=26})

int main(int argc, string argv[])
{
    if (argc == 2) // Numero de comandos
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < strlen(argv[1]) ; i++) // Checar cada elmento da String e retornar
            {

                if (! isalpha(argv[1][i])) // Eliminando os caracteres
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }

                for (int j = i + 1 ; j < strlen(argv[1]) ; j++)
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }

            Do_substitute(argv[1]);

        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}


void Do_substitute(string key)
{
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(p); i++)
    {
        if (isalpha(p[i])) // Checar p[i] se é alfabeto
        {
            char x = p[i];
            if (islower(p[i]))
            {
                alpha_arr_val(tolower(x), key); // Minuscula
            }
            else
            {
                alpha_arr_val(toupper(x), key); // Maiuscula
            }
        }
        else
        {
            printf("%c", p[i]);
        }
    }

    printf("\n");

}
void alpha_arr_val(char pos, string key)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Alfabeto Array

    for (int i = 0; i < strlen(alpha); i++) // Acessando cada elemento do array
    {
        if (islower(pos)) // Minusculo
        {
            if (pos == tolower(alpha[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else // Quando for maisuculo
        {
            if (pos == toupper(alpha[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}