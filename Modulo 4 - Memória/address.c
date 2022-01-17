#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;//Criou uma espaço na memoria e colocou n
    //Colocando o * vai para o local da memoria
    printf("%i\n", *p);//Pegue o valor do endereço p
    //%P significa valor diferente - & o local da memoria onde esta o valor
    /*printf("%i\n", n);*/
}






