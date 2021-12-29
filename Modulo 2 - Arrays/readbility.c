#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Texto : ");//Usuario coloca texto

    int letras = 0; //Contar letras maiuscula e minuscula
    int palavras = 1; //Contar palavras
    int frases = 0; //Contar frases
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))//Eliminando caracteres
        {
            letras++;
        }
        if (s[i] == ' ')
        {
            palavras++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            frases++;
        }
    }
    float grade = 0.0588 * (100 * (float)letras / (float)palavras) - 0.296 * (100 * (float)frases / (float)palavras) - 15.8;

    if (grade < 1)
    {
        printf("Grade 1\n");//Facil
    }
    else if (grade >= 16)//Entre 1 e 16
    {
        printf("Grade 16+\n");//Dificil 16 mais
    }
    else
    {
        printf("Grade %.f\n", grade);//.f arrendondar o resultado
    }
}

