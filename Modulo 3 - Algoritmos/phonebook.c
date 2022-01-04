#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct

{
     string name;
     string number;
}
person;

const int NUMBER = 10;

int main(void)
{
     person people[NUMBER];

    for (int i = 0; i < NUMBER; i++)
    {
        people[i].name = get_string("Qual seu nome: ");
        people[i].number = get_string("Qual seu fone: ");
    }
     for (int i = 0; i < 2; i++)
     {
         if (strcmp(people[i].name, "David") == 0)
         {
              printf("Encontrado %s\n", people[i].number); return 0;
         }
     }
     printf("Não encontrado\n");
     return 1;
}