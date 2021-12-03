#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item
{
    char *direction;
    int value;
};

long long getListLength(char *filepath);

struct item *createStructList(long long length, char *filepath);

long long depth_times_horizontal_distance(long long length, struct item *structList);

int main()
{
    char filepath[] = "./input.txt";
    long long structListLength = getListLength(filepath);
    struct item *structList = createStructList(structListLength, filepath);
    long long result = depth_times_horizontal_distance(structListLength, structList);
    printf("%lld", result);
    /*for (int i = 0; i < structListLength; i++)
        printf("%s %d\n",structList[i].direction, structList[i].value);*/
    return 0;
}

long long getListLength(char *filepath)
{
    long long length = 0;
    FILE *fptr = fopen(filepath, "r");
    if (fptr != NULL)
    {
        char line [1000];
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

struct item *createStructList(long long length, char *filepath)
{
    struct item *dict = (struct item *)malloc(length * sizeof(struct item));
    FILE *fptr = fopen(filepath, "r");

    fptr = fopen(filepath, "r");
    if (fptr != NULL)
    {
        char line [1000];
        for (int i = 0; i < length; i++)
        {
            fgets(line,sizeof(line),fptr);
            dict[i].direction = (char *)malloc(10 * sizeof(char));
            int j;
            for (j = 0; line[j] != ' '; j++)
            {
                dict[i].direction[j] = line[j];
            }
            dict[i].direction[j] = '\0';
            dict[i].value = line[++j] - 48;
        }
        fclose(fptr);
    }
    else
    {
        perror(filepath);
    }
    return dict;
}

long long depth_times_horizontal_distance(long long length, struct item *structList)
{
    long long depth = 0, distance = 0, aim = 0;
    for (int i = 0; i < length; i++)
    {
        if (strcmp(structList[i].direction, "forward" ) == 0)
        {
            distance += structList[i].value;
            depth += aim * structList[i].value;
        }
        else if (strcmp(structList[i].direction, "up") == 0)
        {
            //depth -= structList[i].value;
            aim -= structList[i].value;
        }
        else if (strcmp(structList[i].direction, "down") == 0)
        {
            //depth += structList[i].value;
            aim += structList[i].value;
        }
    }
    return depth * distance;
}


