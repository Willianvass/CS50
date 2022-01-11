#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9// Numero maximo de candidatos

typedef struct// Nome dos candidatos para o contador
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

int candidate_count;// Quantidade de candidatos

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usando a eleição por plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("A quantidade de candidatos é %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Quantidade de votos: ");

    for (int i = 0; i < voter_count; i++)// Loop para os votos
    {
        string name = get_string("Voto: ");

        if (!vote(name))
        {
            printf("Voto inválido!.\n");
        }
    }

    print_winner();// Mostrando o vencedor
}

bool vote(string name)//Calculando os votos
{

    int voteCount = 0;

    bool result = false;

    for (int i = 0; i < candidate_count; i++)
    {
        if (strlen(name) == 0)// Voto em branco
        {
            result = false;
            return result;
        }
        if (strcmp(name, candidates[i].name) == 0 && voteCount <= candidate_count)
        {
            candidates[i].votes += 1;
            voteCount += 1;
            result = true;
            return result;
        }
        else  // Retorno se for inválido
        {
            result = false;
        }
    }
    return result;
}

void print_winner(void)//Vencedor
{

    int highVoteCount = 0;

    for (int i = 0; i < MAX; i++)// Mais votado
    {
        if (candidates[i].votes > highVoteCount)
        {
            highVoteCount = candidates[i].votes;
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (candidates[i].name != 0  && candidates[i].votes != 0 && candidates[i].votes >= highVoteCount)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}