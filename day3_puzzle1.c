#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 32

long long getListLength(char *filepath);

char **createList(long long length, char *filepath);

long long decode(long long length, char **list);

int main()
{
    char filepath[] = "./input.txt";
    long long list_length = getListLength(filepath);
    char **list = createList(list_length, filepath);
    printf("%lld\n", decode(list_length, list));
    /*for (int i = 0; i < list_length; i++)
        printf("%s\n",list[i]);*/
    return 0;
}

long long getListLength(char *filepath)
{
    long long length = 0;
    FILE *fptr = fopen(filepath, "r");
    if (fptr != NULL)
    {
        char line [LINE];
        while(fgets(line,sizeof(line),fptr) != NULL)
        {
            length++;
        }
        fclose(fptr);
    }
    else
    {
        perror(filepath);
    }
    return length;
}

char **createList(long long length, char *filepath)
{
    char **list = (char **)malloc(length * sizeof(char *));
    FILE *fptr = fopen(filepath, "r");
    int i, j;

    fptr = fopen(filepath, "r");

    if (fptr != NULL)
    {
        char line [LINE];
        for (i = 0; i < length; i++)
        {
            fgets(line,sizeof(line),fptr);
            list[i] = (char *)malloc(10 * sizeof(char));
            for (j = 0; line[j] != '\n'; j++)
            {
                list[i][j] = line[j];
            }
            list[i][j] = '\0';
        }
        fclose(fptr);
    }
    else
    {
        perror(filepath);
    }
    return list;
}

long long decode(long long length, char **list)
{
    int hash[LINE] = {0};

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; list[i][j] != '\0'; j++)
        {
            if (list[i][j] == '1')
                hash[j]++;
            else
                hash[j]--;
        }
    }

    long long gamma = 0;
    long long epsilon = 0;
    for (int i = 0; i < LINE; i++)
    {
        if (hash[i] > 0)
        {
            gamma = gamma * 2 + 1;
            epsilon *= 2;
        }
        else if (hash[i] < 0)
        {
            gamma *= 2;
            epsilon = epsilon * 2 + 1;
        }
    }
    return gamma * epsilon;
}


