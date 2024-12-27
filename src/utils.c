#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
char **split_line(const char *line, char delimiter, int *count)
{
    if (line == NULL)
    {
        return NULL;
    }

    int part_alloc = 10;
    char **splittedLine = malloc(part_alloc * sizeof(char *));

    size_t length = strlen(line);
    char *part = (char *)malloc((length + 1) * sizeof(char));

    int j = 0;
    *count = 0;
    for (int i = 0; i <= length + 1; i++)
    {
        // if we reached delimiter
        if (line[i] == delimiter || line[i] == '\0')
        {
            part[j] = '\0';
            splittedLine[*count] = strdup(part);
            (*count)++;

            if (*count >= part_alloc)
            {
                part_alloc *= 2;
                splittedLine = realloc(splittedLine, part_alloc * sizeof(char *));
            }

            free(part);
            part = (char *)malloc((length + 1) * sizeof(char));
            j = 0;
            continue;
        }

        part[j] = line[i];
        j++;
    }
    return splittedLine;
}
