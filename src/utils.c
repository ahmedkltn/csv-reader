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
char *join_line(char **line, const char delimiter, const long count)
{
    // Calculate total length needed
    long total_length = 0;
    for (int i = 0; i < count; i++)
    {
        if (strlen(line[i]) > 0) // Skip empty strings
        {
            total_length += strlen(line[i]);
            total_length++; // For the delimiter
        }
    }

    // Remove the extra delimiter for the last element
    total_length--;

    // Allocate memory for the joined string
    char *s = (char *)malloc((total_length + 1) * sizeof(char));
    if (s == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    int c = 0;
    for (int i = 0; i < count; i++)
    {
        if (strlen(line[i]) > 0) // Skip empty strings
        {
            int n = strlen(line[i]);
            // Add char by char to s variable
            for (int j = 0; j < n; j++)
            {
                s[c++] = line[i][j];
            }
            // Add delimiter at the end if it's not the last element
            if (i != count - 1)
            {
                s[c++] = delimiter;
            }
        }
    }

    if (c > 0 && s[c - 1] == delimiter) // Remove  delimiter
    {
        c--;
    }

    s[c] = '\0'; // Null-terminate the string

    return s;
}