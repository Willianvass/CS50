#include <stdio.h>
#include <ctype.h> //Biblioteca de maiuscula e minuscula
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        {
        printf("%c", toupper(s[i]));
        /*if (islower(s[i]))
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);*/
        }
        /*if (s[i] >= 'a' && s[i] <= 'z')
        {
        printf("%c", s[i] - 32); // codigo sem a biblioteca
        }
        else
        {
         printf("%c", s[i]);*/
    }
    printf("\n");
}


