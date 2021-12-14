#include<stdio.h>
#include<cs50.h>

int get_posInt(void);
void piramide(int param);

int main()
{
    int n = get_posInt();
    piramide(n);
    return 0;
}

    int get_posInt(void){int posInt = -9;
    do
    {
        printf("Qual a altura: ");
        posInt = get_int(" ");

    }while( (posInt < 0) || (posInt >= 24) );
    return posInt;
}

void piramide(int h)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = h; j > i+1; j--)
        {
            printf(" ");
        }
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");

        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}