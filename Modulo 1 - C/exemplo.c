#include <stdio.h>
#include <stdlib.h>
#define MAXLETRAS 10
typedef struct {
    char nome[MAXLETRAS];
    float nota[4];
}Dados;

int main (){
    int i,j;
    Dados lista[3] ={
        {{"Lucas"  }, {10  , 9.5, 7.4, 8.9} },
        {{"Leandro"}, { 9  , 9.5, 7.8, 8.7} },
        {{"José"   }, { 8.5, 9.2, 7.9, 8.8} }
    };
    printf("%*s%8s%8s%8s%8s\n", -MAXLETRAS, "Aluno", "Nota1", "Nota2", "Nota3", "Média");
    // printf("%*s\n", MAXLETRAS,"Hola mundo");
    for (i=0;i<3;i++) {
        printf("%*s", -MAXLETRAS, lista[i].nome);
        for (j=0;j<4;j++) {
            printf("%8.1f", lista[i].nota[j]);
        }
        printf("\n");
   }

    getchar();
    return 0;
}