#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9 // Maximo numero de candidatos

int preferences[MAX][MAX];// Matriz [i][j] numero de votos e preferencias i e j

bool locked[MAX][MAX];// Travar [i][j] travar i e j
bool lock = true;

typedef struct// Vencedor e Perdedor
{
    int winner;
    int loser;
}
pair;

string candidates[MAX];// Array ou Vetor dos candidatos
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Funções que usarei
void validateLock(int j);
int comparator(const void *a, const void *b);
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)// Checar usuario Inválido
    {
        printf("Usando: tideman [candidato ...]\n");
        return 1;
    }
    candidate_count = argc - 1;// Array dos candidatos
    if (candidate_count > MAX)
    {
        printf("Numero máximo dos candidatos é %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }
    pair_count = 0;
    int voter_count = get_int("Numero de eleitores: ");

    for (int i = 0; i < voter_count; i++)// Inserção de votos
    {
        int ranks[candidate_count];// rank[i] dos eleitores

        for (int j = 0; j < candidate_count; j++) // Inserção do rank
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Voto inválido!!.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

bool vote(int rank, string name, int ranks[])// Subindo novo voto no rank
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name,  candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[])// Subindo os votos dos eleitores
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_pairs(void)// Gravando os pares de candidatos
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

int comparator(const void *a, const void *b)// Função de sorteio
{
    pair *orderA = (pair *)a;
    pair *orderB = (pair *)b;

    return (preferences[orderB->winner][orderB->loser] - preferences[orderA->winner][orderA->loser]);
}

void sort_pairs(void)// Apurando os pares pra ver quem venceu
{
    qsort(pairs, pair_count, sizeof(pair), comparator);
}

void validateLock(int j)
{
    if (j == 0)
    {
        return;
    }

    int r = 0;
    bool rank[j];
    for (int i = 0; i < j; i++)
    {
        rank[i] = false;
    }

    validateLock(j - 1);// checando as submatrizes

    for (int i = 0; i < j; i++)
    {
        for (int k = 0; k < j; k++)
        {
            if (locked[i][k] == true)
            {
                rank[i] = true;
            }
        }
    }

    for (int i = 0; i < j; i++)
    {
        if (rank[i] == true)
        {
            r++;
        }
    }

    if (r == j)
    {
        lock = false;
    }
}

void lock_pairs(void)// Fechando os candidatos para criação dos ciclos
{
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;

        validateLock(candidate_count);

        if (!lock)
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
        lock = true;
    }
}

void print_winner(void)// Mostrar o vencedor da eleição
{
    int winner;
    int rank;

    for (int i = 0; i < candidate_count; i++)
    {
        rank = 0;
        for (int k = 0; k < candidate_count; k++)
        {
            if (locked[k][i] == false)
            {
                rank++;
            }
        }

        if (rank == candidate_count)// Mostrar todos nomes
        {
            printf("%s\n", candidates[i]);
        }
    }
}