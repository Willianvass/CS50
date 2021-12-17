#include <cs50.h>
#include <stdio.h>

int main(argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing comand line\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}// Se digitar no terminal echo $? verei o codigo de erro