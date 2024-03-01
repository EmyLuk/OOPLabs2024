#include <stdio.h>

struct Word {
    int size;
    char word[100];
};

int main()
{
    char a[100];
    scanf("%[^\n]a", a);
    char prop[100][100];

    Word cuvant[100];
    int c = 0;
    int aux = 0; 
    int aux_cuv = 0;
    while (1)
    {
        if (a[c] != ' ' && a[c])
        {
            aux++;
        }
        else {
            cuvant[aux_cuv].size = aux;
            aux = 0;
            for (int j = 0; j < cuvant[aux_cuv].size; j++) {
                cuvant[aux_cuv].word[j] = a[c - cuvant[aux_cuv].size + j];
            }
            aux_cuv++;
            if (a[c] == '\0')
                break;
        }
        c++;
    }

    for (int j = 0; j < aux_cuv; j++) {
        printf("%a ", cuvant[j].word);
    }


    return 0;
}